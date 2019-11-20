//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"windows.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define WINDOW_SIZE_X (800.0f)
#define WINDOW_SIZE_Y (600.0f)
#define CLICK_WAIT (300)

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_time = 0;

	Save::Seve();

	for(int i=0; i<3; i++)
	{ 
		((UserData*)Save::GetData())->SPerfectFlag[i] = false;
		((UserData*)Save::GetData())->RPerfectFlag[i] = false;
	}
}

//�A�N�V����
void CObjTitle::Action()
{	
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	if (0 <= x && WINDOW_SIZE_X >= x && 0 <= y && WINDOW_SIZE_Y >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(CLICK_WAIT);
			
				Scene::SetScene(new CSceneModeSelect());
				
			}
		}
		
	}
}

//�h���[
void CObjTitle::Draw()
{
	// �`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�߂�{�^��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = WINDOW_SIZE_X;
	src.m_bottom = WINDOW_SIZE_Y;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom = WINDOW_SIZE_Y;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}