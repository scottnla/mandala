#pragma once

#include "ofMain.h"

class mandala : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
		
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void createRing();
  void drawRing();
  void newMandala();

  float height, width;
  int numRings;
  int ringRadius;

  struct MandalaRing {
    int index;
    float startAngle;
    int polygonSides;
    int radius;
    int polygonRad;
    int itemsPerRing;
  };
  
  vector<MandalaRing> mandala;
};
