//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"ObjSwitchMain.h"
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

	for (int i = 0; i < 6; i++)
	{
		if (i<3)
		{
			SFlag[i] = false;
		}
		
		RFlag[i] = false;
	}
	bool setflag[2] = { false,false };

	memcpy(GFlag, setflag, sizeof(bool) * 2);

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;

	//�t���O��������
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;

}

//�A�N�V����
void CObjGallery::Action()
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


	Save::Open();

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
			{
				SFlag[i] = true;
			}
		}
		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			RFlag[i] = true;
		}
	}


	//�߂�{�^��
	if (HIT_BACK_LEFT <= x && HIT_BACK_RIGHT >= x && HIT_BACK_TOP <= y && HIT_BACK_BOTTOM >= y &&
		GFlag[0] == false && GFlag[1] == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SE��炷
		Audio::Start(2);
		Sleep(SCENEBACK_WAIT);
		Scene::SetScene(new CSceneModeSelect());
	}

	if (Gright == 1)
	{
		if (GFlag[0] == false)
		{
			//�E���
			if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y &&
				c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
			{
				Audio::Start(1);
				scroll_flag = true;
				c_flag[0] = true;

			}
			//�X�N���[������------
			if (scroll_flag == true)
			{
				//��������scrool������������
				speed += -SCROLL_SPEED;
				m_scroll += speed;
				//scroll��800����������800�ɂȂ����Aspeed������������
				if (m_scroll <= (-SCROLL_DISTANCE))
				{
					m_scroll = (-SCROLL_DISTANCE);
					speed = 0.0f;
				}
			}
			//�X�N���[���I������-----
			//�E���������č�����\��������
			if (m_scroll == -SCROLL_DISTANCE)
			{
				scroll_flag = false;
				Gright = 0;
				Gleft = 1;
			}
		}
		if (scroll_flag == false &&FlagCheck(SFlag, 3)==true)
		{
			if (GRAPHIC_LEFT <= x && GRAPHIC_RIGHT >= x && GRAPHIC_TOP <= y && GRAPHIC_BOTTOM >= y && GFlag[0] == false&&
				c_flag[0] == true && c_flag[1] == true)
			{
				
					Audio::Start(1);
					GFlag[0] = true;
				
			}
			else if (0.0f <= x && 800.0f >= x && 0.0f <= y && 600.0f >= y && GFlag[0] == true&&
				c_flag[0] == true && c_flag[1] == true)
			{
				
					Audio::Start(1);
					GFlag[0] = false;
				
			}
		}
	}
	if (Gleft == 1)
	{
		if (GFlag[1] == false)
		{
			//�����
			if (HIT_LEFTARROW_LEFT <= x && HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y &&
				c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
			{
				Audio::Start(1);
				scroll_flag = true;	//�X�N���[�����ɂ���
				c_flag[0] = true;
			}
			//�X�N���[������------
			if (scroll_flag == true)
			{
				//��������scrool������������
				speed += SCROLL_SPEED;
				m_scroll += speed;
				//scroll���O�����������O�ɂȂ����Aspeed������������
				if (m_scroll >= 0.0f)
				{
					m_scroll = 0.0f;
					speed = 0.0f;
				}
			}
			//�X�N���[���I������-----
			//�����������ĉE����\��������
			if (m_scroll == 0.0f&&scroll_flag == true)
			{
				scroll_flag = false;
				Gleft = 0;
				Gright = 1;
			}
		}
		if (scroll_flag == false && FlagCheck(RFlag, 6)==true)
		{
			if (GRAPHIC_LEFT <= x && GRAPHIC_RIGHT >= x && GRAPHIC_TOP <= y && GRAPHIC_BOTTOM >= y && GFlag[1] == false&&
				c_flag[0] == true && c_flag[1] == true)
			{
				
					Audio::Start(1);
					GFlag[1] = true;
				
			}
			else if (0.0f <= x && 800.0f >= x && 0.0f <= y && 600.0f >= y && GFlag[1] == true&&
				c_flag[0] == true && c_flag[1] == true)
			{
					Audio::Start(1);
					GFlag[1] = false;
				
			}
		}
	}
	//�{�^���ނ��Ȃ��A�������͓��삪�I������牟���Ă��Ȃ���Ԃɖ߂�
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
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
	src.m_top = CUT_BACK_TOP;
	src.m_left = CUT_BACK_LEFT;
	src.m_right = CUT_BACK_RIGHT;
	src.m_bottom = CUT_BACK_BOTTOM;
	dst.m_top = HIT_BACK_TOP;
	dst.m_left = HIT_BACK_LEFT;
	dst.m_right = HIT_BACK_RIGHT;
	dst.m_bottom = HIT_BACK_BOTTOM;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	if (Gright == 1 && scroll_flag == false)
	{
		//�E���{�^��
		src.m_top = CUT_RIGHTARROW_TOP;
		src.m_left = CUT_RIGHTARROW_LEFT;
		src.m_right = CUT_RIGHTARROW_RIGHT;
		src.m_bottom = CUT_RIGHTARROW_BOTTOM;
		dst.m_top = HIT_RIGHTARROW_TOP;
		dst.m_left = HIT_RIGHTARROW_LEFT;
		dst.m_right = HIT_RIGHTARROW_RIGHT;
		dst.m_bottom = HIT_RIGHTARROW_BOTTOM;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//���g
	src.m_top = CUT_GRAPHIC_TOP;
	src.m_left = CUT_GRAPHIC_LEFT;
	src.m_right = CUT_GRAPHIC_RIGHT;
	src.m_bottom = CUT_GRAPHIC_BOTTOM;
	dst.m_top = GRAPHIC_TOP;
	dst.m_left = GRAPHIC_LEFT + m_scroll;
	dst.m_right = GRAPHIC_RIGHT + m_scroll;
	dst.m_bottom = GRAPHIC_BOTTOM;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//���g
	src.m_top = CUT_GRAPHIC_TOP;
	src.m_left = CUT_GRAPHIC_LEFT;
	src.m_right = CUT_GRAPHIC_RIGHT;
	src.m_bottom = CUT_GRAPHIC_BOTTOM;
	dst.m_top = GRAPHIC_TOP;
	dst.m_left = GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
	dst.m_right = GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
	dst.m_bottom = GRAPHIC_BOTTOM;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//���\��
	if (FlagCheck(SFlag, 3)==true)
	{
		//�M�������[�J��(��)
		/*src.m_top   = 0.0f;
		src.m_left  = 559.0f;
		src.m_right = 639.0f;
		src.m_bottom= 140.0f;
		dst.m_top   = 245.0f;
		dst.m_left  = 300.0f+m_scroll;
		dst.m_right = 375.0f+m_scroll;
		dst.m_bottom= 385.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);*/
		src.m_top = CUT_GRAPHIC_TOP;
		src.m_left = CUT_GRAPHIC_LEFT;
		src.m_right = RESOURCE_GRAPHIC_RIGHT2;
		src.m_bottom = RESOURCE_GRAPHIC_BOTTOM2;
		if (GFlag[0] == false)
		{
			dst.m_top = GRAPHIC_TOP;
			dst.m_left = GRAPHIC_LEFT + m_scroll;
			dst.m_right = GRAPHIC_RIGHT + m_scroll;
			dst.m_bottom = GRAPHIC_BOTTOM;
		}
		else if (GFlag[0] == true)
		{
			src.m_top = CUT_GRAPHIC_TOP;
			src.m_left = CUT_GRAPHIC_LEFT;
			src.m_right = RESOURCE_GRAPHIC_RIGHT;
			src.m_bottom = RESOURCE_GRAPHIC_BOTTOM;
			dst.m_top = CUT_GRAPHIC_TOP;
			dst.m_left = CUT_GRAPHIC_LEFT + m_scroll;
			dst.m_right = RESOURCE_GRAPHIC_RIGHT + m_scroll;
			dst.m_bottom = RESOURCE_GRAPHIC_BOTTOM;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = CUT_GRAPHIC_TOP;
			src.m_left = CUT_GRAPHIC_LEFT;
			src.m_right = RESOURCE_GRAPHIC_RIGHT2;
			src.m_bottom = RESOURCE_GRAPHIC_BOTTOM2;

			dst.m_top = EX_GRAPHIC_TOP;
			dst.m_left = EX_GRAPHIC_LEFT + m_scroll;
			dst.m_right = EX_GRAPHIC_RIGHT + m_scroll;
			dst.m_bottom = EX_GRAPHIC_BOTTOM;
			Draw::Draw(3, &src, &dst, c, 0.0f);

		}
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	else
	{
		Font::StrDraw(L"�������", 280 + m_scroll, 100, 64, c);
		Font::StrDraw(L"Switch Panel", 200 + m_scroll, 250, 64, c);
		Font::StrDraw(L"�S��Perfect�B��", 160 + m_scroll, 400, 64, c);

	}

	if (Gleft == 1 && scroll_flag == false)
	{

		//�����{�^��
		src.m_top = CUT_LEFTARROW_TOP;
		src.m_left = CUT_LEFTARROW_LEFT;
		src.m_right = CUT_LEFTARROW_RIGHT;
		src.m_bottom = CUT_LEFTARROW_BOTTOM;
		dst.m_top = HIT_LEFTARROW_TOP;
		dst.m_left = HIT_LEFTARROW_LEFT;
		dst.m_right = HIT_LEFTARROW_RIGHT;
		dst.m_bottom = HIT_LEFTARROW_BOTTOM;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}



	//���\��
	if (FlagCheck(RFlag, 6) == true)
	{
		//�M�������[�J��(��)
		/*src.m_top   = 0.0f;
		src.m_left  = 559.0f;
		src.m_right = 639.0f;
		src.m_bottom= 140.0f;*/
		src.m_top = CUT_GRAPHIC_TOP;
		src.m_left = CUT_GRAPHIC_LEFT;
		src.m_right = RESOURCE_GRAPHIC_RIGHT2;
		src.m_bottom = RESOURCE_GRAPHIC_BOTTOM2;
		if (GFlag[1] == false)
		{
			dst.m_top = GRAPHIC_TOP;
			dst.m_left = GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
			dst.m_right = GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
			dst.m_bottom = GRAPHIC_BOTTOM;

		}

		else if (GFlag[1] == true)
		{
			src.m_top = CUT_GRAPHIC_TOP;
			src.m_left = CUT_GRAPHIC_LEFT;
			src.m_right = RESOURCE_GRAPHIC_RIGHT;
			src.m_bottom = RESOURCE_GRAPHIC_BOTTOM;
			dst.m_top = CUT_GRAPHIC_TOP;
			dst.m_left = CUT_GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
			dst.m_right = RESOURCE_GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
			dst.m_bottom = RESOURCE_GRAPHIC_BOTTOM;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = CUT_GRAPHIC_TOP;
			src.m_left = CUT_GRAPHIC_LEFT;
			src.m_right = RESOURCE_GRAPHIC_RIGHT2;
			src.m_bottom = RESOURCE_GRAPHIC_BOTTOM2;

			dst.m_top = EX_GRAPHIC_TOP;
			dst.m_left = EX_GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
			dst.m_right = EX_GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
			dst.m_bottom = EX_GRAPHIC_BOTTOM;
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}

		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else
	{
		Font::StrDraw(L"�������", 280 + SCROLL_DISTANCE + m_scroll, 100, 64, c);
		Font::StrDraw(L"Reversible Panel", 150 + SCROLL_DISTANCE + m_scroll, 250, 64, c);
		Font::StrDraw(L"�S��Perfect�B��", 160 + SCROLL_DISTANCE + m_scroll, 400, 64, c);
	}
	if (GFlag[0] == false&&GFlag[1] == false)
	{
		//�߂�{�^��
		src.m_top = CUT_BACK_TOP;
		src.m_left = CUT_BACK_LEFT;
		src.m_right = CUT_BACK_RIGHT;
		src.m_bottom = CUT_BACK_BOTTOM;
		dst.m_top = HIT_BACK_TOP;
		dst.m_left = HIT_BACK_LEFT;
		dst.m_right = HIT_BACK_RIGHT;
		dst.m_bottom = HIT_BACK_BOTTOM;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
		
	
}

bool CObjGallery::FlagCheck(bool flag[], int num)
{
	int count=0;
	for ( int i = 0; i < num; i++)
	{
		if (flag[i] == true)
		{
			count++;
		}
	}

	if (count==num)
	{
		return true;
	}

	return false;
}