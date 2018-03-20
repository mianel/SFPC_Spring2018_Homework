#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    ofSetLineWidth(2);
    coutPar = 0;
    
    total = 543;
    mParticles.resize(total);
   // mParticles.resize(total);
    
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 150, true, true, true);
    myString = "SFPC";
    loadCharacters(myString);
    
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
   
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(5);
            
            for (int k = 0; k < line.size(); k++) {
                ofPoint point = line[k];
                mParticles[coutPar].setup(ofVec3f(point.x, point.y, 0));
                coutPar++;
            }
        }
    }

}

//--------------------------------------------------------------
ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < total; i++) {
        mParticles[i].behaviors();
        mParticles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    
    float time = ofGetElapsedTimef() * 1.5;
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();
    
   // cam.begin();
    ofPushMatrix();
    ofTranslate(stageW/2, stageH/2 - 20);
    ofTranslate(centerCharacter(myString));

    for(int i = 0; i < total; i++){
        mParticles[i].draw();
    }

    ofPopMatrix();
   // cam.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

