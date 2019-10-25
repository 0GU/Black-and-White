#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL/Audio.h"


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
	hint = false;

}

//�A�N�V����
void CObjReversibleMain::Action()
{
	int sx=0, sy=0;
	int lx, ly;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	//�����蔻��
	if (160<=x&&640>=x&&60<=y&&540>=y)
	{
		if ( Input::GetMouButtonL()== true)    //���N���b�N���p�l���𔽓]������
		{
			//SE��炷
			Audio::Start(1);

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
		}
	}

	//���Z�b�g�{�^�������蔻��
	if (660 <= x && 780 >= x && 440 <= y && 550 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
	
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//�q���g�{�^�������蔻��
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{

			hint = true;
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

	//�q���g�{�^���\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	dst.m_top = 250.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 120.0f;
	dst.m_bottom = dst.m_top + 100.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);


	//�q���g�e�L�X�g�\��
	Font::StrDraw(L"Hint", 50, 250, 30, f);

	if (hint == true)
		Font::StrDraw(L"AAA", 20,280,30, f);

	//���Z�b�g�{�^���\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	dst.m_top = 440.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 120.0f;
	dst.m_bottom = dst.m_top + 100.0f;
	Draw::Draw(4, &src, &dst, c, 0.0f);

}