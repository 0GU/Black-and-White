//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"windows.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_time = 0;
}

//�A�N�V����
void CObjTitle::Action()
{

	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	if (0 <= x && 800 >= x && 0 <= y && 600 >= y)
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
				Sleep(500);
			
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
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}