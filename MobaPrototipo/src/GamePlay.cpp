#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground2.png");
	twitch = new Twitch();  
	hudson = new HUD();

	/*--caminho dos waypoints--*/
	m_waypoint1.push_back(ofVec2f(110,216));
	m_waypoint1.push_back(ofVec2f(329,320));
	m_waypoint1.push_back(ofVec2f(515,393));
	m_waypoint1.push_back(ofVec2f(689,465));
	m_waypoint1.push_back(ofVec2f(850,531));
	/*m_waypoint1.push_back(ofVec2f(856,554));
	m_waypoint1.push_back(ofVec2f(856,400));*/
	
	m_waypoint2.push_back(ofVec2f(29,1000));
	m_waypoint2.push_back(ofVec2f(310,990));
	m_waypoint2.push_back(ofVec2f(350,780));
	m_waypoint2.push_back(ofVec2f(663,820));
	m_waypoint2.push_back(ofVec2f(752,593));
	/*m_waypoint2.push_back(ofVec2f(900, 593));
	m_waypoint2.push_back(ofVec2f(1000, 593));*/

	//-------------------------
	count = 0.0f;

	Reset(game);
}
GamePlay::~GamePlay()
{
	
}

void GamePlay::MousePressed(int x, int y, int btn)
{	/*-- posição de deslocamento--*/
	if (btn == OF_MOUSE_BUTTON_3)
	{
		ofVec2f destination = ofVec2f(ofGetMouseX(), ofGetMouseY());
		destination += camera.GetPosCamera();
		twitch->SetDestiny(destination);
	}
}

void GamePlay::KeyPressed(int key)
{	/*--chama a primeira skill--*/
	if (key == 'q' || key == 'Q')
	{
		if (twitch->GetCooldown(key) == false)
			twitch->Ambush();
	}
	/*--chama a segunda skill--*/
	if (key == 'w' || key == 'W')
	{
		if (twitch->GetCooldown(key) == false)
		{
			twitch->SetPoisonPos(camera.GetPosCamera());
			twitch->VenonCask();
		}
	}
	if (key == 'i' || key == 'I')
	{
		m_showWay = !m_showWay;
	}
}

void GamePlay::Update(GameManager * game)
{
	twitch->Update(game);
	camera.Update(twitch->GetPosition());
	hudson->Update(game,twitch);

	count += ofGetLastFrameTime();
	if (count > 15) {
		int random = rand() % 2;
		m_minion.push_back(Minion(random == 0 ? m_waypoint1 : m_waypoint2));
	
		
		for (int i = 0; i < m_minion.size(); i++)
		{
			m_minion[i].Reset();
		}
		count = 0;
	}

	for (int i = 0; i < m_minion.size(); i++)
	{
		m_minion[i].Update(game);
	}
}

void GamePlay::Draw(GameManager * game)
{
	m_background.draw(-camera.GetPosCamera());
	/*--draw dos waypoints--*/
	if (m_showWay)
	{
		ofSetColor(255, 255, 255, 0);
	}
	else
		ofSetColor(255);
	for (int i = 0; i < m_waypoint1.size(); i++) {
		ofDrawCircle(m_waypoint1[i] - camera.GetPosCamera(), 5);
		ofDrawCircle(m_waypoint2[i] - camera.GetPosCamera(), 5);
	}
	ofSetColor(255);

	twitch->Draw(camera.GetPosCamera());
	
	/*-- draw dos minions--*/
	for (int i = 0; i < m_minion.size(); i++)
	{
		m_minion[i].Draw(camera.GetPosCamera());
	}

	/*--draw da skill--*/
	if (twitch->GetPoison())
	{
		ofDrawCircle(twitch->GetPoisonPos() - camera.GetPosCamera(), 50);
	}	
	hudson->Draw(twitch);
}

void GamePlay::Reset(GameManager * game)
{
	twitch->Reset();
	camera.Reset(ofVec2f(m_background.getWidth(), m_background.getHeight()));
	hudson->Reset();
	m_showWay = false;
}
