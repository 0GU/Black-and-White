//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"GameHead.h"
#include"ObjGameSelect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameSelect::Init()
{

}

//�A�N�V����
void CObjGameSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//�X�C�b�`�̃X�e�[�W�Z���N�g�ֈړ�
	if (100 <= x && 700 >= x && 200 <= y && 292 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{

			Scene::SetScene(new CSceneSwitchMain());

		}
	}
	//���o�[�V�u���̃X�e�[�W�Z���N�g�ֈړ�
	if (100 <= x && 700 >= x && 400 <= y && 492 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (Input::GetMouButtonL() == true)
			{
				
			}
			Scene::SetScene(new CSceneStageSelect());
		}
	}
	//�߂�{�^��
	if (5 <= x && 125 >= x && 35 <= y && 135 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			while (Input::GetMouButtonL() == true)
			{

			}
			Scene::SetScene(new CSceneModeSelect());

		}
	}

}

//�h���[
void CObjGameSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//GAME SELECT�\��
	src.m_top = 135.0f;
	src.m_left = 1.0f;
	src.m_right = 560.0f;
	src.m_bottom = 265.0f;
	dst.m_top = 20.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 155.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//SwitchPanel�\��
	src.m_top = 658.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 750.0f;
	dst.m_top = 200.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.0;
	dst.m_bottom = 292.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//ReversiblePanel
	src.m_top = 746.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 838.0f;
	dst.m_top = 400.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.0;
	dst.m_bottom = 492.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//�߂�{�^��
	src.m_top = 139.0f;
	src.m_left = 559.0f;
	src.m_right = 679.0f;
	src.m_bottom = 239.0f;
	dst.m_top = 35.0f;
	dst.m_left = 5.0f;
	dst.m_right = 125.0;
	dst.m_bottom = 135.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

}