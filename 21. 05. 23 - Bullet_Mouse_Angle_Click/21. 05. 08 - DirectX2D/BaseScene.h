#pragma once
#include "Player.h"
#include "Enermy.h"

//	IScene �̶�� �༮�� ������ָ�
//	�� �༮�� �� �̾�! ��� �˷��ְԵȴ� (Start, Update, Render)
class BaseScene : public IScene
{
public:
	BaseScene();
	~BaseScene();

private:
	Player* m_Player;
	Enermy* m_Enermy;

public:
	// IScene��(��) ���� ��ӵ�
	virtual HRESULT Start() override;
	virtual void Update() override;
	virtual void Render() override;
};

