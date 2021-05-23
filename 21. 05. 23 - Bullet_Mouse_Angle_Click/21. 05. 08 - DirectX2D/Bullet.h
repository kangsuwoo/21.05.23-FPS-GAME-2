#pragma once

class Bullet
{
public:
	Bullet(float x, float y, float angle, float speed);
	~Bullet();

private:
	BaseTexture* m_Texture;

	UINT m_CurrentFrameX;
	D2D_VECTOR_2F m_Position;
	float m_Angle;
	float m_Speed;
	bool m_IsReverse;

	int m_CurrentFrame;

public:
	bool Update();
	void Render();

	D2D1_ELLIPSE GetCircle()
	{
		float radius = m_Texture->GetSize().width / 2;
		return D2D1::Ellipse(
			D2D1::Point2F(m_Position.x + 35, m_Position.y + 45),
			8, 8
		);
	}
};

