#pragma once
class Enermy
{
public:
	Enermy();
	~Enermy();

private:
	BaseTexture* m_Texture;

public:
	void Update();
	void Render();

public:
	D2D_VECTOR_2F Position;
	float Rotation;
	D2D_VECTOR_2F Scale;
	float Opacity;

public:
	D2D1_RECT_F GetRect() {
		return D2D1::RectF(
			Position.x + 5, Position.y,
			Position.x + Scale.x - 30, Position.y + Scale.y - 10.0f);
	}

};

