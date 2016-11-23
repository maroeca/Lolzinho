#pragma once

#include "ofMain.h"
#include "GameManager.h"

class GameMenu
{
private:
	ofImage m_background;

	Button *m_play;
public:
	GameMenu();
	~GameMenu();

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset();
	void MousePressed(int x, int y, int btn, GameManager *game);
};