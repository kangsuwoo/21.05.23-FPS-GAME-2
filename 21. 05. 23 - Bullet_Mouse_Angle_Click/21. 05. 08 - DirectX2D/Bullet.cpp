#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(float x, float y, float angle, float speed)
	: m_Position({x, y}), m_Speed(speed),
	  m_Angle(angle)
{
	m_IsReverse = m_Speed < 0;
	m_Texture = _Texture->LoadTexture("Bullet", L"../_Resources/Bullet.png"
		);
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{
	float x = cosf(m_Angle) * m_Speed;
	float y = sinf(m_Angle) * m_Speed;

	m_Position.x += x;
	m_Position.y += y;

	



	if (m_Position.x <= -m_Texture->GetSize().width || m_Position.x > _Application->Width + m_Texture->GetSize().width)
		return false;

	return true;
}

void Bullet::Render()
{

	m_Texture->Draw(m_Position.x + 30 , m_Position.y + 40, 10, 10);
}
