/*
 *  ofxTextBase.h
 *  konnTimekeeper
 *
 *  Created by anagma on 13/03/30.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ofxTextBase_h
#define ofxTextBase_h

#include "ofMain.h"

class ofxTextBase{
    
public:
	
    ofxTextBase();
    ~ofxTextBase();
	
    void setup(string text_);
    void draw();
	
    void enable();
    void disable();
    bool isEnabled();
	
    void onMouseMoved(ofMouseEventArgs &arg);
    virtual void onMousePressed(ofMouseEventArgs &arg) = 0;
    virtual void onMouseReleased(ofMouseEventArgs &arg) = 0;
    
    // -----------------------------------
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setSizeAuto(bool bAuto);
    
protected:
    string text;
    ofRectangle bounds;
    bool bMouseHover;
    bool bEnabled;
    bool bSizeAuto;
    
    float paddingX, paddingY;
    
    void registerEvents();
    void unregisterEvents();

    void calcSizeAuto();
    bool isMouseHover();
    
};

#endif /* ofxTextBase_h */
