//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameHead.h"
#include"ObjModeSelect.h"
#include"windows.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjModeSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;
	C_m_y1 = 0.0f;
	C_m_y2 = 0.0f;

	//�t���O��������
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;
	credit_flag = true;
	help_flag = true;
}

//�A�N�V����
void CObjModeSelect::Action()
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

	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_SELECT <= y && HIT_BOTTOM_SELECT >= y &&
		credit_flag == true && help_flag == true)
	{
		buttom_name = 's';

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGameSelect());
		}
		ButtomCol(c_flag, col_flag);
	}

	else if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_GALLERY <= y && HIT_BOTTOM_GALLERY >= y &&
			 credit_flag == true && help_flag == true)
	{
		buttom_name = 'g';

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGallery());
		}
		ButtomCol(c_flag, col_flag);
	}
	//�N���W�b�g
	else if (POS_CREDITBUTTON_L <= x && POS_CREDITBUTTON_R >= x && POS_CREDITBUTTON_T <= y && POS_CREDITBUTTON_B >= y && credit_flag == true && help_flag == true)
	{
		buttom_name = 'c';

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			credit_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	//�w���v
	else if (120.0f <= x && 220.0f >= x && 480.0f <= y && 580.0f >= y && credit_flag == true && help_flag == true)
	{
		buttom_name = 'h';

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SE��炷
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			help_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	
	else
	{
		col_flag[0] = false;
		col_flag[1] = false;
	}


	if (credit_flag == false&&c_flag[0] == true && c_flag[1] == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		credit_flag = true;
		c_flag[0] = false;
	}
	if (help_flag == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag = true;
		c_flag[0] = false;
	}
	//�w�i�X�N���[��
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B;

	//�{�^���ނ��Ȃ��A�������͓��삪�I������牟���Ă��Ȃ���Ԃɖ߂�
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
	}

}

//�h���[
void CObjModeSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//�{�^���ȊO�A�{�^���ʒu�ɃJ�[�\��
	float	b[4] = { 0.7f,0.7f,0.7f,1.0f };//�{�^���ʏ�
	float	t[4] = { 0.4f,0.4f,0.4f,1.0f };//�{�^�������Ă���

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


	//Gallery�\��
	src.m_top = CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_GALLERY;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_GALLERY;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'g')
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'g')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, b, 0.0f);

	//GameSelect�\��
	src.m_top = CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_SELECT;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_SELECT;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 's')
		Draw::Draw(1, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 's')
		Draw::Draw(1, &src, &dst, t, 0.0f);
	else
		Draw::Draw(1, &src, &dst, b, 0.0f);

	//�܂Ƃߕ\��
	src.m_top = CUT_CONCLUSION_T;
	src.m_left = CUT_CONCLUSION_L;
	src.m_right = CUT_CONCLUSION_R;
	src.m_bottom = CUT_CONCLUSION_B;
	dst.m_top = POS_CONCLUSION_T;
	dst.m_left = POS_CONCLUSION_L;
	dst.m_right = POS_CONCLUSION_R;
	dst.m_bottom = POS_CONCLUSION_B;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�N���W�b�g�{�^��
	src.m_top = CUT_CREDITBUTTON_T;
	src.m_left = CUT_CREDITBUTTON_L;
	src.m_right = CUT_CREDITBUTTON_R;
	src.m_bottom = CUT_CREDITBUTTON_B;
	dst.m_top = POS_CREDITBUTTON_T;
	dst.m_left = POS_CREDITBUTTON_L;
	dst.m_right = POS_CREDITBUTTON_R;
	dst.m_bottom = POS_CREDITBUTTON_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, t, 0.0f);
	else
		Draw::Draw(5, &src, &dst, b, 0.0f);
	//help�{�^��
	src.m_top = 100.0f;
	src.m_left = 924.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 200.0f;
	dst.m_top = 480.0f;
	dst.m_left = 120.0f;
	dst.m_right = 221.0f;
	dst.m_bottom = 580.0f;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'h')
		Draw::Draw(5, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'h')
		Draw::Draw(5, &src, &dst, t, 0.0f);
	else
		Draw::Draw(5, &src, &dst, b, 0.0f);
	//�N���W�b�g�\��
	if (credit_flag == false)
	{
		src.m_top = CUT_CREDIT_T;
		src.m_left = CUT_CREDIT_L;
		src.m_right = CUT_CREDIT_R;
		src.m_bottom = CUT_CREDIT_B;
		dst.m_top = POS_CREDIT_T;
		dst.m_left = POS_CREDIT_L;
		dst.m_right = POS_CREDIT_R;
		dst.m_bottom = POS_CREDIT_B;
		Draw::Draw(4, &src, &dst, c, 0.0f);
		
		src.m_top = 2.0f;
		src.m_left = 116.0f;
		src.m_right = 241.0f;
		src.m_bottom = 269.0f;
		dst.m_top = 120.0f;
		dst.m_left = 20.0f;
		dst.m_right = 160.0f;
		dst.m_bottom = 440.0f;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		src.m_top = 2.0f;
		src.m_left = 2.0f;
		src.m_right = 106.0;
		src.m_bottom = 281.0;
		dst.m_top = 200.0f;
		dst.m_left = 670.0f;
		dst.m_right = 780.0f;
		dst.m_bottom = 500.0f;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		
	}
	
	//�w���v�\��
	if (help_flag == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1280.0f;
		src.m_bottom = 720.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}