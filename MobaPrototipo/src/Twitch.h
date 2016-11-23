#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Twitch
{
private:
	ofVec2f m_position;
	ofVec2f m_direction;
	ofVec2f m_speed;
	ofVec2f m_destiny;
	ofVec2f m_center;
	ofVec2f m_distance;

	float m_hp, m_mana;
	ofImage m_image;

	/*---Skills---*/
	ofVec2f m_atkDir;
	int m_spdParametro;
	bool m_cooldownQ;
	bool m_invisible;
	bool m_poison;
	bool m_cooldownW;
	ofVec2f m_poisonPos;
	float m_poisonDuration;
	float m_timeCooldownQ;
	float m_timeCooldownW;
	float m_invisibleDuration;

	/*--regen--*/
	float m_regenTime;

public:
	Twitch();
	~Twitch();

	void Move();

	void Update(GameManager *game);
	void Draw(const ofVec2f& camera);
	void Reset();

	/*-----Skills-----*/
	void BaseAtk();
	void Ambush();
	void VenonCask();
	bool GetCooldown(int key);
	bool GetPoison();
	void SetPoisonPos(ofVec2f camera);
	ofVec2f GetPoisonPos();
	void CooldownReduction();
	
	/*--Regen--*/
	void Regen();

	/*-------- Setters-------*/
	void SetPosition(ofVec2f position);
	void SetDirection(ofVec2f direction);
	void SetSpeed(ofVec2f speed);
	void SetDestiny(ofVec2f destiny);
	void SetDistance(ofVec2f distance);

	/*-----Getters-----*/
	ofVec2f GetPosition();
	ofVec2f GetDirection();
	ofVec2f GetSpeed();
	ofVec2f GetDestiny();
	ofVec2f GetDistance();
	float GetMana();
	float GetHp();

};