#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjSwitchMain.h"
#include"GameL\Audio.h"
#include "UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSwitchMain::Init()
{


	StageSlect = -1;
	for (int i = 0; i < 3; i++)
	{
		((UserData*)Save::GetData())->SPStageSelect[i] = false;
	}

	Save::Open();

	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->SPStageSelect[i] == true)
		{
			StageSlect = i;
		}
	}


	int stage_data[5][5] = {};

	LoadSPStage(StageSlect, *stage_data);

	//�}�b�v�f�[�^���R�s�[
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));

	bool flag_set[5] =
	{ false,false,false,false,false, };
	memcpy(flag, flag_set, sizeof(bool)*(5));
	Clear_count = 12;

}

//�A�N�V����
void CObjSwitchMain::Action()
{
	int sx = 0, sy = 0;
	int lx, ly;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//�����蔻��
	if (160 <= x && 640 >= x && 60 <= y && 540 >= y && ((((int)(y - 60) / 96) % 2 == 0 && ((int)(x - 160) / 96) % 2 == 1) || (((int)(y - 60) / 96) % 2 == 1 && ((int)(x - 160) / 96) % 2 == 0)) && flag[1] == false && flag[2] == false&& flag[3] == false)
	{
		if (Input::GetMouButtonL() == true)    //���N���b�N���p�l���𔽓]������
		{
			//SE��炷
			Audio::Start(1);

			//Count�����炷
			Clear_count--;

			sy = (int)(y - 60) / 96;   //�N���b�N����y���W��z��Ŏg����悤�ɒ���
			sx = (int)(x - 160) / 96;  //�N���b�N����x���W��z��Ŏg����悤�ɒ���
			for (int m = 0; m < 2; m++)
			{
				switch (stage[sy][sx])
				{
				case 2:
					switch (m)
					{
					case 0://��
						ly = sy;
						lx = sx - 1;
						break;
					case 1://�E
						ly = sy;
						lx = sx + 1;
						break;
					}
					break;
				case 3:
					switch (m)
					{
						/*case 0://��
							ly = sy;
							lx = sx - 1;
							break;*/
					case 0://��
						ly = sy - 1;
						lx = sx;
						break;

					case 1://��
						ly = sy + 1;
						lx = sx;
						break;
						/*case 4://�E
							ly = sy;
							lx = sx + 1;
							break;*/
					}
					break;
				}
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)//����̐��퉻
					{
						if (stage[ly][lx] == 0)
						{
							stage[ly][lx] = 1;
						}
						else if (stage[ly][lx] == 1)
						{
							stage[ly][lx] = 0;
						}
					}
				
			}
			while (Input::GetMouButtonL() == true)
			{

			}

			if (SwitchClearCheck(stage) == true)
			{
				flag[1] = true;
			}
			else if (SwitchClearCheck(stage) == false && Clear_count == 0)
			{
				flag[2] = true;
			}

		}
	}
	//GameClear���̔���
	if (flag[1] == true)
	{
		//StageSELECT�֖߂�{�^������
		if (x >= 130 && x <= 690 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());

			}
		}
	}
	//GameOver���̔���
	if (flag[2] == true)
	{
		//BGM��~
		Audio::Stop(0);
		//Yes�{�^������
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				Clear_count = 12;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM��~
				Audio::Start(0);
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				flag[2] = false;
			}
		}
		//No�{�^������
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{

				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
				flag[2] = false;
			}
		}
	}

	//���Z�b�g�{�^�������蔻��
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			Clear_count = 12;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//�q���g�{�^�������蔻��
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{

			flag[0] = true;
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
	//StageSelect�֖߂�{�^������------------------------------------------------------------
	if (x >= 30 && x <= 130 && y >= 60 && y <= 160 && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			flag[3] = true;

			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
	if (flag[3] == true)
	{
		//Yes�{�^������
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Stop(1);
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
			}
		}
		//No�{�^������
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
		{

			if (Input::GetMouButtonL() == true)
			{

				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}

				flag[3] = false;
			}
		}
	}

}

//�h���[
void CObjSwitchMain::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//�e�L�X�g�p

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 96.0f;
	src.m_bottom = 96.0f;

	//stage�̕`��
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };
	Font::StrDraw(L"stage1", 30, 480, 12, f);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			//�\���ʒu�̐ݒ�
			dst.m_top = i * 96.0f + 60.0f;
			dst.m_left = j * 96.0f + 160.0f;
			dst.m_right = dst.m_left + 96.0;
			dst.m_bottom = dst.m_top + 96.0;
			if (stage[i][j] == 0)
			{
				//���p�l��
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 1)
			{
				//���p�l��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 3)
			{
				//���p�l��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 2)
			{
				//���p�l��
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}

		}
	}
	//�q���g�{�^��-----------------------------------------------
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	//�\��
	//�v���O�����̖���x�l��10f���炵�Ă܂�
	dst.m_top = 250.0f;
	dst.m_left = 660.0f;
	dst.m_right = 780.0;
	dst.m_bottom = 350.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�q���g�̕\��
	if (flag[0] == true)
	{
		Font::StrDraw(L"�ŒZ�萔", 20, 200, 32, f);
		Font::StrDraw(L"6��", 40, 260, 32, f);

	}

	//���Z�b�g�{�^��--------------------------------------------
	//�؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	//�\��
	//�v���O�����̖���x�ly�l10f���炵�Ă��܂�
	dst.m_top = 440.0f;
	dst.m_left = 660.0f;
	dst.m_right = 780.0f;
	dst.m_bottom = 540.0f;
	Draw::Draw(4, &src, &dst, c, 0.0f);

	//StageSelect�{�^��-----------------------------------------------
	//�؂���
	src.m_top = 820.0f;
	src.m_left = 478.0f;
	src.m_right = 600.0f;
	src.m_bottom = 920.0f;
	//�\��
	//�v���O�����̖���x�l��10f���炵�Ă܂�
	dst.m_top = 60.0f;
	dst.m_left = 30.0f;
	dst.m_right = 130.0;
	dst.m_bottom = 160.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);


	Font::StrDraw(L"Count", 675, 45, 32, f);

	//Count�̒l�𕶎���---------------------------------------
	wchar_t str[128];
	swprintf_s(str, L"%d", Clear_count);

	if (Clear_count >= 10)
		Font::StrDraw(str, 700, 80, 32, f);
	else if (Clear_count <= 9)
		Font::StrDraw(str, 710, 80, 32, f);
	//�V�[���`��FGameClear!------------------------------------
	if (flag[1] == true)
	{
		src.m_top = 249.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 372.0f;
		dst.m_top = 150.0f;
		dst.m_left = 130.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 270.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		src.m_top = 490.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 610.0f;
		dst.m_top = 370.0f;
		dst.m_left = 130.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 490.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//GameOver------------------------------------
	if (flag[2] == true)
	{
		//GameOver�\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 580.0f;
		src.m_bottom = 250.0f;
		dst.m_top = 70.0f;
		dst.m_left = 110.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 320.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
		//Yes�ENo�{�^���̕`��
		if (flag[2] == true || flag[3] == true)
		{
			src.m_top = 820.0f;
			src.m_left = 0.0f;
			src.m_right = 240.0f;
			src.m_bottom = 940.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = 820.0f;
			src.m_left = 239.0f;
			src.m_right = 480.0f;
			src.m_bottom = 940.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}

	

}