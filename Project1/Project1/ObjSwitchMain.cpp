#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjSwitchMain.h"
#include "GameL\Audio.h"
#include "Switchfunction.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjSwitchMain::CObjSwitchMain(int stage)
{
	StageSlect = stage;
}

//�C�j�V�����C�Y
void CObjSwitchMain::Init()
{
	LoadSPStage(StageSlect, *stage,count);
	count[2] = count[1];
	//�}�b�v�f�[�^���R�s�[
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));

	bool flag_set[6] =
	{ false,false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(6));
	   	
	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
	r = 0.0f;

}

//�A�N�V����
void CObjSwitchMain::Action()
{
	int lx = 0;
	int ly = 0;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//�����蔻��
	if (PUZZLE_POS_L <= x && PUZZLE_POS_L + PUZZLE_SIZE >= x && PUZZLE_POS_T <= y && PUZZLE_POS_T + PUZZLE_SIZE >= y &&
		((((int)(y - PUZZLE_POS_T) / PANEL_SIZE) % 2 == 0 && ((int)(x - PUZZLE_POS_L) / PANEL_SIZE) % 2 == 1) ||
		 (((int)(y - PUZZLE_POS_T) / PANEL_SIZE) % 2 == 1 && ((int)(x - PUZZLE_POS_L) / PANEL_SIZE) % 2 == 0))
		&& flag[1] == false && flag[2] == false && flag[3] == false)
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

				sy = (int)(y - PUZZLE_POS_T) / PANEL_SIZE;   //�N���b�N����y���W��z��Ŏg����悤�ɒ���
				sx = (int)(x - PUZZLE_POS_L) / PANEL_SIZE;  //�N���b�N����x���W��z��Ŏg����悤�ɒ���
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
						case 0://��
							ly = sy - 1;
							lx = sx;
							break;

						case 1://��
							ly = sy + 1;
							lx = sx;
							break;
						}
						break;
					}
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)//����̐��퉻
					{
						if (stage[ly][lx] == WHITE_PANEL_ID)
						{
							stage[ly][lx] = CH_WHITE_PANEL_ID;
						}
						else if (stage[ly][lx] == BLACK_PANEL_ID)
						{
							stage[ly][lx] = CH_BLACK_PANEL_ID;
						}
					}

				}
				while (Input::GetMouButtonL() == true)
				{

				}


			}
		}
	}
	//�A�j���[�V��������-----

	time_flag = true;//���[�v���P�񂾂��^�C���𑝂₷

	for (int m = 0; m < 2; m++)
	{
		switch (stage[sy][sx])
		{
		case 2://���E�{�^��
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
		case 3://�㉺�{�^��
			switch (m)
			{
			case 0://��
				ly = sy - 1;
				lx = sx;
				break;

			case 1://��
				ly = sy + 1;
				lx = sx;
				break;
			}
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[ly][lx] == CH_WHITE_PANEL_ID)	//�ω������p�l��
			{
				//�^�C���𑝂₷�i���[�v���P��̂݁j
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == M_TIME_MAX) 
				{
					m_ani_flame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������獕�p�l���ɕύX
				if (m_ani_flame == M_ANI_FRAME_MAX)
				{
					stage[ly][lx] = BLACK_PANEL_ID;
				}
			}
			if (stage[ly][lx] == CH_BLACK_PANEL_ID)	//�ω������p�l��
			{
				//�^�C���𑝂₷�i���[�v�����̂݁j
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == M_TIME_MAX)
				{
					m_ani_flame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������甒�p�l���ɕύX
				if (m_ani_flame == M_ANI_FRAME_MAX)
				{
					stage[ly][lx] = WHITE_PANEL_ID;
				}
			}
		}
	}
	//���]�I������
	if (m_ani_flame == M_ANI_FRAME_MAX)
	{
		m_ani_flame = 0;	//������
		m_change = true;	//�p�l���𓮂�����悤�ɂ���

		if (SwitchClearCheck(stage) == true)	//�N���A�����𖞂�����
		{
			//�p�[�t�F�N�g�����𖞂����Ă���
			if (count[2] - count[0] == count[1])
			{
				flag[4] = true;
				Audio::Start(4);
			}
			flag[1] = true;
			if (flag[4] == false)
			{
				Audio::Start(3);
			}
		}
		else if (SwitchClearCheck(stage) == false && count[1] == 0)		//�Q�[���I�[�o�[�����𖞂�����
		{
			flag[2] = true;
			Audio::Start(2);
		}
	}

	//GameClear���̔���
	if (flag[1] == true)
	{
		//BGM��~
		Audio::Stop(0);

		//StageSELECT�֖߂�{�^������
		if (x >= CLEARBACK_POS_L && x <= CLEARBACK_POS_R && y >= CLEARBACK_POS_T && y <= CLEARBACK_POS_B)
		{
			if (Input::GetMouButtonL() == true)
			{

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
		if (x >= YES_BUTTON_POS_L && x <= YES_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = COUNT;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM��~
				Audio::Start(0);
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				flag[2] = false;
				Audio::Start(0);
			}

		}
		//No�{�^������
		if (x >= NO_BUTTON_POS_L && x <= NO_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B)
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
	if (HIN_RESE_BUTTON_POS_L <= x && HIN_RESE_BUTTON_POS_L + BUTTON_SIZE_X >= x &&
		RESET_BUTTON_POS_T	  <= y && RESET_BUTTON_POS_T    + BUTTON_SIZE_Y >= y &&
		flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = COUNT;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SE��炷
			Audio::Start(6);
			m_change = true;
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//�q���g�{�^�������蔻��
	if (HIN_RESE_BUTTON_POS_L <= x && HIN_RESE_BUTTON_POS_L + BUTTON_SIZE_X >= x &&
		HINT_BUTTON_POS_T	  <= y && HINT_BUTTON_POS_T	    + BUTTON_SIZE_Y >= y &&
		flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{

			flag[0] = true;
			//SE��炷
			Audio::Start(5);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
	//StageSelect�֖߂�{�^������------------------------------------------------------------
	if (x >= STAGESELE_BUTTON_POS_L && x <= STAGESELE_BUTTON_POS_L + BUTTON_SIZE_X &&
		y >= STAGESELE_BUTTON_POS_T && y <= STAGESELE_BUTTON_POS_T + BUTTON_SIZE_Y &&
		flag[1] == false && flag[2] == false)
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
		if (x >= YES_BUTTON_POS_L	&& x <= YES_BUTTON_POS_R && 
			y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B)
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
		if (x >= NO_BUTTON_POS_L	&& x <= NO_BUTTON_POS_R && 
			y >= YESNO_BUTTON_POS_T	&& y <= YESNO_BUTTON_POS_B)
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

	//Perfect�t���O�̊Ǘ�
	Save::Seve();
	if (flag[1] == true && count[1] == count[0])
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->SPerfectFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->SPerfectFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->SPerfectFlag[2] = true;
			break;
		}
	}
	//Clear�t���O�̊Ǘ�
	if (flag[1] == true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->SClearFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->SClearFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->SClearFlag[2] = true;
			break;
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
	src.m_top   = CUT_BACKGROUND_T;
	src.m_left  = CUT_BACKGROUND_L;
	src.m_right = CUT_BACKGROUND_R;
	src.m_bottom= CUT_BACKGROUND_B;
	dst.m_top   = 0.0f;
	dst.m_left  = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom= WINDOW_SIZE_Y;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//stage�̕`��
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };

	switch (StageSlect)
	{
	case 1:
		Font::StrDraw(L"STAGE1", NOW_STAGE_POS_X, NOW_STAGE_POS_Y, NOW_STAGE_SIZE, f);
		break;
	case 2:
		Font::StrDraw(L"STAGE2", NOW_STAGE_POS_X, NOW_STAGE_POS_Y, NOW_STAGE_SIZE, f);
		break;
	case 3:
		Font::StrDraw(L"STAGE3", NOW_STAGE_POS_X, NOW_STAGE_POS_Y, NOW_STAGE_SIZE, f);
		break;

	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//�㉺���E�ŃA�j���[�V�����̊p�x��ς�����
			if (sy == i - 1 && sx == j)
			{
				r = CHANGE_ANI_R_T;
			}
			else if (sy == i && sx == j - 1)
			{
				r = CHANGE_ANI_R_L;
			}
			else if (sy == i && sx == j + 1)
			{
				r = CHANGE_ANI_R_R;
			}
			else if (sy == i + 1 && sx == j)
			{
				r = CHANGE_ANI_R_B;
			}


			//�؂���ʒu�̐ݒ�
			src.m_top   = 0.0f;
			src.m_left  = 0.0f;
			src.m_right = src.m_left+PANEL_SIZE;
			src.m_bottom= src.m_top+PANEL_SIZE;

			//�\���ʒu�̐ݒ�
			dst.m_top   = i * PANEL_SIZE + PUZZLE_POS_T;
			dst.m_left  = j * PANEL_SIZE + PUZZLE_POS_L;
			dst.m_right = dst.m_left + PANEL_SIZE;
			dst.m_bottom= dst.m_top  + PANEL_SIZE;
			if (stage[i][j] == WHITE_PANEL_ID)
			{
				//���p�l��
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL_ID)
			{
				//���p�l��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == UP_DOWN_SWIT_ID)
			{
				//�c�X�C�b�`
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == LEF_RIG_SWIT_ID)
			{
				//���X�C�b�`
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == CH_WHITE_PANEL_ID)
			{
				//�ω������p�l��
				src.m_top   = 0.0f;
				src.m_left  = 0.0f + (m_ani_flame * PANEL_SIZE);
				src.m_right = src.m_left + PANEL_SIZE;
				src.m_bottom= src.m_top  + PANEL_SIZE;

				Draw::Draw(8, &src, &dst, c, r);
			}
			else if (stage[i][j] == CH_BLACK_PANEL_ID)
			{
				//�ω������p�l��
				src.m_top   = 96.0f;
				src.m_left  = 0.0f + (m_ani_flame * PANEL_SIZE);
				src.m_right = src.m_left + PANEL_SIZE;
				src.m_bottom= src.m_top  + PANEL_SIZE;

				Draw::Draw(8, &src, &dst, c, r);
			}
		}
	}
	//�q���g�{�^��-----------------------------------------------
	//�؂���
	src.m_top   = CUT_HIN_RESE_BUTTON_T;
	src.m_left  = CUT_HIN_RESE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom= src.m_top  + BUTTON_SIZE_Y;
	//�\��
	//�v���O�����̖���x�l��10f���炵�Ă܂�
	dst.m_top   = HINT_BUTTON_POS_T;
	dst.m_left  = HIN_RESE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom= dst.m_top  + BUTTON_SIZE_Y;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�q���g�̕\��
	if (flag[0] == true)
	{
		Font::StrDraw(L"�ŒZ�萔", HIN_TEXT_POS_X_1, HIN_TEXT_POS_Y_1, HIN_TEXT_SIZE, f);
		Font::StrDraw(L"6��"	 , HIN_TEXT_POS_X_2, HIN_TEXT_POS_Y_2, HIN_TEXT_SIZE, f);
	}

	//���Z�b�g�{�^��--------------------------------------------
	//�؂���
	src.m_top   = CUT_HIN_RESE_BUTTON_T;
	src.m_left  = CUT_HIN_RESE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom= src.m_top  + BUTTON_SIZE_Y;
	//�\��
	//�v���O�����̖���x�ly�l10f���炵�Ă��܂�
	dst.m_top   = RESET_BUTTON_POS_T;
	dst.m_left  = HIN_RESE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom= dst.m_top  + BUTTON_SIZE_Y;
	Draw::Draw(4, &src, &dst, c, 0.0f);

	//StageSelect�{�^��-----------------------------------------------
	src.m_top   = CUT_SELE_BUTTON_T;
	src.m_left  = CUT_SELE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom= src.m_top  + BUTTON_SIZE_Y;
	//�v���O�����̖���x�l��10f���炵�Ă܂�
	dst.m_top   = STAGESELE_BUTTON_POS_T;
	dst.m_left  = STAGESELE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom= dst.m_top  + BUTTON_SIZE_Y;
	Draw::Draw(5, &src, &dst, c, 0.0f);


	Font::StrDraw(L"Count", CNT_TEXT_POS_X, CNT_TEXT_POS_Y, CNT_SIZE, f);

	//Count�̒l�𕶎���---------------------------------------
	wchar_t str[128];
	swprintf_s(str, L"%d", count[1]);

	if (count[1] >= 10)
		Font::StrDraw(str, CNT_NUM_MANY_POS_X, CNT_NUM_POS_Y, CNT_SIZE, f);
	else if (count[1] <= 9)
		Font::StrDraw(str, CNT_NUM_FEW_POS_X, CNT_NUM_POS_Y, CNT_SIZE, f);
	//�V�[���`��FPerFect!------------------------------------
	if (flag[4] == true)
	{
		//PerFect!
		src.m_top   = CUT_PERFECT_T;
		src.m_left  = CUT_PERFECT_L;
		src.m_right = CUT_PERFECT_R;
		src.m_bottom= CUT_PERFECT_B;
		dst.m_top   = PERFECT_TEXT_POS_T;
		dst.m_left  = PERFECT_TEXT_POS_L;
		dst.m_right = PERFECT_TEXT_POS_R;
		dst.m_bottom= PERFECT_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 30.0f);
		//�X�e�[�W�I���ɖ߂�
		src.m_top   = CUT_CLEARBACK_T;
		src.m_left  = CUT_CLEARBACK_L;
		src.m_right = CUT_CLEARBACK_R;
		src.m_bottom= CUT_CLEARBACK_B;
		dst.m_top   = CLEARBACK_POS_T;
		dst.m_left  = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom= CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//GameClear------------------------------------------
	else if (flag[1] == true)
	{
		//Game Clear!!
		src.m_top   = CUT_GAMECLEAR_T;
		src.m_left  = CUT_GAMECLEAR_L;
		src.m_right = CUT_GAMECLEAR_R;
		src.m_bottom= CUT_GAMECLEAR_B;
		dst.m_top   = GAMECLEAR_TEXT_POS_T;
		dst.m_left  = GAMECLEAR_TEXT_POS_L;
		dst.m_right = GAMECLEAR_TEXT_POS_R;
		dst.m_bottom= GAMECLEAR_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//�X�e�[�W�I���ɖ߂�
		src.m_top   = CUT_CLEARBACK_T;
		src.m_left  = CUT_CLEARBACK_L;
		src.m_right = CUT_CLEARBACK_R;
		src.m_bottom= CUT_CLEARBACK_B;
		dst.m_top   = CLEARBACK_POS_T;
		dst.m_left  = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom= CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//GameOver------------------------------------
	if (flag[2] == true)
	{
		//GameOver�\��
		src.m_top   = CUT_GAMEOVER_T;
		src.m_left  = CUT_GAMEOVER_L;
		src.m_right = CUT_GAMEOVER_R;
		src.m_bottom= CUT_GAMEOVER_B;
		dst.m_top   = GAMEOVER_TEXT_POS_T;
		dst.m_left  = GAMEOVER_TEXT_POS_L;
		dst.m_right = GAMEOVER_TEXT_POS_R;
		dst.m_bottom= GAMEOVER_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
		//Yes�ENo�{�^���A�X�e�[�W�ɖ߂�܂����H�̕`��
		if (flag[2] == true || flag[3] == true)
		{
			//Yes�{�^��
			src.m_top   = CUT_YESNO_BUTTON_T;
			src.m_left  = CUT_YES_BUTTON_L;
			src.m_right = CUT_YES_BUTTON_R;
			src.m_bottom= CUT_YESNO_BUTTON_B;
			dst.m_top   = YESNO_BUTTON_POS_T;
			dst.m_left  = YES_BUTTON_POS_L;
			dst.m_right = YES_BUTTON_POS_R;
			dst.m_bottom= YESNO_BUTTON_POS_B;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			//No�{�^��
			src.m_left  = CUT_NO_BUTTON_L;
			src.m_right = CUT_NO_BUTTON_R;
			dst.m_left  = NO_BUTTON_POS_L;
			dst.m_right = NO_BUTTON_POS_R;
			Draw::Draw(5, &src, &dst, c, 0.0f);			
		}
		//�X�e�[�W�ɖ߂�܂����H�̕`��
		if (flag[3] == true)
		{
			src.m_top   = CUT_BACKSELECT_T;
			src.m_left  = CUT_BACKSELECT_L;
			src.m_right = CUT_BACKSELECT_R;
			src.m_bottom= CUT_BACKSELECT_B;
			dst.m_top   = BACKSELE_TEXT_POS_T;
			dst.m_left  = BACKSELE_TEXT_POS_L;
			dst.m_right = BACKSELE_TEXT_POS_R;
			dst.m_bottom= BACKSELE_TEXT_POS_B;
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
}