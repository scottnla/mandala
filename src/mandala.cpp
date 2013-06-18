#include "mandala.h"

//--------------------------------------------------------------
void mandala::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofSetFrameRate(30);
  width = ofGetWidth();
  height = ofGetHeight();
  //create mandala parameters
  ringRadius = 350;
  ring.num = int(ofRandom(6,12));
  ring.startAngle = 0;
  ring.beta = ofRandom(1.1,1.4);
  ring.eta = ofRandom(0.1, 0.9);
  ring.a = ofRandom(0.2, 0.35);
  ring.b = ofRandom(0.4, 0.6);
}

//--------------------------------------------------------------
void mandala::update(){
}

//--------------------------------------------------------------
void mandala::draw(){
  ofBackground(0,0,0);
  ofSetColor(255,255,255,32);
  ofFill();
  ofTranslate(width/2, height/2);
  for(int i = 0; i < ring.num; i++) {
    ofPushMatrix();
    ofRotateZ(ofRadToDeg(TWO_PI/ring.num*i + ring.startAngle));
    ofBeginShape();
    ofCurveVertex(0,0);
    ofCurveVertex(0,0);
    ofCurveVertex(ringRadius*ring.b, ringRadius*ring.a*(1+ring.eta));
    ofCurveVertex(ringRadius*ring.beta,0);
    ofCurveVertex(ringRadius*ring.b, ringRadius*ring.a*(1-ring.eta));
    ofCurveVertex(0,0);
    ofCurveVertex(0,0);
    ofEndShape();
    ofPopMatrix();

    ofPushMatrix();
    ofScale(-1,1);
    ofRotateZ(ofRadToDeg(TWO_PI/ring.num*i + ring.startAngle));
    ofBeginShape();
    ofCurveVertex(0,0);
    ofCurveVertex(0,0);
    ofCurveVertex(ringRadius*ring.b, ringRadius*ring.a*(1-ring.eta));
    ofCurveVertex(ringRadius*ring.beta,0);
    ofCurveVertex(ringRadius*ring.b, ringRadius*ring.a*(1+ring.eta));
    ofCurveVertex(0,0);
    ofCurveVertex(0,0);
    ofEndShape();
    ofPopMatrix();
  }
  ring.startAngle += 0.01;
}

//--------------------------------------------------------------
void mandala::keyPressed(int key){

}

//--------------------------------------------------------------
void mandala::keyReleased(int key){

}

//--------------------------------------------------------------
void mandala::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void mandala::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mandala::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mandala::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mandala::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mandala::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mandala::dragEvent(ofDragInfo dragInfo){ 

}
