#pragma once
#include "GameManager.h"

class Minion
{
private:
	ofImage m_image;
	float m_hp;
	ofVec2f m_position;
	ofVec2f m_destiny;
	int current;
	float m_size;
public:
	Minion(vector <ofVec2f>& path);
	~Minion();

	void Update(GameManager *game);
	void Draw(const ofVec2f& camera);
	void Reset();

	float GetPosX();
	float GetPosY();

	vector <ofVec2f>& receiver;
};