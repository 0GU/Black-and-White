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
	m_r1 = RESET_POS_CREDIT;
	m_r2 = RESET_POS_CREDIT;
	C_m_y1 = RESET_POS_CREDIT;
	C_m_y2 = RESET_POS_CREDIT;
	
	//�t���O��������
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	memcpy(col_flag, flag_set, sizeof(bool)*(2));

	back = true;
	mou_call = true;
	credit_flag = true;
	help_flag = true;
	buttom_name = 0;
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
		buttom_name = 's';//���邳�ύX�p

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
		buttom_name = 'g';//���邳�ύX�p

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
		buttom_name = 'c';//���邳�ύX�p

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
		buttom_name = 'h';//���邳�ύX�p

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

	//�N���W�b�g�̃X�N���[��
	m_r1 += 1.5f;
	if (m_r1 > CIRCLE)
		m_r1 = RESET_POS_CREDIT;

	C_m_y1 = sin(3.14 / 180 * m_r1);
	
	m_r2  -= 1.5f;
	if (m_r2 < -CIRCLE)
		m_r2 = RESET_POS_CREDIT;

	C_m_y2 = sin(3.14 / 180 * m_r2);
	C_m_y1 *= CREDIT_MOVE_SPEED;
	C_m_y2 *= CREDIT_MOVE_SPEED;

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
	src.m_top = CUT_BUTTON_HELP_T;
	src.m_left = CUT_BUTTON_HELP_L;
	src.m_right = CUT_BUTTON_HELP_R;
	src.m_bottom = CUT_BUTTON_HELP_B;
	dst.m_top = POS_BUTTON_HELP_T;
	dst.m_left = POS_BUTTON_HELP_L;
	dst.m_right = POS_BUTTON_HELP_R;
	dst.m_bottom = POS_BUTTON_HELP_B;
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
		
		src.m_top = CUT_CRE_OBJ_TOP_LEFT;
		src.m_left = CUT_LEFT_CRE_OBJ_L;
		src.m_right = CUT_LEFT_CRE_OBJ_R;
		src.m_bottom = CUT_LEFT_CRE_OBJ_B;
		dst.m_top = POS_LEFT_CRE_OBJ_T+C_m_y1;
		dst.m_left = POS_LEFT_CRE_OBJ_L;
		dst.m_right = POS_LEFT_CRE_OBJ_R;
		dst.m_bottom = POS_LEFT_CRE_OBJ_B+C_m_y1;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		src.m_top = CUT_CRE_OBJ_TOP_LEFT;
		src.m_left = CUT_CRE_OBJ_TOP_LEFT;
		src.m_right = CUT_RIGHT_CRE_OBJ_R;
		src.m_bottom = CUT_RIGHT_CRE_OBJ_B;
		dst.m_top = POS_RIGHT_CRE_OBJ_T +C_m_y2;
		dst.m_left = POS_RIGHT_CRE_OBJ_L;
		dst.m_right = POS_RIGHT_CRE_OBJ_R;
		dst.m_bottom = POS_RIGHT_CRE_OBJ_B +C_m_y2;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		
	}
	
	//�w���v�\��
	if (help_flag == false)
	{
		src.m_top = HELP_TOP_LEFT;
		src.m_left = HELP_TOP_LEFT;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = HELP_TOP_LEFT;
		dst.m_left = HELP_TOP_LEFT;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}