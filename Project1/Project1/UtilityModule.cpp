#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "UtilityModule.h"
#include"GameL/WinInputs.h"

void MousePosX(float x)
{
	x = (float)Input::GetPosX();
}

void MousePosY(float y)
//�}�E�X�̈ʒu���擾Y
{
	y = (float)Input::GetPosY();
}

bool MouseDownL()
{
	bool m_mou_l;
	 m_mou_l = Input::GetMouButtonL();
	 return m_mou_l;
}