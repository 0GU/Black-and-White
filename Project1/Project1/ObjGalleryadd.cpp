//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/Audio.h"
#include"windows.h"
#include"GameHead.h"
#include"ObjGalleryadd.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGalleryadd::Init()
{

}

//�A�N�V����
void CObjGalleryadd::Action()
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


	if (0 <= x && WINDOW_SIZE_X >= x && 0 <= y && WINDOW_SIZE_Y >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(CLICK_WAIT);

				Scene::SetScene(new CSceneModeSelect());

			}
		}

	}
}

//�h���[
void CObjGalleryadd::Draw()
{
	// �`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = WINDOW_SIZE_X;
	src.m_bottom = WINDOW_SIZE_Y;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom = WINDOW_SIZE_Y;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//