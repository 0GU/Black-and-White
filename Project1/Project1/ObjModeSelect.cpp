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
	m_y1 = 0.0f;
	m_y2 = 600.0f;
}

//�A�N�V����
void CObjModeSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_SELECT <= y && HIT_BOTTOM_SELECT >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGameSelect());
		}

	}

	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_GALLERY <= y && HIT_BOTTOM_GALLERY >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGallery());
		}

	}
	//�w�i�X�N���[��
	m_y1 -= 1.0f;
	if (m_y1 < -600.0f)
		m_y1 = 600;
	m_y2 -= 1.0f;
	if (m_y2 < -600.0f)
		m_y2 = 600;
	
}

//�h���[
void CObjModeSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�w�i�X�N���[��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 0.0f+m_y1;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f+ m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�w�i���X�^�[�g
	dst.m_top = 0.0f+ m_y2;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f+ m_y2;
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
	src.m_top =CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_SELECT;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_SELECT;
	Draw::Draw(1, &src, &dst, c, 0.0f);



}