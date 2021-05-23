#include "stdafx.h"
#include "Player.h"

Player::Player()
	: m_IsLeft(false),
	m_CurrentFrameX(0), m_CurrentFrameY(0),
	Rotation(0.0f),
	Opacity(1.0f),
	CurrentStatus(IDLE)
{
	_Texture->LoadTexture("배경", L"../_Resources/23.jpg");

	Position = { 100.0f, 400.0f };

	m_Texture = _Texture->LoadTexture(
		"캐릭터", L"../_Resources/Untitled-10.png",
		10, 4);
	Scale = { 70, 64 };

	m_Bullets = new BulletManager();



}

Player::~Player()
{
	SAFE_DELETE(m_Bullets);
}

static int CurrentFrame = 0;
void Player::Update()
{
	bool isChange = false;
	if (_KeyCode->GetKey('A') || _KeyCode->GetKey(VK_LEFT))
	{
		Position.x -= 2.0f;
		m_IsLeft = true;

		if (CurrentStatus != MOVE) {
			isChange = true;
			CurrentStatus = MOVE;
		}
	}
	else if (_KeyCode->GetKey('D') || _KeyCode->GetKey(VK_RIGHT))
	{
		Position.x += 2.0f;
		m_IsLeft = false;

		if (CurrentStatus != MOVE) {
			isChange = true;
			CurrentStatus = MOVE;
		}
	}
	else {
		if (CurrentStatus != IDLE)
		{
			isChange = true;
			CurrentStatus = IDLE;
		}
	}

	if (_KeyCode->GetKeyDown(VK_LBUTTON))
	{
		isChange = true;
		float angle = Collision::GetAngle(Position.x, Position.y, MousePoint.x, MousePoint.y);
		m_Bullets->Shoot(Position.x + 2.5f, Position.y, angle, 5.0f);


	}

	////	Test
	//if (_KeyCode->GetKeyDown(VK_LBUTTON))
	//{
	//	if (Collision::IsInRectPoint(GetRect(), MousePoint))
	//		printf("Click!\n");
	//}
	//if (_KeyCode->GetKeyUp(VK_LBUTTON))
	//{
	//	printf("Click! Up\n");
	//}

	if (isChange) CurrentFrame = 0;
	else CurrentFrame++;

	//	FSM -> 유한 기계 상태
	switch (CurrentStatus)
	{
		case IDLE:
		{
			m_CurrentFrameY = 0;
			if (CurrentFrame % 10 == 0)
			{
				CurrentFrame = 0;
				m_CurrentFrameX++;
				if (m_CurrentFrameX == 9 + 1)
					m_CurrentFrameX = 0;
				
			}
		}
		break;

		case MOVE:
		{

			if (isChange) m_CurrentFrameY = 1;
			if (CurrentFrame % 10 == 0)
			{
				CurrentFrame = 0;
				m_CurrentFrameX++;
				if (m_CurrentFrameX == 7 + 1)
					m_CurrentFrameX = 2;
			}
		}
		break;
	}

	m_Bullets->Update();
}

void Player::Render()
{
	_Texture->Find("배경")->Draw(0.0f, 0.0f, _Application->Width, _Application->Height);

	_RenderTarget->DrawRectangle(GetRect(), _Renderer->GetBrush());

	//	프레임 렌더할 때 중요한 것
	//	포지션, 프레임 포지션, 리버스 유무, 크기, 투명도
	m_Texture->DrawFrame(
		Position.x, Position.y,
		m_CurrentFrameX, m_CurrentFrameY,
		Scale.x, Scale.y,
		m_IsLeft,
		Rotation,
		Opacity);

	m_Bullets->Render();
}
