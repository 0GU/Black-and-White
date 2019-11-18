//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjGallery.h"
#include"Windows.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGallery::Init()
{
	Gright = 1;
	Gleft = 0;
}

//�A�N�V����
void CObjGallery::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//�߂�{�^��
	if (5 <= x && 125 >= x && 35 <= y && 135 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SE��炷
			Audio::Start(2);
			while (Input::GetMouButtonL() == true)
			{				
								
			}
			Sleep(500);
			Scene::SetScene(new CSceneModeSelect());

		}
	}

	if (Gright == 1)
	{
		//�E���
		if (700 <= x && 775 >= x && 240 <= y && 360 >= y)
		{
			if (Input::GetMouButtonL() == true)
			{
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(300);
				Gright = 0;
				Gleft = 1;

			}
		}
	}
	if (Gleft == 1)
	{
		//�����
		if (23 <= x && 101 >= x && 240 <= y && 360 >= y)
		{
			if (Input::GetMouButtonL() == true)
			{
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(300);
				Gleft = 0;
				Gright = 1;

			}
		}
	}
}

//�h���[
void CObjGallery::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	//�߂�{�^��
	src.m_top = 139.0f;
	src.m_left = 559.0f;
	src.m_right = 679.0f;
	src.m_bottom = 239.0f;
	dst.m_top = 35.0f;
	dst.m_left = 5.0f;
	dst.m_right = 125.0;
	dst.m_bottom = 135.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	if (Gright == 1)
	{
		//���{�^��
		src.m_top = 0.0f;
		src.m_left = 559.0f;
		src.m_right = 639.0f;
		src.m_bottom = 140.0f;
		dst.m_top = 245.0f;
		dst.m_left = 700.0f;
		dst.m_right = 775.0;
		dst.m_bottom = 365.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);

		//���g
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 50.0f;
		dst.m_left = 145.0f;
		dst.m_right = 657.0f;
		dst.m_bottom = 560.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

	if (Gleft == 1)
	{
		//�����{�^��
		src.m_top = 0.0f;
		src.m_left = 638.0f;
		src.m_right = 718.0f;
		src.m_bottom = 140.0f;
		dst.m_top = 245.0f;
		dst.m_left = 26.0f;
		dst.m_right = 101.0;
		dst.m_bottom = 365.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);

		//���g
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 50.0f;
		dst.m_left = 145.0f;
		dst.m_right = 657.0f;
		dst.m_bottom = 560.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}