#include "Button.h"

Button::Button(int posX, int posY, int height, int width, std::string path)
{
	m_posX = posX;
	m_posY = posY;
	m_height = height;
	m_width = width;
	m_image.loadImage(path);
}


Button::~Button()
{
}

void Button::Draw() {
	m_image.draw(m_posX, m_posY);
}

int Button::GetWidth() {
	return m_width;
}

int Button::GetHeight() {
	return m_height;
}

int Button::GetPosX() {
	return m_posX;
}

int Button::GetPosY() {
	return m_posY;
}