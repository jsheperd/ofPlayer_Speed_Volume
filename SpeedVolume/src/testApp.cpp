#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	beats.loadSound("sounds/1085.mp3");
	SoundFileName = string("sounds/1085.mp3");
	beats.setVolume(0.75f);
	beats.setMultiPlay(false);
	beats.setLoop(true);
}

//--------------------------------------------------------------
void testApp::update(){

	ofBackground(255,255,255);
	// update the sound playing system:
	ofSoundUpdate();

}

//--------------------------------------------------------------
void testApp::draw(){
    string tempStr;

	ofSetHexColor(0x000000);
	tempStr = "Click somewhere to start (Volume/vertical, Speed/horizontal position).";
    tempStr += "\ndrag&drop audio or load with <SPACE>, <s> strat/stop";
	tempStr += "\nspeed: " + ofToString(beats.getSpeed());
	tempStr += "\nvolume: " + ofToString(beats.getVolume());
	tempStr += "\nFilename:" + SoundFileName;
	ofDrawBitmapString(tempStr, 50,ofGetHeight()-80);


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == ' '){

		//Open the Open File Dialog
		ofFileDialogResult openFileResult= ofSystemLoadDialog("Select a soundfile (mp3, wav)");

		//Check if the user opened a file
		if (openFileResult.bSuccess){
                SoundFileName = openFileResult.filePath;
                beats.loadSound(SoundFileName);
		}
	}

    if (key == 's'){
        if (beats.getIsPlaying()) beats.stop();
        else beats.play();
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
        beats.setSpeed( ( float(x) / float(ofGetWidth()) ) + 0.5f );
        beats.setVolume( 1.0f - ( float(y)/float(ofGetHeight()) ) ) ;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
        beats.setSpeed( ( float(x) / float(ofGetWidth()) ) + 0.5f );
        beats.setVolume( 1.0f - ( float(y)/float(ofGetHeight()) ) ) ;
		beats.play();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){
  if( info.files.size() > 0 ){
      try{
        SoundFileName = info.files[0];
        beats.loadSound(SoundFileName);
      }
      catch(...){

      }
  }
}
