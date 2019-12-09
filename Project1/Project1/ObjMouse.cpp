//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\DrawFont.h"
#include"GameL/SceneManager.h"

#include"ObjMouse.h"
#include"SceneReversibleMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMouse::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_l = false;
}

//�A�N�V����
void CObjMouse::Action()
{

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_l = Input::GetMouButtonL();
}
//�h���[
void CObjMouse::Draw()
{	
	float c[4] = { 0.5,1,1,1 };
	/*
	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 10, 20, 36, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=�����Ă�", 20, 60, 24, c);
	else
		Font::StrDraw(L"L=�����ĂȂ�", 20, 60, 24, c);*/
}
