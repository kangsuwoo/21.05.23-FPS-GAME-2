#include "stdafx.h"
#include "Enermy.h"

Enermy::Enermy()
{
	Position = { 600.0f, 400.0f };

	m_Texture = _Texture->LoadTexture(
		"Ä³¸¯ÅÍ", L"../_Resources/Untitled-10.png",
		10, 4);
	Scale = { 70, 64 };
}

Enermy::~Enermy()
{
}

void Enermy::Update()
{
}

void Enermy::Render()
{

	_RenderTarget->DrawRectangle(GetRect(), _Renderer->GetBrush());

	m_Texture->DrawFrame(
		Position.x, Position.y,
		0, 0,
		Scale.x, Scale.y,
		true,
		Rotation,
		Opacity);
}
