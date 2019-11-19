#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL\Audio.h"
#include "UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjReversibleMain::CObjReversibleMain(int stage)
{
	StageSlect = stage;
}

//�C�j�V�����C�Y
void CObjReversibleMain::Init()
{
	int stage_data[5][5] = {};   //�X�e�[�W�p�z��

	//�X�e�[�W�ǂݍ��ݗp�֐�
	LoadRPStage(StageSlect, *stage_data);
	//�J�E���g�ǂݍ��ݗp�֐�
	LoadRPCount(StageSlect, count);
	//�J�E���g���Z�b�g�p�ɏ����J�E���g��ۑ�����
	count[2] = count[1];

	//�}�b�v�f�[�^���R�s�[
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
	//���Z�b�g�p�z��ɃR�s�[
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));
	
	//�t���O��������
	bool flag_set[5] =
	{ false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(5));

	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
}

//�A�N�V����
void CObjReversibleMain::Action()
{
	int lx, ly;//���]�����p�ϐ�

	//�}�E�X�̍��W��ǂݍ���
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	//�����蔻��---------------------------------------------------------------------------------------------------------
	if (160 <= x && 640 >= x && 60 <= y && 540 >= y && flag[1] == false && flag[2] == false && flag[3] == false)
	{
		if (m_change == true)
		{
			if (Input::GetMouButtonL() == true)    //���N���b�N���p�l���𔽓]������
			{
				m_change = false;	//���]���͂ق��̃p�l���𔽓]�ł��Ȃ��悤�ɂ���

				//SE��炷
				Audio::Start(1);

				//Count�����炷
				count[1]--;

				sx = (y - 60) / 96;   //�N���b�N����y���W��z��Ŏg����悤�ɒ���
				sy = (x - 160) / 96;  //�N���b�N����x���W��z��Ŏg����悤�ɒ���
				for (int m = 0; m < 5; m++)
				{
					switch (m)
					{
					case 0://��
						lx = sx;
						ly = sy - 1;
						break;
					case 1://��
						lx = sx - 1;
						ly = sy;
						break;
					case 2://�N���b�N�����ꏊ
						lx = sx;
						ly = sy;
						break;
					case 3://�E
						lx = sx + 1;
						ly = sy;
						break;
					case 4://��
						lx = sx;
						ly = sy + 1;
						break;
					}
					//���]�����̏���
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
					{
						//���]���������l�ɕύX����
						if (stage[lx][ly] == 0)
						{
							stage[lx][ly] = 2;
						}
						else if (stage[lx][ly] == 1)
						{

							stage[lx][ly] = 3;
						}
					}
				}
				while (Input::GetMouButtonL() == true)
				{

				}
				
			}
		}

	
	
	}
	//���]�A�j���[�V��������------------------------------
	
	time_flag = true;//���[�v���P�񂾂��^�C���𑝂₷

	for (int m = 0; m < 5; m++)
	{
		switch (m)
		{
		case 0://��
			lx = sx;
			ly = sy - 1;
			break;
		case 1://��
			lx = sx - 1;
			ly = sy;
			break;
		case 2:
			lx = sx;
			ly = sy;
			break;
		case 3://�E
			lx = sx + 1;
			ly = sy;
			break;
		case 4://��
			lx = sx;
			ly = sy + 1;
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[lx][ly] == 2)//���]���p�l��
			{
				//�^�C���𑝂₷�i���[�v���P��̂݁j
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == 3) {
					m_ani_flame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������獕�p�l���ɕύX
				if (m_ani_flame == 8)
				{
					stage[lx][ly] = 1;
				}

			}
			if (stage[lx][ly] == 3)//���]���p�l��
			{
				//�^�C���𑝂₷�i���[�v���P��̂݁j
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == 3) {
					m_ani_flame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������甒�p�l���ɕύX
				if (m_ani_flame == 8)
				{
					stage[lx][ly] = 0;
				}

			}

		}
	}

	//���]�I������
	if (m_ani_flame == 8)
	{
		m_ani_flame = 0;	//������
		m_change = true;	//�p�l���𓮂�����悤�ɂ���

		if (ReversibleClearCheck(stage) == true)	//�N���A�����𖞂�����
		{
			//�p�[�t�F�N�g�����𖞂����Ă���
			if (count[2] - count[0]==count[1])
			{
				flag[4] = true;
			}
			Audio::Start(3);
			flag[1] = true;
		}
		else if (ReversibleClearCheck(stage) == false && count[1] == 0&&m_change==true)	//�Q�[���I�[�o�[�����𖞂�����
		{
			flag[2] = true;
			Audio::Start(2);
		}
	}

	//GameClear���̔���-----------------------------------------------------------------------------------------------
	if (flag[1] == true)
	{
		//BGM��~
		Audio::Stop(0);
		//StageSelect�֖߂�{�^������
		if (x >= 130 && x <= 690 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneReversibleSelect());

			}

		}
	}
	//GameOver���̔���--------------------------------------------------------------------------------------------------
	if (flag[2] == true)
	{
		//BGM��~
		Audio::Stop(0);
		//Yes�{�^������
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = 22;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM�čĐ�
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
				Scene::SetScene(new CSceneReversibleSelect());
				flag[2] = false;
			}
		}

	}

	//���Z�b�g�{�^�������蔻��-------------------------------------------------------------
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y && flag[1] == false && flag[2] == false&& m_ani_flame == 0)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//�q���g�{�^�������蔻��----------------------------------------------------------------
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
		//BGM��~
		Audio::Stop(0);
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
				Scene::SetScene(new CSceneReversibleSelect());
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
void CObjReversibleMain::Draw()
{
	int AniData[8]{
		0,1,2,3,7,6,5,4,
	};
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
	
	//stage�̕`��--------------------------------------------------
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str1[128];
	swprintf_s(str1, L"STAGE%d",StageSlect);
	Font::StrDraw(str1, 30, 470, 36, f);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 96.0f+60.0f-12.0f;
				dst.m_left = j * 96.0f+160.0f;
				dst.m_right = dst.m_left + 96.0;
				dst.m_bottom = dst.m_top + 120.0;
				if (stage[i][j] == 0)
				{
					src.m_top = 120.0;
					src.m_left = 0.0f;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//���p�l��
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				else if (stage[i][j] == 1)
				{
					src.m_top = 0.0f ;
					src.m_left = 0.0f;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//���p�l��
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				if (stage[i][j] == 2)
				{
					src.m_top = 120.0f- (AniData[m_ani_flame]/4)*120;
					src.m_left = 96.0f +( AniData[m_ani_flame]%4) * 96;
					src.m_right = src.m_left-96.0f;
					src.m_bottom = 120.0f + src.m_top;
					//���]���p�l��
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				else if (stage[i][j] == 3)
				{
					src.m_top = 0.0f+ (AniData[m_ani_flame]/4)*120;
					src.m_left = 0.0f +( AniData[m_ani_flame]%4) * 96;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//���]���p�l��
					Draw::Draw(6, &src, &dst, c, 0.0f);
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
			Font::StrDraw(L"�ŒZ�萔", 20, 260, 32, f);

			wchar_t str2[128];
			swprintf_s(str2, L"%d��", count[0]);

			
			Font::StrDraw(str2,40 , 320, 32, f);
			
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

		//Count�̕����\��----------------------------------------------
		Font::StrDraw(L"Count", 675, 45, 32, f);

		//Count�̒l�𕶎���---------------------------------------
		wchar_t str3[128];
		swprintf_s(str3, L"%d", count[1]);

		if(count[1]>=10)
			Font::StrDraw(str3, 700, 80, 32, f);
		else if(count[1]<=9)
			Font::StrDraw(str3, 710, 80, 32, f);
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
		}
		//Yes�ENo�{�^���̕`��
		if (flag[2] == true || flag[3] == true)
		{
			src.m_top = 820.0f;
			src.m_left = 0.0f;
			src.m_right = 239.0f;
			src.m_bottom = 939.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = 820.0f;
			src.m_left = 239.0f;
			src.m_right = 478.0f;
			src.m_bottom = 939.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}
		//Perfect�\��
		if (flag[4] == true)
		{
			Font::StrDraw(L"Perfect!!", 100, 10, 32, f);

		}
}