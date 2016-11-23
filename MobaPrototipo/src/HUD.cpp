#include "HUD.h"

HUD::HUD()
{
	m_background.loadImage("images/hudBar.png");
	Reset();
}

HUD::~HUD()
{
}
void HUD::Reset()
{
	m_posX = 0;
	m_posY = 0;
	m_width = 1280;
	m_height = 50;
	m_timer = 0.0f;
}



void HUD::Update(GameManager *game, Twitch *twitch)
{
	twitch->GetHp();
	twitch->GetMana();
	m_timer += ofGetLastFrameTime();
}

void HUD::Draw(Twitch *twitch)
{
	m_background.draw(m_posX, m_posY);
	ofSetColor(ofColor::white);
	ofDrawBitmapString("HP: " + ofToString(twitch->GetHp()), 125, 57);
	ofSetColor(ofColor::white);
	ofDrawBitmapString("Mana: " + ofToString(twitch->GetMana()), 215, 57);
	ofSetColor(ofColor::white);
	ofDrawBitmapString(ofToString(m_timer), 550, 57);

	string fpsStr = "FPS: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(fpsStr, 1165, 57);
}