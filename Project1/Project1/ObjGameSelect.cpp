//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"ObjGameSelect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameSelect::Init()
{

}

//�A�N�V����
void CObjGameSelect::Action()
{

}

//�h���[
void CObjGameSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 135.0f;
	dst.m_top = 30.0f;
	dst.m_left = 120.0f;
	dst.m_right = 600.0;
	dst.m_bottom = 150.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	// ���r���Ȃ̂ł܂��\���o���ĂȂ��ł�
	//GAME SELECT
	//�؂���
	src.m_top = 135.0f;
	src.m_left = 0.0f;
	src.m_right = 560.0f;
	src.m_bottom = 267.0f;
	//�\��
	dst.m_top = 50.0f;
	dst.m_left = 120.0f;
	dst.m_right = 660.0f;
	dst.m_bottom = 135.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);
	src.m_bottom = 136.0f;
	dst.m_top = 360.0f;
	dst.m_left = 160.0f;
	dst.m_right = 640.0;
	dst.m_bottom = 480.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);//�M�������[

	//�w�i�\��
	src.m_top = 134.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 270.0f;
	dst.m_top = 119.0f;
	dst.m_left = 160.0f;
	dst.m_right = 640.0;
	dst.m_bottom = 240.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);//�M�������[

}