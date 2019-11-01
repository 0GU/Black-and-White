#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL/Audio.h"
#include "UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjReversibleMain::Init()
{
	int stage_data[5][5] =
	{
		{0,1,1,0,1},
		{1,0,1,1,0},
		{1,1,0,1,0},
		{1,0,0,0,1},
		{0,1,1,1,1},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));
	
	bool flag_set[3] =
	{ false,false,false };
	memcpy(flag, flag_set, sizeof(bool)*(3));

	Clear_count = 22;
}

//�A�N�V����
void CObjReversibleMain::Action()
{
	int sx=0, sy=0;
	int lx, ly;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	//�����蔻��
	if (160<=x&&640>=x&&60<=y&&540>=y&&flag[1]==false&&flag[2]==false)
	{
		if ( Input::GetMouButtonL()== true)    //���N���b�N���p�l���𔽓]������
		{
			//SE��炷
			Audio::Start(1);

			//Count�����炷
			Clear_count--;

			sx = (y - 60) / 96;   //�N���b�N����y���W��z��Ŏg����悤�ɒ���
			sy = (x - 160) / 96;  //�N���b�N����x���W��z��Ŏg����悤�ɒ���
			for (int m = 0; m < 5; m++)
			{
				switch (m)
				{
				case 0:
					lx = sx;
					ly = sy-1;
					break;
				case 1:
					lx = sx-1;
					ly = sy;
					break;
				case 2:
					lx = sx;
					ly = sy;
					break;
				case 3:
					lx = sx+1;
					ly = sy;
					break;
				case 4:
					lx = sx;
					ly = sy+1;
					break;
				}
				if(lx>=0&&ly>=0&& lx <= 4 && ly <= 4)
				{
					if (stage[lx][ly] == 0)
					{
						stage[lx][ly] = 1;
					}
					else if (stage[lx][ly] == 1)
					{
						stage[lx][ly] = 0;
					}
				}
			}
			while (Input::GetMouButtonL() == true)
			{

			}

			if (ReversibleClearCheck(stage)==true)
			{
				flag[1] = true;
			}
			else if (ReversibleClearCheck(stage) == false&&Clear_count==0)
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

		}
	}
	//GameOver���̔���
	if (flag[2]==true)
	{
		//Yes�{�^������
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				Clear_count = 22;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
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

		}
	}

	//���Z�b�g�{�^�������蔻��
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y&&flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			Clear_count = 22;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//�q���g�{�^�������蔻��
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y&& flag[1] == false && flag[2] == false)
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
}

//�h���[
void CObjReversibleMain::Draw()
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
				dst.m_top = i * 96.0f+60.0f;
				dst.m_left = j * 96.0f+160.0f;
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
		if (flag[0]==true)
		{
			Font::StrDraw(L"�ŒZ�萔", 20, 200, 32, f);
			Font::StrDraw(L"6��",40 , 260, 32, f);
			
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

		Font::StrDraw(L"Count", 675, 45, 32, f);

		//Count�̒l�𕶎���---------------------------------------
		wchar_t str[128];
		swprintf(str, L"%d", Clear_count);

		if(Clear_count>=10)
			Font::StrDraw(str, 700, 80, 32, f);
		else if(Clear_count<=9)
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

		//GameOver---------------------------------------------------
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

			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 240.0f;
			src.m_bottom = 120.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 240.0f;
			src.m_bottom = 120.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}

}