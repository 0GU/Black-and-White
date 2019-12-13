#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL\Audio.h"
#include "Reversiblefunction.h"

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
	//�X�e�[�W�f�[�^�ǂݍ��ݗp�֐�
	LoadRPStage(StageSlect, *stage, count);

	//�J�E���g���Z�b�g�p�ɏ����J�E���g��ۑ�����
	count[2] = count[1];

	//���Z�b�g�p�z��ɃR�s�[
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));

	//�t���O��������
	bool flag_set[8] =
	{ false,false,false,false,false,false,false,false };
	memcpy(flag, flag_set, sizeof(bool)*(8));


	m_ani_flame = INITIALIZE;
	m_time = INITIALIZE;
	m_ani_flag = false;
	sx = INITIALIZE;
	sy = INITIALIZE;
	lx = INITIALIZE;
	ly = INITIALIZE;

	Save::Open();
	j = 0;
	for (i = 0; i < 3; i++)
	{

		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			++j;
			if (j == 3)
			{
				flag[7] = true;
			}
		}
	}
	j = 0;


		colorchange = 0;
		colorflag = false;
	
	//�t���O��������
		
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;


}

//�A�N�V����
void CObjReversibleMain::Action()
{
	//�}�E�X�̍��W��ǂݍ���
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//�N���b�N�G�t�F�N�g�Ăяo���i�P��̂݁j
	if (mou_call == true)
	{
		CObjMouse*m = new CObjMouse(back);
		Objs::InsertObj(m, OBJ_MOUSE, 2);//��
		mou_call = false;
	}

	//�N���b�N����
	//[0]�̂� true = �����Ă����ԁ@
	//[1]�̂� true = �����Ă��Ȃ����
	//����    true = �����Ă��痣�������
	if (Input::GetMouButtonL() == true)
	{
		c_flag[0] = true;
		c_flag[1] = false;
	}
	if (Input::GetMouButtonL() == false)
	{
		c_flag[1] = true;
	}


	//�����蔻��---------------------------------------------------------------------------------------------------------
	if (HIT_PANEL_LEFT <= x && HIT_PANEL_RIGHT >= x && HIT_PANEL_TOP <= y && HIT_PANEL_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false && c_flag[0] == true && c_flag[1] == true && m_ani_flag == false)
	{
		sy = (y - HIT_PANEL_TOP) / PANEL_SIZE_Y; //�N���b�N����y���W��z��Ŏg����悤�ɒ���
		sx = (x - HIT_PANEL_LEFT) / PANEL_SIZE_X; //�N���b�N����x���W��z��Ŏg����悤�ɒ���
		for (int m = 0; m < 5; m++)
		{
			ReversibleProcess(sx, sy, &lx, &ly, m, stage);

			//���]�����̏���
			if (lx >= ARRAY_SIZE_LEFT && ly >= ARRAY_SIZE_TOP && lx <= ARRAY_SIZE_RIGHT && ly <= ARRAY_SIZE_BOTTOM)
			{
				//���]���������l�ɕύX����
				if (stage[ly][lx] == WHITE_PANEL)
				{
					stage[ly][lx] = WHITE_PANEL_REVERSAL;
				}
				else if (stage[ly][lx] == BLACK_PANEL)
				{
					stage[ly][lx] = BLACK_PANEL_REVERSAL;
				}
			}
		}
		m_ani_flag = true;	//���]���͂ق��̃p�l���𔽓]�ł��Ȃ��悤�ɂ���

		//SE��炷
		Audio::Start(1);
		//Count�����炷
		count[1]--;
	}
	//���]�A�j���[�V��������------------------------------
	if (flag[4] == false)
	{
		time_flag = true;//���[�v���P�񂾂��^�C���𑝂₷

		for (int m = 0; m < 5; m++)
		{
			ReversibleProcess(sx, sy, &lx, &ly, m, stage);

			if (lx >= ARRAY_SIZE_LEFT && ly >= ARRAY_SIZE_TOP && lx <= ARRAY_SIZE_RIGHT && ly <= ARRAY_SIZE_BOTTOM)
			{
				if (stage[ly][lx] == WHITE_PANEL_REVERSAL)//���]���p�l��
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
						stage[ly][lx] = BLACK_PANEL;
					}

				}
				if (stage[ly][lx] == BLACK_PANEL_REVERSAL)//���]���p�l��
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
						stage[ly][lx] = WHITE_PANEL;
					}

				}

			}

		}
	}

	//���]�I������
	if (m_ani_flame == 8)
	{
		m_ani_flame = INITIALIZE;	//������
		m_ani_flag = false;	//�p�l���𓮂�����悤�ɂ���

		if (ReversibleClearCheck(stage) == true)	//�N���A�����𖞂�����
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
		else if (ReversibleClearCheck(stage) == false && count[1] == 0 && m_ani_flag == false)	//�Q�[���I�[�o�[�����𖞂�����
		{
			flag[2] = true;
			Audio::Start(2);
		}
	}


	//Perfect�t���O�̊Ǘ�
	Save::Seve();
	if (flag[1] == true && flag[4] == true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->RPerfectFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->RPerfectFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->RPerfectFlag[2] = true;
			break;
		}
		(UserData*)Save::Seve;

	}
	//Clear�t���O�̊Ǘ�
	if (flag[1] == true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->RClearFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->RClearFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->RClearFlag[2] = true;
			break;
		}
		(UserData*)Save::Seve;
	}
	
	//GameClear���̔���-----------------------------------------------------------------------------------------------
	if (flag[1] == true)
	{
		//BGM��~
		Audio::Stop(0);
		CObjReversibleMain::Reverse();
		//StageSelect�֖߂�{�^������
		if (x >= STAGE_SELECT_LEFT && x <= STAGE_SELECT_RIGHT && y >= STAGE_SELECT_TOP && y <= STAGE_SELECT_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Sleep(300);
			Save::Open();
			for (i = 0; i < 3; i++)
			{

				if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
				{
					++j;
					if (j == 3)
					{
						flag[6] = true;
					}
				}
			}

			if (flag[6] == true && flag[7] == false)
			{
				Scene::SetScene(new CSceneGalleryadd());
			}
			else if (flag[6] == false || flag[7] == true)
			{
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
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//BGM�čĐ�
			Audio::Start(0);
			//SE��炷
			Audio::Start(1);
			flag[2] = false;
			c_flag[0] = false;
		}
		//No�{�^������
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Scene::SetScene(new CSceneReversibleSelect());
			flag[2] = false;
		}

	}

	//���Z�b�g�{�^�������蔻��-------------------------------------------------------------
	if (RESET_BUTTON_LEFT <= x && RESET_BUTTON_RIGHT >= x && RESET_BUTTON_TOP <= y && RESET_BUTTON_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false && m_ani_flame == 0 &&
		c_flag[0] == true && c_flag[1] == true)
	{
		count[1] = count[2];
		memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
		//SE��炷
		Audio::Start(6);
	}

	//�q���g�{�^�������蔻��----------------------------------------------------------------
	if (HINT_BUTTON_LEFT <= x && HINT_BUTTON_RIGHT >= x && HINT_BUTTON_TOP <= y && HINT_BUTTON_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false &&
		c_flag[0] == true && c_flag[1] == true)
	{
		flag[0] = true;
		//SE��炷
		Audio::Start(5);
		c_flag[0] = false;
	}

	//StageSelect�֖߂�{�^������------------------------------------------------------------
	if (x >= SELECT_BUTTON_LEFT && x <= SELECT_BUTTON_RIGHT && y >= SELECT_BUTTON_TOP && y <= SELECT_BUTTON_BOTTOM &&
		flag[1] == false && flag[2] == false && c_flag[0] == true && c_flag[1] == true)
	{
		flag[3] = true;
		//SE��炷
		Audio::Start(1);
		c_flag[0] = false;
	}
	if (flag[3] == true)
	{
		//Yes�{�^������
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Stop(1);
			Audio::Start(1);
			Sleep(300);

			Scene::SetScene(new CSceneReversibleSelect());
		}
		//No�{�^������
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			c_flag[0] = false;
			flag[3] = false;
		}
	}


	//�{�^���ނ��Ȃ��A�������͓��삪�I������牟���Ă��Ȃ���Ԃɖ߂�
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
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
	float   cchange[4] = { colorchange,0.0f,0.0f,1.0f };//�e�L�X�g�p

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�w�i�\��
	src.m_top = SRC_BACKGROUND_TOP;
	src.m_left = SRC_BACKGROUND_LEFT;
	src.m_right = SRC_BACKGROUND_RIGHT;
	src.m_bottom = SRC_BACKGROUND_BOTTOM;
	dst.m_top = DST_BACKGROUND_TOP;
	dst.m_left = DST_BACKGROUND_LEFT;
	dst.m_right = DST_BACKGROUND_RIGHT;
	dst.m_bottom = DST_BACKGROUND_BOTTOM;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//stage�̕`��--------------------------------------------------
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str1[128];
	swprintf_s(str1, L"STAGE%d", StageSlect);
	Font::StrDraw(str1, 30, 470, 36, f);
	Font::StrDraw(L"�S�Ẵp�l�������F�ɕς���I", 180, 25, 32, f);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			//�\���ʒu�̐ݒ�
			dst.m_top = i * PANEL_SIZE_Y + HIT_PANEL_TOP - PANEL_POSITION_CORRECTION;
			dst.m_left = j * PANEL_SIZE_X + HIT_PANEL_LEFT;
			dst.m_right = dst.m_left + ANIMATIONPANEL_SIZE_X;
			dst.m_bottom = dst.m_top + ANIMATIONPANEL_SIZE_Y;
			if (stage[i][j] == WHITE_PANEL)
			{
				src.m_top = POSITION_WHITE;
				src.m_left = PANEL_TOP;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//���p�l��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL)
			{
				src.m_top = PANEL_TOP;
				src.m_left = PANEL_TOP;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//���p�l��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			if (stage[i][j] == WHITE_PANEL_REVERSAL)
			{
				src.m_top = POSITION_WHITE - (AniData[m_ani_flame] / 4)*ANIMATIONPANEL_SIZE_Y;
				src.m_left = ANIMATIONPANEL_SIZE_X + (AniData[m_ani_flame] % 4) * ANIMATIONPANEL_SIZE_X;
				src.m_right = src.m_left - ANIMATIONPANEL_SIZE_X;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//���]���p�l��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL_REVERSAL)
			{
				src.m_top = PANEL_TOP + (AniData[m_ani_flame] / 4)*ANIMATIONPANEL_SIZE_Y;
				src.m_left = PANEL_LEFT + (AniData[m_ani_flame] % 4) * ANIMATIONPANEL_SIZE_X;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//���]���p�l��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}

		}
	}
	//�q���g�{�^��-----------------------------------------------
	//�؂���
	src.m_top = SRC_HINT_TOP;
	src.m_left = SRC_HINT_LEFT;
	src.m_right = SRC_HINT_RIGHT;
	src.m_bottom = SRC_HINT_BOTTOM;
	//�\��
	//�v���O�����̖���x�l��10f,y�l��5f���炵�Ă܂�
	dst.m_top = HINT_BUTTON_TOP + POSITION_CORRECTION_HEIGHT;
	dst.m_left = HINT_BUTTON_LEFT + POSITION_CORRECTION_WIDTH;
	dst.m_right = HINT_BUTTON_RIGHT + POSITION_CORRECTION_WIDTH;
	dst.m_bottom = HINT_BUTTON_BOTTOM + POSITION_CORRECTION_HEIGHT;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�q���g�̕\��
	if (flag[0] == true)
	{
		if (StageSlect == 1)
		{
			Font::StrDraw(L"�܂��̓p�l��", 15, 260, 24, f);
			Font::StrDraw(L"���N���b�N�I", 15, 300, 24, f);
		}
		else if (StageSlect == 2)
		{
			Font::StrDraw(L"�܂��̓p�l��", 15, 260, 24, f);
			Font::StrDraw(L"���N���b�N�I", 15, 300, 24, f);
		}
		else if (StageSlect == 3)
		{
			wchar_t str2[128];
			Font::StrDraw(L"�ŒZ�萔", 20, 260, 32, f);
			swprintf_s(str2, L"%d��", count[0]);


			Font::StrDraw(str2, 40, 320, 32, f);

		}

	}

	//���Z�b�g�{�^��--------------------------------------------
	//�؂���
	src.m_top = SRC_RESET_TOP;
	src.m_left = SRC_RESET_LEFT;
	src.m_right = SRC_RESET_RIGHT;
	src.m_bottom = SRC_RESET_BOTTOM;
	//�\��
	//�v���O�����̖���x�l10f,y�l5f���炵�Ă��܂�
	dst.m_top = RESET_BUTTON_TOP + POSITION_CORRECTION_HEIGHT;
	dst.m_left = RESET_BUTTON_LEFT + POSITION_CORRECTION_WIDTH;
	dst.m_right = RESET_BUTTON_RIGHT + POSITION_CORRECTION_WIDTH;
	dst.m_bottom = RESET_BUTTON_BOTTOM + POSITION_CORRECTION_HEIGHT;
	Draw::Draw(4, &src, &dst, c, 0.0f);

	//StageSelect�{�^��-----------------------------------------------
	//�؂���
	src.m_top = SRC_SELECT_TOP;
	src.m_left = SRC_SELECT_LEFT;
	src.m_right = SRC_SELECT_RIGHT;
	src.m_bottom = SRC_SELECT_BOTTOM;
	//�\��
	dst.m_top = SELECT_BUTTON_TOP;
	dst.m_left = SELECT_BUTTON_LEFT;
	dst.m_right = SELECT_BUTTON_RIGHT;
	dst.m_bottom = SELECT_BUTTON_BOTTOM;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//Count�̕����\��----------------------------------------------
	Font::StrDraw(L"Count", 675, 45, 32, f);

	//Count�̒l�𕶎���---------------------------------------
	wchar_t str3[128];
	swprintf_s(str3, L"%d", count[1]);

	if (count[1] >= 10)
		Font::StrDraw(str3, 700, 80, 32, f);
	else if (count[1] <= 9)
		Font::StrDraw(str3, 710, 80, 32, f);
	//�V�[���`��:Perfect!---------------------------------------

	if (flag[4] == true)
	{

		//Perfect
		src.m_top = SRC_PERFECT_TOP;
		src.m_left = SRC_PERFECT_LEFT;
		src.m_right = SRC_PERFECT_RIGHT;
		src.m_bottom = SRC_PERFECT_BOTTOM;
		dst.m_top = DST_PERFECT_TOP;
		dst.m_left = DST_PERFECT_LEFT;
		dst.m_right = DST_PERFECT_RIGHT;
		dst.m_bottom = DST_PERFECT_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 30.0f);
		//StageSelect�֖߂�
		src.m_top = SRC_STAGE_SELECT_TOP;
		src.m_left = SRC_STAGE_SELECT_LEFT;
		src.m_right = SRC_STAGE_SELECT_RIGHT;
		src.m_bottom = SRC_STAGE_SELECT_BOTTOM;
		dst.m_top = STAGE_SELECT_TOP + 5;
		dst.m_left = STAGE_SELECT_LEFT;
		dst.m_right = STAGE_SELECT_RIGHT;
		dst.m_bottom = STAGE_SELECT_BOTTOM + 5;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}
	//�V�[���`��FGameClear!------------------------------------
	else if (flag[1] == true)
	{

		//GameClear
		src.m_top = SRC_CLERE_TOP;
		src.m_left = SRC_CLERE_LEFT;
		src.m_right = SRC_CLERE_RIGHT;
		src.m_bottom = SRC_CLERE_BOTTOM;
		dst.m_top = DST_CLERE_TOP;
		dst.m_left = DST_CLERE_LEFT;
		dst.m_right = DST_CLERE_RIGHT;
		dst.m_bottom = DST_CLERE_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//StageSelect�֖߂�
		src.m_top = SRC_STAGE_SELECT_TOP;
		src.m_left = SRC_STAGE_SELECT_LEFT;
		src.m_right = SRC_STAGE_SELECT_RIGHT;
		src.m_bottom = SRC_STAGE_SELECT_BOTTOM;
		dst.m_top = STAGE_SELECT_TOP;
		dst.m_left = STAGE_SELECT_LEFT;
		dst.m_right = STAGE_SELECT_RIGHT;
		dst.m_bottom = STAGE_SELECT_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}

	//GameOver---------------------------------------------------
	if (flag[2] == true)
	{
		//GameOver�\��
		src.m_top = SRC_GAMEOVER_TOP;
		src.m_left = SRC_GAMEOVER_LEFT;
		src.m_right = SRC_GAMEOVER_RIGHT;
		src.m_bottom = SRC_GAMEOVER_BOTTOM;
		dst.m_top = DST_GAMEOVER_TOP;
		dst.m_left = DST_GAMEOVER_LEFT;
		dst.m_right = DST_GAMEOVER_RIGHT;
		dst.m_bottom = DST_GAMEOVER_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//Yes�ENo�{�^���̕`��
	if (flag[2] == true || flag[3] == true)
	{
		//Yes
		src.m_top = SRC_YES_TOP;
		src.m_left = SRC_YES_LEFT;
		src.m_right = SRC_YES_RIGHT;
		src.m_bottom = SRC_YES_BOTTOM;
		dst.m_top = YES_BUTTON_TOP;
		dst.m_left = YES_BUTTON_LEFT;
		dst.m_right = YES_BUTTON_RIGHT;
		dst.m_bottom = YES_BUTTON_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//NO
		src.m_top = SRC_NO_TOP;
		src.m_left = SRC_NO_LEFT;
		src.m_right = SRC_NO_RIGHT;
		src.m_bottom = SRC_NO_BOTTOM;
		dst.m_top = NO_BUTTON_TOP;
		dst.m_left = NO_BUTTON_LEFT;
		dst.m_right = NO_BUTTON_RIGHT;
		dst.m_bottom = NO_BUTTON_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}
	//�X�e�[�W�ɖ߂�܂����H�̕`��
	if (flag[3] == true)
	{
		src.m_top = SRC_RETURNSELECT_TOP;
		src.m_left = SRC_RETURNSELECT_LEFT;
		src.m_right = SRC_RETURNSELECT_RIGHT;
		src.m_bottom = SRC_RETURNSELECT_BOTTOM;
		dst.m_top = DST_RETURNSELECT_TOP;
		dst.m_left = DST_RETURNSELECT_LEFT;
		dst.m_right = DST_RETURNSELECT_RIGHT;
		dst.m_bottom = DST_RETURNSELECT_BOTTOM;
		Draw::Draw(7, &src, &dst, c, 0.0f);

	}


}

void CObjReversibleMain::Reverse() //Perfect�N���A���Ƀp�l������]����������
{
	if (flag[4] == true)
	{
		if (flag[5] == false)
		{
			LoadRPStage(99, *stage, count);
			flag[5] = true;
		}
		time_flag = true;//���[�v���P�񂾂��^�C���𑝂₷

		for (int m = 0; m < 5; m++)
		{
			for (int i = 0; i < 5; i++)
			{




				if (stage[m][i] == WHITE_PANEL_REVERSAL)//���]���p�l��
				{
					//�^�C���𑝂₷�i���[�v���P��̂݁j
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//�A�j���[�V�����𓮂���
					if (m_time == 1) {
						m_ani_flame++;
						m_time = 0;
					}
					//�A�j���[�V�������I�������獕�p�l���ɕύX
					if (m_ani_flame == 8)
					{
						stage[m][i] = BLACK_PANEL_REVERSAL;
					}

				}
				else if (stage[m][i] == BLACK_PANEL_REVERSAL)//���]���p�l��
				{
					//�^�C���𑝂₷�i���[�v���P��̂݁j
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//�A�j���[�V�����𓮂���
					if (m_time == 1) {
						m_ani_flame++;
						m_time = 0;
					}
					//�A�j���[�V�������I�������甒�p�l���ɕύX
					if (m_ani_flame == 8)
					{
						stage[m][i] = WHITE_PANEL_REVERSAL;
					}

				}
			}


		}

		//���]�I������
		if (m_ani_flame == 8)
		{
			m_ani_flame = INITIALIZE;	//������
		}
	}

}
//