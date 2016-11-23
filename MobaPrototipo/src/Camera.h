#pragma once
#include "GameManager.h"

class Camera
{
private:
	ofVec2f m_screenCenter;
	ofVec2f m_posCamera;

	float m_maxX, m_maxY;
public:
	Camera();
	~Camera();

	void Reset(ofVec2f background);
	void Update(ofVec2f player);

	ofVec2f GetPosCamera();
};