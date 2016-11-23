#include "Twitch.h"

Twitch::Twitch()
{
	m_image.loadImage("images/twitch.png");
	m_image.setAnchorPoint(m_image.getWidth()/2, m_image.getHeight()/2);
	Reset();
}

Twitch::~Twitch()
{
}

void Twitch::Move()
{
	m_direction = m_destiny - m_position;
	m_speed = m_direction.normalize();

	if (m_destiny.distance(m_position) > 5)
		m_position += m_speed * m_spdParametro;
}

void Twitch::Update(GameManager *game)
{
	this->Move();
	if (m_invisible)
	{
		if (m_invisibleDuration >= 2.0f)
		{
			m_invisible = false;
			m_spdParametro = 2;
			m_invisibleDuration = 0;
		}
		else
		{
			m_invisibleDuration += ofGetLastFrameTime();
		}
	}
	if (m_poison)
	{
		if (m_poisonDuration >= 1.5)
		{
			m_poison = false;
			m_poisonDuration = 0.0f;
		}
		else
			m_poisonDuration += ofGetLastFrameTime();
	}	
	this->CooldownReduction();
	this->Regen();
}

void Twitch::Draw(const ofVec2f& camera)
{
	if (m_invisible)
	{
		ofSetColor(255, 255, 255, 30);
		m_image.draw(m_position -camera);
		ofSetColor(255, 255, 255, 255);
	}
	else
	{
		ofSetColor(255, 255, 255, 255);
		m_image.draw(m_position - camera);
	}
}

void Twitch::Reset()
{
	m_position.set(0, 400);
	m_destiny.set(0, 400);

	m_hp = 1920.0f;
	m_mana = 970.0f;

	m_invisible = false;
	m_timeCooldownQ = 0.0f; 
	m_cooldownQ = false;
	m_invisibleDuration = 0.0f;
	m_poison = false;
	m_cooldownW = false;
	m_timeCooldownW = 0.0f;
	m_poisonDuration = 0.0f;

	m_spdParametro = 2;

	m_regenTime = 0.0f;
}

void Twitch::BaseAtk()
{
	ofDrawCircle(this->m_position.x, this->m_position.y, 1);
	m_atkDir = m_position.normalize() - (ofVec2f(ofGetMouseX(), ofGetMouseY()).normalize());
}

void Twitch::Ambush()
{
	if (m_mana >= 40.0f)
	{
		m_invisible = true;
		m_spdParametro = 3;
		m_cooldownQ = true;
		m_mana -= 40.0f;
	}
}

void Twitch::VenonCask()
{
	if (m_mana >= 50.0f)
	{
		m_poison = true;
		m_cooldownW = true;
		m_mana -= 50.0f;
	}
	//ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 10);
}

bool Twitch::GetCooldown(int key)
{
	if (key == 'q' || key == 'Q')
		return m_cooldownQ;
	else if (key == 'w' || key == 'W')
		return m_cooldownW;
}

bool Twitch::GetPoison()
{
	return m_poison;
}

void Twitch::SetPoisonPos(ofVec2f camera)
{
	m_poisonPos.set(ofVec2f(ofGetMouseX(), ofGetMouseY())+camera);
}

ofVec2f Twitch::GetPoisonPos()
{
	return m_poisonPos;
}

void Twitch::CooldownReduction()
{
	if (m_cooldownQ)
	{
		if (m_timeCooldownQ >= 16.0f)
		{
			m_cooldownQ = false;
			m_timeCooldownQ = 0.0f;
		}
		else
			m_timeCooldownQ += ofGetLastFrameTime();
	}
	if (m_cooldownW)
	{
		if (m_timeCooldownW >= 9.0f)
		{
			m_cooldownW = false;
			m_timeCooldownW = 0.0f;
		}
		else
			m_timeCooldownW += ofGetLastFrameTime();
	}
}

void Twitch::Regen()
{
	if (m_regenTime >= 1)
	{
		if (m_hp < 1905.0f)
			m_hp += 6.0f;
		if (m_mana < 970.0f)
			m_mana += 5.0f;
		m_regenTime = 0.0f;
	}
	else
		m_regenTime += ofGetLastFrameTime();
}

void Twitch::SetPosition(ofVec2f position)
{
	m_position = position;
}

void Twitch::SetDirection(ofVec2f direction)
{
	m_direction = direction;
}

void Twitch::SetSpeed(ofVec2f speed)
{
	m_speed = speed;
}

void Twitch::SetDestiny(ofVec2f destiny)
{
	m_destiny = destiny;
}

void Twitch::SetDistance(ofVec2f distance)
{
	m_distance = distance;
}

ofVec2f Twitch::GetPosition()
{
	return m_position;
}

ofVec2f Twitch::GetDirection()
{
	return m_direction;
}

ofVec2f Twitch::GetSpeed()
{
	return m_speed;
}

ofVec2f Twitch::GetDestiny()
{
	return m_destiny;
}

ofVec2f Twitch::GetDistance()
{
	return m_distance;
}

float Twitch::GetMana()
{
	return m_mana;
}

float Twitch::GetHp()
{
	return m_hp;
}
