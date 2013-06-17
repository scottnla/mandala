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
  numRings = int(ofRandom(6,12));
  ringRadius = int(ofRandom(25, 75));
  for(int i = 0; i < numRings; i++) {
    MandalaRing ring;
    int numPolygons = int(ofRandom(6,12));
    int numSides = int(ofRandom(3,8));
    int polygonRadius = int(ofRandom(3,5))*10;
    ring.index = i;
    ring.startAngle = 0;
    ring.polygonSides = numSides;
    ring.radius = ringRadius;
    ring.polygonRad = polygonRadius;
    ring.itemsPerRing = numPolygons;
    mandala.push_back(ring);
    ringRadius *= ofRandom(1.2,1.5);
  }
}

//--------------------------------------------------------------
void mandala::update(){
}

//--------------------------------------------------------------
void mandala::draw(){
  ofBackground(0,0,0);
  ofSetColor(255,255,255,32);
  ofFill();
  for(int k = 0; k < numRings; k++) {
    int items = mandala[k].itemsPerRing;
    int ringRad = mandala[k].radius;
    int sides = mandala[k].polygonSides;
    int polyRad = mandala[k].polygonRad;
    for(int i = 0; i < items; i++) {
      ofPushMatrix();
      ofTranslate(width/2, height/2);
      ofRotateZ(ofRadToDeg(TWO_PI/items*i) + mandala[k].startAngle);
      ofPushMatrix();
      ofTranslate(0, ringRad);
      ofBeginShape();
      for(int j = 0; j < sides; j++) {
	ofVertex(polyRad*cos(TWO_PI/sides*j), polyRad*sin(TWO_PI/sides*j));
      }
      ofVertex(polyRad, 0);
      ofEndShape();
      ofPopMatrix();
      ofPopMatrix();
      mandala[k].startAngle += pow(-1, mandala[k].index)*0.1;
    }
  }
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

//--------------------------------------------------------------
void mandala::shape(int sides, int rep, int polyRad, int sidesPoly, int lvl){
  if(lvl > 0 || polyRad > width * 0.48) {
    for(int i = 0; i < sidesPoly; i++) {
      ofPushMatrix();
      ofTranslate(width/2, height/2);
      ofRotateZ(ofRadToDeg(TWO_PI/sidesPoly*i));
      ofPushMatrix();
      ofTranslate(0, rep);
      ofBeginShape();
      for(int j = 0; j < sides; j++) {
	ofVertex(polyRad*cos(TWO_PI/sides*j), polyRad*sin(TWO_PI/sides*j));
      }
      ofVertex(polyRad, 0);
      ofEndShape();
      ofPopMatrix();
      ofPopMatrix();
    }
    rep *= ofRandom(1.0, 3.0);
    polyRad *= ofRandom(0.5, 1.5);
    sidesPoly *= ofRandom(0.8, 1.2);
    lvl--;
    shape(sides, rep, polyRad, sidesPoly, lvl);
  }
}
