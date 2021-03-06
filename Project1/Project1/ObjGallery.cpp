//使用するヘッダーファイル
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
#include "MoveScenefunction.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGallery::Init()
{
	Gright = 1;
	Gleft = 0;

	for (int i = 0; i < 6; i++)
	{

		SFlag[i] = false;


		RFlag[i] = false;
	}
	bool setflag[2] = { false,false };

	memcpy(GFlag, setflag, sizeof(bool) * 2);
	memcpy(col_flag, setflag, sizeof(bool)*(2));

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;

	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;
	buttom_name = 0;
	help_flag = true;
}

//アクション
void CObjGallery::Action()
{
	col_flag[0] = false;
	col_flag[1] = false;

	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//クリックエフェクト呼び出し（１回のみ）
	if (mou_call == true)
	{
		CObjMouse*m = new CObjMouse(back);
		Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
		mou_call = false;
	}

	//クリック判別
	//[0]のみ true = 押している状態　
	//[1]のみ true = 押していない状態
	//両方    true = 押してから離した状態
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

		if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
		{
			SFlag[i] = true;
		}

		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			RFlag[i] = true;
		}
	}

	//ヘルプボタン
	if (POS_HELPBUTTON_L <= x && POS_HELPBUTTON_R >= x && POS_HELPBUTTON_T <= y && POS_HELPBUTTON_B >= y &&
		GFlag[0] == false && GFlag[1] == false && scroll_flag == false && help_flag == true)
	{
		buttom_name = 'h';

		if (c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			help_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	else if (help_flag == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag = true;
		c_flag[0] = false;
	}
	//戻るボタン
	else if (HIT_BACK_LEFT <= x && HIT_BACK_RIGHT >= x && HIT_BACK_TOP <= y && HIT_BACK_BOTTOM >= y &&
		GFlag[0] == false && GFlag[1] == false && scroll_flag == false && help_flag == true)
	{
		buttom_name = 'b';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true&& scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(2);
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneModeSelect());
		}
		ButtomCol(c_flag, col_flag);

	}

	else if (Gright == 1)
	{
		if (GFlag[0] == false)
		{
			//右矢印
			if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y &&
				scroll_flag == false && help_flag == true)
			{
				buttom_name = 'r';//明るさ変更用

				if (c_flag[0] == true && c_flag[1] == true)
				{
					Audio::Start(1);
					scroll_flag = true;
					c_flag[0] = true;
				}
				ButtomCol(c_flag, col_flag);
			}
			else
			{
				col_flag[0] = false;
				col_flag[1] = false;
			}

			//スクロール処理------
			if (scroll_flag == true)
			{
				//少しずつscroolを加速させる
				speed += -SCROLL_SPEED;
				m_scroll += speed;
				//scrollが800を上回ったら800になおし、speedを初期化する
				if (m_scroll <= (-SCROLL_DISTANCE))
				{
					m_scroll = (-SCROLL_DISTANCE);
					speed = 0.0f;
				}
			}
			//スクロール終了処理-----
			//右矢印を消して左矢印を表示させる
			if (m_scroll == -SCROLL_DISTANCE)
			{
				scroll_flag = false;
				Gright = 0;
				Gleft = 1;
			}
		}
		if (scroll_flag == false &&FlagCheck(SFlag, 6)==true)
		{
			if (GRAPHIC_LEFT <= x && GRAPHIC_RIGHT >= x && GRAPHIC_TOP <= y && GRAPHIC_BOTTOM >= y && GFlag[0] == false&&
				c_flag[0] == true && c_flag[1] == true && help_flag == true)
			{
				
					Audio::Start(1);
					GFlag[0] = true;
				
			}
			else if (0.0f <= x && 800.0f >= x && 0.0f <= y && 600.0f >= y && GFlag[0] == true&&
				c_flag[0] == true && c_flag[1] == true && help_flag == true)
			{
				
					Audio::Start(1);
					GFlag[0] = false;
				
			}
		}

	}
	else if (Gleft == 1)
	{
		if (GFlag[1] == false)
		{
			//左矢印
			if (HIT_LEFTARROW_LEFT <= x && HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y &&
				scroll_flag == false && help_flag == true)
			{
				buttom_name = 'l';//明るさ変更用

				if (c_flag[0] == true && c_flag[1] == true)
				{
					Audio::Start(1);
					scroll_flag = true;	//スクロール中にする
					c_flag[0] = true;
				}
				ButtomCol(c_flag, col_flag);
			}
			else
			{
				col_flag[0] = false;
				col_flag[1] = false;
			}
			//スクロール処理------
			if (scroll_flag == true)
			{
				//少しずつscroolを加速させる
				speed += SCROLL_SPEED;
				m_scroll += speed;
				//scrollが０を下回ったら０になおし、speedを初期化する
				if (m_scroll >= 0.0f)
				{
					m_scroll = 0.0f;
					speed = 0.0f;
				}
			}
			//スクロール終了処理-----
			//左矢印を消して右矢印を表示させる
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
				c_flag[0] == true && c_flag[1] == true && help_flag == true)
			{
				Audio::Start(1);
				GFlag[1] = true;
			}
			else if (GRAPHIC_TOP_LEFT <= x && GRAPHIC_RIGHT_BLACK >= x && GRAPHIC_TOP_LEFT <= y && GRAPHIC_BOTTOM_BLACK >= y && GFlag[1] == true&&
				c_flag[0] == true && c_flag[1] == true && help_flag == true)
			{
				Audio::Start(1);
				GFlag[1] = false;
			}
		}

	}
	
	/*else
	{
		col_flag[0] = false;
		col_flag[1] = false;
	}
	*/
	//ボタン類がない、もしくは動作が終わったら押していない状態に戻す
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
	}

	if (Input::GetVKey(VK_RETURN) == true && Input::GetVKey(VK_RSHIFT) == true && Input::GetVKey(VK_RCONTROL) == true)
	{
		MoveTitle();
	}

}

