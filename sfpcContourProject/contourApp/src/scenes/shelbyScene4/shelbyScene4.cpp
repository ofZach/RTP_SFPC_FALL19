#include "shelbyScene4.h"

//---------------------------------------------------------------
void shelbyScene4::setup(){
}


//---------------------------------------------------------------
void shelbyScene4::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void shelbyScene4::draw(){
    ofPolyline l;
    ofPolyline l2;

    for (int i = 0; i < CT->resampleSmoothed.size(); i += 1) {
        l.addVertex(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y);
        l2.addVertex(l[i].x, l[i].y, -300);

        ofPolyline connect;
        connect.addVertex(l[i]);
        connect.addVertex(l2[i]);
        connect.draw();
    }

    l.draw();
    l2.draw();
}
