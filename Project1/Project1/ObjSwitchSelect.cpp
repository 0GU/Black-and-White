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
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;

	bool set_Pflag[6] = { false, false ,false ,false,false,false };
	bool set_Cflag[6] = { false, false ,false,false,false,false };

	Save::Open();

	for (int i = 0; i < 6; i++)
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
	//�t���O��������
	memcpy(Pflag, set_Pflag, sizeof(bool)*(6));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(6));
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;

	back = false;
	mou_call = true;

	Rright = 1;
	Rleft = 0;
}

//�A�N�V����
void CObjSwitchSelect::Action()
{
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

	if (Cflag[2] == true)
	{
		if (Rright == 1)
		{

			//�E���
			if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y &&
				c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
			{
				Audio::Start(1);
				scroll_flag = true;
				c_flag[0] = true;
			}
			//�X�N���[������------
			if (scroll_flag == true)
			{
				//��������scrool������������
				speed += -SCROLL_SPEED;
				m_scroll += speed;
				//scroll��800����������800�ɂȂ����Aspeed������������
				if (m_scroll <= (-SCROLL_DISTANCE))
				{
					m_scroll = (-SCROLL_DISTANCE);
					speed = 0.0f;
				}
			}
			//�X�N���[���I������-----
			//�E���������č�����\��������
			if (m_scroll == -SCROLL_DISTANCE)
			{
				scroll_flag = false;
				Rright = 0;
				Rleft = 1;
				Rflag = false;
			}
		}
	}

	if (Rleft == 1)
	{
		//�����
		if (HIT_LEFTARROW_LEFT <= x && HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y &&
			c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
		{
			Audio::Start(1);
			scroll_flag = true;	//�X�N���[�����ɂ���
			c_flag[0] = true;
		}
		//�X�N���[������------
		if (scroll_flag == true)
		{
			//��������scrool������������
			speed += SCROLL_SPEED;
			m_scroll += speed;
			//scroll���O�����������O�ɂȂ����Aspeed������������
			if (m_scroll >= 0.0f)
			{
				m_scroll = 0.0f;
				speed = 0.0f;
			}
		}
		//�X�N���[���I������-----
		//�����������ĉE����\��������
		if (m_scroll == 0.0f&&scroll_flag == true)
		{
			scroll_flag = false;
			Rleft = 0;
			Rright = 1;
		}


	}

	//right�l���`��ƃY���Ă����ג���
	if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_ONE_T <= y && STAGE_SW_SELECT_ONE_B >= y &&
		c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)//stage1
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SELECT_WAIT);

		Scene::SetScene(new CSceneSwitchMain(1));
	}
	if (Cflag[0] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_TWO_T <= y && STAGE_SW_SELECT_TWO_B >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)//stage2
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneSwitchMain(2));
		}
	}
	if (Cflag[1] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_THREE_T <= y && STAGE_SW_SELECT_THREE_B >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)//stage3
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneSwitchMain(3));
		}
	}
	if (Cflag[2] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_ONE_T <= y && STAGE_SW_SELECT_ONE_B >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)//stage4
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneSwitchMain(4));
		}
	}
	if (Cflag[3] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_TWO_T <= y && STAGE_SW_SELECT_TWO_B >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)//stage5
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneSwitchMain(5));
		}
	}
	if (Cflag[4] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_THREE_T <= y && STAGE_SW_SELECT_THREE_B >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)//stage6
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneSwitchMain(6));
		}
	}
	//�߂�{�^��
	if (BACKBUTTON_POS_L <= x && BACKBUTTON_POS_R >= x && BACKBUTTON_POS_T <= y && BACKBUTTON_POS_B >= y &&
		c_flag[0] == true && c_flag[1] == true)
	{
		//SE��炷
		Audio::Start(2);
		Sleep(SCENEBACK_WAIT);
		Scene::SetScene(new CSceneGameSelect());
	}

	//�w�i�X�N���[��
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B_GAP;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B_GAP;

	//�{�^���ނ��Ȃ��A�������͓��삪�I������牟���Ă��Ȃ���Ԃɖ߂�
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
	}

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
	src.m_top = BACKGROUND_TL;
	src.m_left = BACKGROUND_TL;
	src.m_right = BACKGROUND_R;
	src.m_bottom = BACKGROUND_B;

	dst.m_top = BACKGROUND_TL + m_y1;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�w�i���X�^�[�g
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�X�e�[�W��I��
	src.m_top = CUT_STAGE_T;
	src.m_left = CUT_STAGE_L;
	src.m_right = CUT_STAGE_R;
	src.m_bottom = CUT_STAGE_B;	//542x95
	dst.m_top = POS_STAGE_T;
	dst.m_left = POS_STAGE_L;
	dst.m_right = POS_STAGE_R;
	dst.m_bottom = POS_STAGE_B;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	if (Cflag[2] == true)
	{
		//�E���̕`��-------------------------
		if (Rright == 1 && scroll_flag == false)
		{
			//�E���{�^��
			src.m_top = RIGHT_ARROW_T;
			src.m_left = RIGHT_ARROW_L;
			src.m_right = RIGHT_ARROW_R;
			src.m_bottom = RIGHT_ARROW_B;
			dst.m_top = HIT_RIGHTARROW_TOP;
			dst.m_left = HIT_RIGHTARROW_LEFT;
			dst.m_right = HIT_RIGHTARROW_RIGHT;
			dst.m_bottom = HIT_RIGHTARROW_BOTTOM;
			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
	}
	//�����̕`��------------------------
	if (Rleft == 1 && scroll_flag == false)
	{

		//�����{�^��
		src.m_top = RIGHT_ARROW_T;
		src.m_left = LEFT_ARROW_L;
		src.m_right = LEFT_ARROW_R;
		src.m_bottom = RIGHT_ARROW_B;
		dst.m_top = HIT_LEFTARROW_TOP;
		dst.m_left = HIT_LEFTARROW_LEFT;
		dst.m_right = HIT_LEFTARROW_RIGHT;
		dst.m_bottom = HIT_LEFTARROW_BOTTOM;
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}

	//STAGE1
	src.m_top = RESOURCE_STAGE1_T;
	src.m_left = RESOURCE_STAGE_L;
	src.m_right = RESOURCE_STAGE_R;
	src.m_bottom = RESOURCE_STAGE1_B;
	dst.m_top = STAGE_SW_SELECT_ONE_T;
	dst.m_left = STAGE_SW_SELECT_L + m_scroll;
	dst.m_right = STAGE_SW_SELECT_R_DRAW + m_scroll;
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
	//STAGE4
	if (Cflag[2] == true)
	{
		src.m_top = RESOURCE_STAGE1_T;
		src.m_left = RESOURCE_STAGE_L;
		src.m_right = RESOURCE_STAGE_R;
		src.m_bottom = RESOURCE_STAGE1_B;
		dst.m_top = STAGE_SW_SELECT_ONE_T;
		dst.m_left = STAGE_SW_SELECT_L + SCROLL_DISTANCE + m_scroll;
		dst.m_right = STAGE_SW_SELECT_R_DRAW + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = STAGE_SW_SELECT_ONE_B;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//STAGE5
	if (Cflag[3] == true)
	{
		src.m_top = RESOURCE_STAGE2_T;
		src.m_left = RESOURCE_STAGE_L;
		src.m_right = RESOURCE_STAGE_R;
		src.m_bottom = RESOURCE_STAGE2_B;
		dst.m_top = STAGE_SW_SELECT_TWO_T;
		dst.m_bottom = STAGE_SW_SELECT_TWO_B;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//STAGE6
	if (Cflag[4] == true)
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
	src.m_top = RESOURCE_STAR_T;
	src.m_left = RESOURCE_STAR_L;
	src.m_right = RESOURCE_STAR_R;
	src.m_bottom = RESOURCE_STAR_B;
	dst.m_left = STAGE_SW_STAR_L + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + m_scroll;

	//(1)
	if (Pflag[0] == false && Cflag[0] == true)
	{
		dst.m_top = STAGE_SW_STAR_ONE_T ;
		dst.m_bottom = STAGE_SW_STAR_ONE_B ;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(2)
	if (Pflag[1] == false && Cflag[1] == true)
	{
		dst.m_top = STAGE_SW_STAR_TWO_T ;
		dst.m_bottom = STAGE_SW_STAR_TWO_B ;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(3)
	if (Pflag[2] == false && Cflag[2] == true)
	{
		dst.m_top = STAGE_SW_STAR_THREE_T ;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	dst.m_left = STAGE_SW_STAR_L + SCROLL_DISTANCE + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + SCROLL_DISTANCE + m_scroll;
	//(4)
	if (Pflag[3] == false && Cflag[3] == true)
	{
		dst.m_top = STAGE_SW_STAR_ONE_T ;
		dst.m_bottom = STAGE_SW_STAR_ONE_B ;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(5)
	if (Pflag[4] == false && Cflag[4] == true)
	{
		dst.m_top = STAGE_SW_STAR_TWO_T;
		dst.m_bottom = STAGE_SW_STAR_TWO_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(6)
	if (Pflag[5] == false && Cflag[5] == true)
	{
		dst.m_top = STAGE_SW_STAR_THREE_T;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//�����̕`��---------------------------------------------------------------------------
	//(1)
	src.m_top = RESOURCE_PSTAR_T;
	src.m_left = RESOURCE_PSTAR_L;
	src.m_right = RESOURCE_PSTAR_R;
	src.m_bottom = RESOURCE_PSTAR_B;
	dst.m_left = STAGE_SW_STAR_L + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + m_scroll;

	if (Pflag[0] == true)
	{
		dst.m_top = STAGE_SW_STAR_ONE_T;
		dst.m_bottom = STAGE_SW_STAR_ONE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		dst.m_top = STAGE_SW_STAR_TWO_T;
		dst.m_bottom = STAGE_SW_STAR_TWO_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		dst.m_top = STAGE_SW_STAR_THREE_T;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	dst.m_left = STAGE_SW_STAR_L + SCROLL_DISTANCE + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + SCROLL_DISTANCE + m_scroll;
	//(4)
	if (Pflag[3] == true)
	{
		dst.m_top = STAGE_SW_STAR_ONE_T;
		dst.m_bottom = STAGE_SW_STAR_ONE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(5)
	if (Pflag[4] ==true)
	{
		dst.m_top = STAGE_SW_STAR_TWO_T;
		dst.m_bottom = STAGE_SW_STAR_TWO_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(6)
	if (Pflag[5] == true)
	{
		dst.m_top = STAGE_SW_STAR_THREE_T;
		dst.m_bottom = STAGE_SW_STAR_THREE_B;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}

}