//
//  ofxTextBase.cpp
//  gaplessLoopPlayer
//
//  Created by FURUDATE Ken on 2016/12/11.
//
//

#include "ofxTextBase.h"

ofxTextBase::ofxTextBase(){
    text ="";
    bounds.set(0, 0, 100, 15);
    paddingX = 10;
    paddingY = 0;
    bMouseHover = bEnabled = false;
    bSizeAuto = true;
}
ofxTextBase::~ofxTextBase(){
    disable();
}

void ofxTextBase::setup(string text_){
    text = text_;
    calcSizeAuto();
    enable();
}
void ofxTextBase::draw(){
    ofDrawBitmapString(text, bounds.x+paddingX,bounds.y+bounds.height-paddingY-2);
}

void ofxTextBase::enable(){
    bEnabled = true;
    registerEvents();
}
void ofxTextBase::disable(){
    bEnabled = false;
    bMouseHover = false;
    unregisterEvents();
}
void ofxTextBase::registerEvents(){
    ofAddListener(ofEvents().mouseMoved,    this, &ofxTextBase::onMouseMoved);
    ofAddListener(ofEvents().mousePressed,  this, &ofxTextBase::onMousePressed);
    ofAddListener(ofEvents().mouseReleased, this, &ofxTextBase::onMouseReleased);
}
void ofxTextBase::unregisterEvents(){
    ofRemoveListener(ofEvents().mouseMoved,     this, &ofxTextBase::onMouseMoved);
    ofRemoveListener(ofEvents().mousePressed,   this, &ofxTextBase::onMousePressed);
    ofRemoveListener(ofEvents().mouseReleased,  this, &ofxTextBase::onMouseReleased);
}
bool ofxTextBase::isEnabled(){
    return bEnabled;
}

void ofxTextBase::onMouseMoved(ofMouseEventArgs &arg){
    bMouseHover = bounds.inside(arg.x, arg.y);
}

// -----------------------------------
void ofxTextBase::setPosition(float x, float y){
    bounds.setPosition(x, y);
}
void ofxTextBase::setSize(float x, float y){
    bounds.setSize(x, y);
    bSizeAuto = false;
}
void ofxTextBase::setSizeAuto(bool bAuto){
    bSizeAuto = bAuto;
    calcSizeAuto();
}

void ofxTextBase::calcSizeAuto(){
    if(bSizeAuto){
        ofBitmapFont bitmapFont;
        bounds = bitmapFont.getBoundingBox(text, bounds.getX(), bounds.getY());
        bounds.width += paddingX*2;
        bounds.height += paddingY*2;
        
    }
}
bool ofxTextBase::isMouseHover(){
    return bMouseHover;
}
