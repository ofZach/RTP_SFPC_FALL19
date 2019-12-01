

#include "inputManager.h"

//---------------------------------------------------------------
void inputManager::setup(){
    
    group.setName("settings");
    group.add(threshold.set("threshold", 100, 0, 255));
    group.add(speed.set("speed", 1, 0,2));
    group.add(medianFilterAmount.set("medianFilterAmount", 5, 0, 30));
    
#ifndef USE_VIDEO
    
    group.add(learnBG.set ("learnBG", false));
    group.add(threshold2.set("threshold2", 200, 0, 255));
    group.add(bUseBothThresholds.set("bUseBothThresholds",false));
    group.add(distanceFromBg.set("distanceFromBg",10, 0, 255));
    
#endif
    
    group.add(minBlobSize.set("minBlobSize", 100, 0, 10000));
    
    panel.setup("cv", "cvSettings2.xml");
    panel.add(group);
    panel.loadFromFile("cvSettings2.xml");
    
#ifdef USE_VIDEO
    player.load("videos/input.mov");
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
#else
    
    maxDepthLearned.allocate(INPUT_W, INPUT_H, OF_IMAGE_GRAYSCALE);
    for (int i = 0; i < INPUT_W*INPUT_H; i++){
        maxDepthLearned.getPixels()[i] = 0;
    }
    maxDepthLearned.update();
    
//    kinect.init();
//    kinect.open();
    
    ofxKinectV2 tmp;
    vector <ofxKinectV2::KinectDeviceInfo> deviceList = tmp.getDeviceList();
    
    cout << deviceList.size() << endl;
    
    kinect = shared_ptr <ofxKinectV2> (new ofxKinectV2());
    kinect->open(deviceList[0].serial);
    //panel.add(kinect->params);
    //panel.add(kinect.params);
    
    kinect->maxDistance = 3200;
    kinect->minDistance = 50;
    
    maxDepthLearned.load("bg.png");
    
#endif
    
    graypixels = new unsigned char[INPUT_W*INPUT_H];
    medianFiltered = new unsigned char[INPUT_W*INPUT_H];
    medianFilteredResult.allocate(INPUT_W, INPUT_H, OF_IMAGE_GRAYSCALE);
    
    //panel.loadFromFile("settings.xml");
    
    
}

void inputManager::changeMovie( string fileName){
#ifdef USE_VIDEO
    player.stop();
    player.load(fileName);
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
#endif
}


