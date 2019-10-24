#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "UtilityModule.h"
#include"GameL/WinInputs.h"

int MousePosX()
{
	float m_mou_x;
	m_mou_x = (float)Input::GetPosX();
	return m_mou_x;
}

int MousePosY()
//マウスの位置を取得Y
{
	float m_mou_y;
	m_mou_y = (float)Input::GetPosY();
	return m_mou_y;
}

