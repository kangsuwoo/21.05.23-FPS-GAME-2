#include "stdafx.h"
#include "BaseScene.h"

BaseScene::BaseScene()
{
}

BaseScene::~BaseScene()
{
	//	delete m_Player;
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Enermy);
}

HRESULT BaseScene::Start()
{
	m_Player = new Player();
	m_Enermy = new Enermy();

	return S_OK;
}

void BaseScene::Update()
{
	m_Player->Update();
	m_Enermy->Update();
	
}

void BaseScene::Render()
{
	m_Player->Render();
	m_Enermy->Render();
}
