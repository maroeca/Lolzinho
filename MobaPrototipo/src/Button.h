#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Button
{
private:
	int m_posX, m_posY;
	int m_width, m_height;
	ofImage m_image;
public:
	Button(int posX, int posY, int height, int width, std::string path);
	~Button();

	int GetWidth();
	int GetHeight();

	int GetPosX();
	int GetPosY();

	void Draw();
};

