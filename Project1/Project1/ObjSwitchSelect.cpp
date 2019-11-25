//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjSwitchSelect.h"
#include"ObjSwitchMain.h"
#include"Windows.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSwitchSelect::Init()
{
	m_y1 = 0.0f;
	m_y2 = 600.0f;

	bool set_Pflag[3] = { false, false ,false };
	bool set_Cflag[3] = { false, false ,false };

	Save::Open();

	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->SClearFlag[i] == true)
		{
			set_Cflag[i] = true;
		}

		if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
		{
			set_Pflag[i] = true;
		}
	}
	memcpy(Pflag, set_Pflag, sizeof(bool)*(3));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(3));
}

//�A�N�V����
void CObjSwitchSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//right�l���`��ƃY���Ă����ג���
	if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_ONE_T <= y && STAGE_SW_SELECT_ONE_B >= y)//stage1
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			
			
			Scene::SetScene(new CSceneSwitchMain(1));
		}
	}
	if (Cflag[0] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_TWO_T <= y && STAGE_SW_SELECT_TWO_B >= y)//stage2
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);


				Scene::SetScene(new CSceneSwitchMain(2));

			}
		}
	}
	if (Cflag[1] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_THREE_T <= y && STAGE_SW_SELECT_THREE_B >= y)//stage3
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);


				Scene::SetScene(new CSceneSwitchMain(3));

			}
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
			Scene::SetScene(new CSceneGameSelect());

		}
	}
	//�w�i�X�N���[��
	m_y1 -= 1.0f;
	if (m_y1 < -600.0f)
		m_y1 = 600;
	m_y2 -= 1.0f;
	if (m_y2 < -600.0f)
		m_y2 = 600;
}

//�h���[
void CObjSwitchSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//�e�L�X�g�p

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu


	//�w�i�X�N���[��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 0.0f + m_y1;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f + m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�w�i���X�^�[�g
	dst.m_top = 0.0f + m_y2;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f + m_y2;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//STAGE1
	src.m_top = RESOURCE_STAGE1_T;
	src.m_left = RESOURCE_STAGE_L;
	src.m_right = RESOURCE_STAGE_R;
	src.m_bottom = RESOURCE_STAGE1_B;
	dst.m_top = STAGE_SW_SELECT_ONE_T;
	dst.m_left = STAGE_SW_SELECT_L;
	dst.m_right = STAGE_SW_SELECT_R_DRAW;
	dst.m_bottom = STAGE_SW_SELECT_ONE_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//STAGE2
	if (Cflag[0] == true)
	{
		src.m_top = RESOURCE_STAGE2_T;
		src.m_left = RESOURCE_STAGE_L;
		src.m_right = RESOURCE_STAGE_R;
		src.m_bottom = RESOURCE_STAGE2_B;
		dst.m_top = STAGE_SW_SELECT_TWO_T;
		dst.m_bottom = STAGE_SW_SELECT_TWO_B;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//STAGE3
	if (Cflag[1] == true)
	{
		src.m_top = RESOURCE_STAGE3_T;
		src.m_bottom = RESOURCE_STAGE3_B;
		dst.m_top = STAGE_SW_SELECT_THREE_T;
		dst.m_bottom = STAGE_SW_SELECT_THREE_B;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//�߂�{�^��
	src.m_top = RESOURCE_BACKBUTTON_T;
	src.m_left = RESOURCE_BACKBUTTON_L;
	src.m_right = RESOURCE_BACKBUTTON_R;
	src.m_bottom = RESOURCE_BACKBUTTON_B;
	dst.m_top = BACKBUTTON_POS_T;
	dst.m_left = BACKBUTTON_POS_L;
	dst.m_right = BACKBUTTON_POS_R;
	dst.m_bottom = BACKBUTTON_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�����̕`��---------------------------------------------------------------------------

	//(1)
	if (Pflag[0] == false && Cflag[0] == true)
	{
		src.m_top = RESOURCE_STAR_T;
		src.m_left = RESOURCE_STAR_L;
		src.m_right = RESOURCE_STAR_R;
		src.m_bottom = RESOURCE_STAR_B;
		dst.m_top = STAGE_SW_STAR_ONE_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_ONE_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//(2)
	if (Pflag[1] == false && Cflag[1] == true)
	{
		src.m_top = RESOURCE_STAR_T;
		src.m_left = RESOURCE_STAR_L;
		src.m_right = RESOURCE_STAR_R;
		src.m_bottom = RESOURCE_STAR_B;
		dst.m_top = STAGE_SW_STAR_TWO_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_TWO_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//(3)
	if (Pflag[2] == false && Cflag[2] == true)
	{
		src.m_top = RESOURCE_STAR_T;
		src.m_left = RESOURCE_STAR_L;
		src.m_right = RESOURCE_STAR_R;
		src.m_bottom = RESOURCE_STAR_B;
		dst.m_top = STAGE_SW_STAR_THREE_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//�����̕`��---------------------------------------------------------------------------
	//(1)
	if (Pflag[0] == true)
	{
		src.m_top = RESOURCE_PSTAR_T;
		src.m_left = RESOURCE_PSTAR_L;
		src.m_right = RESOURCE_PSTAR_R;
		src.m_bottom = RESOURCE_PSTAR_B;
		dst.m_top = STAGE_SW_STAR_ONE_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_ONE_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		src.m_top = RESOURCE_PSTAR_T;
		src.m_left = RESOURCE_PSTAR_L;
		src.m_right = RESOURCE_PSTAR_R;
		src.m_bottom = RESOURCE_PSTAR_B;
		dst.m_top = STAGE_SW_STAR_TWO_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_TWO_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		src.m_top = RESOURCE_PSTAR_T;
		src.m_left = RESOURCE_PSTAR_L;
		src.m_right = RESOURCE_PSTAR_R;
		src.m_bottom = RESOURCE_PSTAR_B;
		dst.m_top = STAGE_SW_STAR_THREE_T;
		dst.m_left = STAGE_SW_STAR_L;
		dst.m_right = STAGE_SW_STAR_R;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}