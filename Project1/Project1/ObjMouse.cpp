//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\DrawFont.h"
#include"GameL/SceneManager.h"

#include"ObjMouse.h"
#include"SceneReversibleMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjMouse::CObjMouse(bool back)
{
	back_col = back;
}

//�C�j�V�����C�Y
void CObjMouse::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_l = false;

	m_ani_flame = 0;
	m_time = 0;
	mouse_flag = false;

}

//�A�N�V����
void CObjMouse::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_l = Input::GetMouButtonL();

	if (m_mou_l == true)
	{
		mouse_flag = true;
	}
	if (mouse_flag == true)
	{
		//�^�C���𑝂₷�i���[�v���P��̂݁j
		m_time += 1;

		//�A�j���[�V�����𓮂���
		if (m_time == 3)
		{
			m_ani_flame += 1;
			m_time = 0;
		}
		//�A�j���[�V�������I�������獕�p�l���ɕύX
		if (m_ani_flame == 4)
		{
			m_ani_flame = 0;
			mouse_flag = false;
		}

	}

}
//�h���[
void CObjMouse::Draw()
{	
	float c[4] = { 0.5,1,1,1 };
	float ew[4] = { 1.0f,1.0f,1.0f,1.0f };
	float eb[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 10, 20, 36, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=�����Ă�", 20, 60, 24, c);
	else
		Font::StrDraw(L"L=�����ĂȂ�", 20, 60, 24, c);

	//�N���b�N�G�t�F�N�g(��)
	if (mouse_flag == true)
	{
		src.m_top = 72;
		src.m_left = 800 + (m_ani_flame * 40);
		src.m_right = src.m_left + 40;
		src.m_bottom = 112;
		dst.m_top = m_mou_y - 19;
		dst.m_left = m_mou_x - 19;
		dst.m_right = dst.m_left + 40;
		dst.m_bottom = dst.m_top + 40;

		if (back_col == true)
		{
			Draw::Draw(10, &src, &dst, ew, 0.0f);
		}
		else
		{
			Draw::Draw(10, &src, &dst, eb, 0.0f);

		}
	}

}
