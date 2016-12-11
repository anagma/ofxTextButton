/*
 *  ofxTextButton.h
 *  konnTimekeeper
 *
 *  Created by anagma on 13/03/30.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ofxTextButton_h
#define ofxTextButton_h

#include "ofxTextBase.h"
class ofxTextButton : public ofxTextBase{
public:
	ofEvent<string> clicked;

	void onMousePressed(ofMouseEventArgs &arg){
		bMouseClicked = bounds.inside(arg.x, arg.y);
		if (bMouseClicked) {
			ofNotifyEvent(clicked, text, this);
		}
	}
    void onMouseReleased(ofMouseEventArgs &arg){
        bMouseClicked = false;
    }
protected:
    bool bMouseClicked;
};

class ofxTextButtonSimple : public ofxTextButton{
public:
	void draw(){
		ofPushStyle();
        
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
        
        // draw outline when mouse hover
		if (isMouseHover()) {
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
		ofxTextButton::draw();
		ofPopStyle();
	}
};

#endif /* ofxTextButton_h */
