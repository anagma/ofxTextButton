/*
 *  ofxTextToggle.h
 *  konnTimekeeper
 *
 *  Created by anagma on 13/03/30.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ofxTextToggle_h
#define ofxTextToggle_h

#include "ofxTextBase.h"
class ofxTextToggle : public ofxTextBase{
public:
	ofEvent<bool> clicked;

	void onMousePressed(ofMouseEventArgs &arg){
		bMouseClicked = bounds.inside(arg.x, arg.y);
		if (bMouseClicked) {
			toggle();
		}
	}
    void onMouseReleased(ofMouseEventArgs &arg){
        bMouseClicked = false;
    }
	
	bool getState(){
		return bOn;
	}
	void setState(bool val, bool notify=true){
		bOn = val;
		if (notify) {
			ofNotifyEvent(clicked, bOn, this);
		}
	}
	bool toggle(){
		setState(!bOn);
		return bOn;
	}
protected:
    bool bMouseClicked;
    bool bOn;
};

class ofxTextToggleSimple : public ofxTextToggle{
public:
	void draw(){
		ofPushStyle();
		if(getState()){ // is ON ====================
            
            // draw button
			ofFill();
			ofSetColor(230);
			ofDrawRectangle(bounds);
			
			if (isMouseHover()) {
                // draw outline
				ofSetColor(255);
				ofNoFill();
				ofDrawRectangle(bounds);
			}
            
            // draw text
			ofSetColor(0);
			ofxTextToggle::draw();

        }else{ // is OFF ====================
            
            // draw button
			if (bMouseClicked) {
				ofSetColor(255);
			}else if (bEnabled) {
				ofSetColor(128);
			}else{
				ofSetColor(32);
			}
			ofFill();
			ofDrawRectangle(bounds);
            
			if (isMouseHover()) {
                // draw outline
				ofSetColor(255);
				ofNoFill();
				ofDrawRectangle(bounds);
			}

            // draw text
            if (bMouseClicked) {
				ofSetColor(0);
			}else if (bEnabled) {
				ofSetColor(255);
			}else {
				ofSetColor(128);
			}
			ofxTextToggle::draw();
		}
		ofPopStyle();
	}
};

#endif /* ofxTextToggle_h */
