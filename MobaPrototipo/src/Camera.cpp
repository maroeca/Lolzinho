#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Reset(ofVec2f background)
{
	m_screenCenter.set(ofGetWidth() / 2, ofGetHeight() / 2);

	m_maxX = background.x - (ofGetWidth());
	m_maxY = background.y - (ofGetHeight());
}

void Camera::Update(ofVec2f player)
{
	m_posCamera = player - m_screenCenter;

	if (m_posCamera.x <= 0)
		m_posCamera.x = 0;

	else if (m_posCamera.x >= m_maxX)
		m_posCamera.x = m_maxX;

	if (m_posCamera.y <= 0)
		m_posCamera.y = 0;

	else if (m_posCamera.y >= m_maxY)
		m_posCamera.y = m_maxY;
}

ofVec2f Camera::GetPosCamera()
{
	return m_posCamera;
}
