//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"GameHead.h"
#include"ObjGallery.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGallery::Init()
{

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
			while (Input::GetMouButtonL() == true)
			{

			}
			Scene::SetScene(new CSceneModeSelect());

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

}