#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	gameManager = new GameManager(GAME_MENU);
	gameMenu = new GameMenu();
	gamePlay = new GamePlay(gameManager);
}

//--------------------------------------------------------------
void ofApp::update(){
	switch (gameManager->GetGameState()) {
	case GAME_MENU:
		gameMenu->Update(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->Update(gameManager);
		break;
	case GAME_OVER:
		break;
	case GAME_RESET:
		gameMenu->Reset();
		gamePlay->Reset(gameManager);
		gameManager->SetGameState(GAME_MENU);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (gameManager->GetGameState()) {
	case GAME_MENU:
		gameMenu->Draw(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->Draw(gameManager);
		break;
	case GAME_OVER:
		break;
	case GAME_RESET:
		break;
	}

	gameManager->Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (gameManager->GetGameState() == GAME_PLAY)
	{
		gamePlay->KeyPressed(key);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	std::cout << ofGetMouseX() << "," << ofGetMouseY() << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	switch (gameManager->GetGameState()) {
	case GAME_MENU:
		gameMenu->MousePressed(ofGetMouseX(), ofGetMouseY(), button, gameManager);
		break;
	case GAME_PLAY:
		gamePlay->MousePressed(ofGetMouseX(), ofGetMouseY(), button);
		break;
	case GAME_OVER:
		break;
	case GAME_RESET:
		break;
	}
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
