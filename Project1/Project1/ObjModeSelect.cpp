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

	//�t���O��������
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;
	credit_flag = true;
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
		c_flag[0] == true && c_flag[1] == true && credit_flag == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SELECT_WAIT);
		Scene::SetScene(new CSceneGameSelect());
	}

	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_GALLERY <= y && HIT_BOTTOM_GALLERY >= y &&
		c_flag[0] == true && c_flag[1] == true&& credit_flag == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SELECT_WAIT);
		Scene::SetScene(new CSceneGallery());
	}
	//�N���W�b�g
	if (POS_CREDITBUTTON_L <= x && POS_CREDITBUTTON_R >= x && POS_CREDITBUTTON_T <= y && POS_CREDITBUTTON_B >= y && c_flag[0] == true && c_flag[1] == true&& credit_flag == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		credit_flag = false;
		c_flag[0] = false;
	}
	if (credit_flag == false&&c_flag[0] == true && c_flag[1] == true)
	{
		//SE��炷
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		credit_flag = true;
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
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

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
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//GameSelect�\��
	src.m_top = CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_SELECT;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_SELECT;
	Draw::Draw(1, &src, &dst, c, 0.0f);

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
	Draw::Draw(5, &src, &dst, c, 0.0f);

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
	}
}