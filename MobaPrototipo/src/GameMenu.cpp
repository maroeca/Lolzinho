#include "GameMenu.h"

GameMenu::GameMenu()
{
	m_background.loadImage("images/menuBackground.png");
	Reset();
}

GameMenu::~GameMenu()
{
}

void GameMenu::Update(GameManager *game)
{
}

void GameMenu::Draw(GameManager *game)
{
	m_background.draw(0, 0);
	m_play->Draw();
	
}

void GameMenu::Reset()
{
	m_play = new Button(ofGetWindowWidth()/2 - 50, 580, 50, 100, "images/newGame.png");
}

void GameMenu::MousePressed(int x, int y, int btn, GameManager *game)
{
	if (x > m_play->GetPosX() && x < (m_play->GetPosX()+m_play->GetWidth()) 
		&& y > m_play->GetPosY() && y < (m_play->GetPosY() + m_play->GetHeight()) 
		&& btn == OF_MOUSE_BUTTON_1)
		game->SetGameState(GAME_PLAY);

	
}