//---------------------------------------------------------------
void inputManager::update(){
    
    
#ifndef USE_VIDEO
    if (learnBG){
        
        learn();
        
        learnBG = false;
        
    }
#endif
    
    
    //cout << player.getWidth() << " " << player.getHeight() << endl;
#ifdef USE_VIDEO
    player.update();
    player.setVolume(0);
    player.setSpeed(speed);
    
    bIsFrameNew = player.isFrameNew();
    
    
    if (player.isFrameNew() == true){
        
        unsigned char * data  = player.getPixels().getData();
        for (int i = 0; i < INPUT_W*INPUT_H; i++){
            graypixels[i] = data[i*3];
        }
        
        
        ctmf(graypixels, medianFiltered,
             INPUT_W, INPUT_H, INPUT_W, INPUT_W,medianFilterAmount, 1);
        
        
        
        medianFilteredResult.setFromPixels(medianFiltered, INPUT_W, INPUT_H, OF_IMAGE_GRAYSCALE);
        
        
        
        finder.setSortBySize(true);
        
        finder.setThreshold(threshold);
        
        finder.findContours(medianFilteredResult);
    }
#else
//    kinect.update();
//    if( kinect.isFrameNew() ){
//
//
//        cout << kinect.getDepthPixels().getWidth() << " " << kinect.getDepthPixels().getHeight() << endl;
//
//        texDepth.loadData( kinect.getDepthPixels() );
//        //texRGB.loadData( kinect.getRgbPixels() );
//
//        unsigned char * data  = kinect.getDepthPixels().getData();
//
//
//        // todo is this OK ???
//        for (int i = 0; i < INPUT_W*INPUT_H; i++){
//            graypixels[i] = data[i];
//        }
//
//        // todo move this to kinect.
//        ctmf(graypixels, medianFiltered,
//             INPUT_W, INPUT_H, INPUT_W, INPUT_W,medianFilterAmount, 1);
//
//        medianFilteredResult.setFromPixels(medianFiltered, INPUT_W, INPUT_H, OF_IMAGE_GRAYSCALE);
//
//        finder.setSortBySize(true);
//        finder.setThreshold(threshold);
//
//        finder.findContours(medianFilteredResult);
//
//    }
    
    kinect->update();

    bIsFrameNew = false;
    
    if( kinect->isFrameNew()  ){
        
        bIsFrameNew = true;
        texDepth.loadData( kinect->getDepthPixels() );
        
        if (bLearningBg == true){
            
            unsigned char * toCheck = (unsigned char *)kinect->getDepthPixels().getData();
            unsigned char * orig = (unsigned char *)maxDepthLearned.getPixels().getData();
            for (int i = 0; i < INPUT_H*INPUT_W; i++){
                orig[i] = MAX(orig[i], toCheck[i]);
            }
            maxDepthLearned.update();
            nFramesLearning++;
            if (nFramesLearning > 160){
                bLearningBg = false;
                
                maxDepthLearned.save("bg.png");
                
            }
            
        }
        
        //texRGB.loadData( kinect->getRgbPixels() );
        
        unsigned char * data  = (unsigned char *)kinect->getDepthPixels().getData();
        
        unsigned char * check  = maxDepthLearned.getPixels().getData();
        
        int distance = distanceFromBg;
        // todo is this OK ???
        for (int i = 0; i < 512*424; i++){
            
            if (data[i] < (check[i] + distance)){
                graypixels[i] = 0; //data[i];
            } else {
                graypixels[i] = data[i];
            }
            
            
        }
        
        // todo move this to kinect.
        ctmf(graypixels, medianFiltered,
             512, 424, 512, 512,medianFilterAmount, 1);
        
        for (int i = 0; i < INPUT_W; i++){
            for (int j = 0; j < INPUT_H; j++){
                if ( i > INPUT_W*0.9){
                    medianFiltered[j * INPUT_W + i] = 0;
                }
            }
        }
        
       
        
        if (bUseBothThresholds){
            
            int minV = min(threshold, threshold2);
            int maxV = max(threshold, threshold2);
            
            for (int i = 0; i < INPUT_W; i++){
                for (int j = 0; j < INPUT_H; j++){
                    if (medianFiltered[j * INPUT_W + i] >= minV &&
                        medianFiltered[j * INPUT_W + i] <= maxV){
                        medianFiltered[j * INPUT_W + i] = 255;
                    } else {
                        medianFiltered[j * INPUT_W + i] = 0;
                    }
                }
            }
            finder.setThreshold(127);
        } else {
            finder.setThreshold(threshold);
        }
        
        medianFilteredResult.setFromPixels(medianFiltered, 512, 424, OF_IMAGE_GRAYSCALE);
        
        //finder.setMinArea(minBlobSize);
        
        finder.setSortBySize(true);
        
        
        //finder.setThreshold(threshold);
        
        finder.findContours(medianFilteredResult);
        
    }
    
    
#endif
    
}


//---------------------------------------------------------------
void inputManager::draw(){
    
#ifdef USE_VIDEO
    player.draw(0,0);
    medianFilteredResult.draw(INPUT_W,0);
    if (finder.size() > 0){
        ofPushMatrix();
        ofTranslate(0,INPUT_H);
        finder.getPolyline(0).draw();
        ofPopMatrix();
        
    }
    //finder.draw();
#else
    texDepth.draw(0,0);
    medianFilteredResult.draw(INPUT_W,0);
    if (finder.size() > 0){
        ofPushMatrix();
        ofTranslate(0,INPUT_H);
        finder.getPolyline(0).draw();
        ofPopMatrix();
        cout << finder.getPolyline(0).getBoundingBox() << endl;
        
    }
    finder.draw();
    maxDepthLearned.draw(INPUT_W,INPUT_H);
    
    
#endif
    
    
    panel.draw();
}
