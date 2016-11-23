#pragma once

#include "GameManager.h"
#include "Twitch.h"

class HUD
{
private:
	int m_posX, m_posY;
	int m_width, m_height;
	ofImage m_background;

	float m_timer;
public:
	HUD();
	~HUD();

	void Update(GameManager *game, Twitch *twitch);
	void Draw(Twitch *twitch);
	void Reset();

};