//ドロー
void CObjGallery::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//ボタン以外、ボタン位置にカーソル
	float	b[4] = { 0.7f,0.7f,0.7f,1.0f };//ボタン通常
	float	t[4] = { 0.4f,0.4f,0.4f,1.0f };//ボタン押している

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//戻るボタン
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
		//右矢印ボタン
		src.m_top = CUT_RIGHTARROW_TOP;
		src.m_left = CUT_RIGHTARROW_LEFT;
		src.m_right = CUT_RIGHTARROW_RIGHT;
		src.m_bottom = CUT_RIGHTARROW_BOTTOM;
		dst.m_top = HIT_RIGHTARROW_TOP;
		dst.m_left = HIT_RIGHTARROW_LEFT;
		dst.m_right = HIT_RIGHTARROW_RIGHT;
		dst.m_bottom = HIT_RIGHTARROW_BOTTOM;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'r')
			Draw::Draw(0, &src, &dst, c, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'r')
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, b, 0.0f);
	}

	//仮枠
	src.m_top = CUT_GRAPHIC_TOP;
	src.m_left = CUT_GRAPHIC_LEFT;
	src.m_right = CUT_GRAPHIC_RIGHT;
	src.m_bottom = CUT_GRAPHIC_BOTTOM;
	dst.m_top = GRAPHIC_TOP;
	dst.m_left = GRAPHIC_LEFT + m_scroll;
	dst.m_right = GRAPHIC_RIGHT + m_scroll;
	dst.m_bottom = GRAPHIC_BOTTOM;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//仮枠
	src.m_top = CUT_GRAPHIC_TOP;
	src.m_left = CUT_GRAPHIC_LEFT;
	src.m_right = CUT_GRAPHIC_RIGHT;
	src.m_bottom = CUT_GRAPHIC_BOTTOM;
	dst.m_top = GRAPHIC_TOP;
	dst.m_left = GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
	dst.m_right = GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
	dst.m_bottom = GRAPHIC_BOTTOM;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//仮表示
	if (FlagCheck(SFlag, 6)==true)
	{
		//ギャラリー開放(仮)
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
		Font::StrDraw(L"解放条件", 280 + m_scroll, 100, 64, c);
		Font::StrDraw(L"Switch Panel", 200 + m_scroll, 250, 64, c);
		Font::StrDraw(L"全てPerfect達成", 160 + m_scroll, 400, 64, c);

	}

	if (Gleft == 1 && scroll_flag == false)
	{

		//左矢印ボタン
		src.m_top = CUT_LEFTARROW_TOP;
		src.m_left = CUT_LEFTARROW_LEFT;
		src.m_right = CUT_LEFTARROW_RIGHT;
		src.m_bottom = CUT_LEFTARROW_BOTTOM;
		dst.m_top = HIT_LEFTARROW_TOP;
		dst.m_left = HIT_LEFTARROW_LEFT;
		dst.m_right = HIT_LEFTARROW_RIGHT;
		dst.m_bottom = HIT_LEFTARROW_BOTTOM;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'l')
			Draw::Draw(0, &src, &dst, c, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'l')
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, b, 0.0f);
	}



	//仮表示
	if (FlagCheck(RFlag, 6) == true)
	{
		//ギャラリー開放(仮)
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
		Font::StrDraw(L"解放条件", 280 + SCROLL_DISTANCE + m_scroll, 100, 64, c);
		Font::StrDraw(L"Reversible Panel", 150 + SCROLL_DISTANCE + m_scroll, 250, 64, c);
		Font::StrDraw(L"全てPerfect達成", 160 + SCROLL_DISTANCE + m_scroll, 400, 64, c);
	}
	if (GFlag[0] == false&&GFlag[1] == false)
	{
		//戻るボタン
		src.m_top = CUT_BACK_TOP;
		src.m_left = CUT_BACK_LEFT;
		src.m_right = CUT_BACK_RIGHT;
		src.m_bottom = CUT_BACK_BOTTOM;
		dst.m_top = HIT_BACK_TOP;
		dst.m_left = HIT_BACK_LEFT;
		dst.m_right = HIT_BACK_RIGHT;
		dst.m_bottom = HIT_BACK_BOTTOM;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'b')
			Draw::Draw(0, &src, &dst, c, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'b')
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, b, 0.0f);
	}
		
	//helpボタン---------------------------------------------------------------
	if (GFlag[0] == false && GFlag[1] == false)
	{
		src.m_top = CUT_HELPBUTTON_T;
		src.m_left = CUT_HELPBUTTON_L;
		src.m_right = CUT_HELPBUTTON_R;
		src.m_bottom = CUT_HELPBUTTON_B;
		dst.m_top = POS_HELPBUTTON_T;
		dst.m_left = POS_HELPBUTTON_L;
		dst.m_right = POS_HELPBUTTON_R;
		dst.m_bottom = POS_HELPBUTTON_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'h')
			Draw::Draw(0, &src, &dst, c, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'h')
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, b, 0.0f);
	}
	//ヘルプ表示
	if (help_flag == false)
	{
		src.m_top = CUT_HELP_T;
		src.m_left = CUT_HELP_L;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = POS_HELP_T;
		dst.m_left = POS_HELP_L;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(2, &src, &dst, c, 0.0f);
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