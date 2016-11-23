#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Twitch.h"
#include "Camera.h"
#include <vector>
#include "Minion.h"
#include "HUD.h"

class GamePlay
{
private:
	ofImage m_background;
	Twitch *twitch;
	Camera camera;
	HUD *hudson;
	
	vector <Minion> m_minion;

	vector <ofVec2f> m_waypoint1;
	vector <ofVec2f> m_waypoint2;

	float count;

	bool m_showWay;

public:
	GamePlay(GameManager *game);
	~GamePlay();

	void MousePressed(int x, int y, int btn);
	void KeyPressed(int key);

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset(GameManager *game);

};
