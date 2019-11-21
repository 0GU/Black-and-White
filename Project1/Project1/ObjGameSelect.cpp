//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "Windows.h"

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
	if (SELECT_POS_L <= x && SELECT_POS_R >= x && SW_SELECT_POS_T <= y && SW_SELECT_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneSwitchSelect());

		}
	}
	//���o�[�V�u���̃X�e�[�W�Z���N�g�ֈړ�
	if (SELECT_POS_L <= x && SELECT_POS_R >= x && RP_SELECT_POS_T <= y && RP_SELECT_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleSelect());
		}
	}
	//�߂�{�^��
	if (BACKBUTTON_POS_L <= x && BACKBUTTON_POS_R >= x && BACKBUTTON_POS_T <= y && BACKBUTTON_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(2);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SCENEBACK_WAIT);
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

	//GAME SELECT�\��-----------------------------------------------------
	src.m_top   = RESOURCE_SCENE_TEXT_T;
	src.m_left  = RESOURCE_SCENE_TEXT_L;
	src.m_right = RESOURCE_SCENE_TEXT_R;
	src.m_bottom= RESOURCE_SCENE_TEXT_B;
	dst.m_top   = SCENE_TEXT_POS_T;
	dst.m_left  = SCENE_TEXT_POS_L;
	dst.m_right = SCENE_TEXT_POS_R;
	dst.m_bottom= SCENE_TEXT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//SwitchPanel�\��-----------------------------------------------------
	src.m_top   = RESOURCE_SW_SELECT_T;
	src.m_left  = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom= RESOURCE_SW_SELECT_B;
	dst.m_top   = SW_SELECT_POS_T;
	dst.m_left  = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom= SW_SELECT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//ReversiblePanel-----------------------------------------------------
	src.m_top   = RESOURCE_RP_SELECT_T;
	src.m_left  = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom= RESOURCE_RP_SELECT_B;
	dst.m_top   = RP_SELECT_POS_T;
	dst.m_left  = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom= RP_SELECT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//�߂�{�^��-----------------------------------------------------------
	src.m_top   = RESOURCE_BACK_T;
	src.m_left  = RESOURCE_BACK_L;
	src.m_right = RESOURCE_BACK_R;
	src.m_bottom= RESOURCE_BACK_B;
	dst.m_top   = BACKBUTTON_POS_T;
	dst.m_left  = BACKBUTTON_POS_L;
	dst.m_right = BACKBUTTON_POS_R;
	dst.m_bottom= BACKBUTTON_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

}