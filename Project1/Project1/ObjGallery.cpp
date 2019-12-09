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

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGallery::Init()
{
	Gright = 1;
	Gleft = 0;

	for (int i = 0; i < 3; i++)
	{
		SFlag[i] = false;
		RFlag[i] = false;
	}
	bool setflag[2] = { false,false };

	memcpy(GFlag, setflag, sizeof(bool) * 2);

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;
	m_ani_flame = 0;
	m_time = 0;
	mouse_flag = false;
}

//アクション
void CObjGallery::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	
	if (Input::GetMouButtonL() == true)
	{
		mouse_flag = true;

	}
	if (mouse_flag == true)
	{
		//タイムを増やす（ループ中１回のみ）
		m_time++;

		//アニメーションを動かす
		if (m_time == 3) {
			m_ani_flame++;
			m_time = 0;
		}
		//アニメーションが終了したら黒パネルに変更
		if (m_ani_flame == 4)
		{
			m_ani_flame = 0;
			mouse_flag = false;
		}

	}

	Save::Open();

	for (int i = 0; i < 3; i++)
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


	//戻るボタン
	if (HIT_BACK_LEFT <= x && HIT_BACK_RIGHT >= x && HIT_BACK_TOP <= y && HIT_BACK_BOTTOM >= y &&
		GFlag[0] == false && GFlag[1] == false)
	{
		if (Input::GetMouButtonL() == true && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(2);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneModeSelect());

		}
	}

	if (Gright == 1)
	{
		if (GFlag[0] == false)
		{
			//右矢印
			if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y)
			{
				if (Input::GetMouButtonL() == true && scroll_flag == false)
				{
					Audio::Start(1);
					while (Input::GetMouButtonL() == true)
					{

					}
					scroll_flag = true;
				}
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
		if (scroll_flag == false && SFlag[0] == true && SFlag[1] == true && SFlag[2] == true)
		{
			if (GRAPHIC_LEFT <= x && GRAPHIC_RIGHT >= x && GRAPHIC_TOP <= y && GRAPHIC_BOTTOM >= y && GFlag[0] == false)
			{
				if (Input::GetMouButtonL() == true)
				{
					while (Input::GetMouButtonL() == true)
					{

					}
					Audio::Start(1);
					GFlag[0] = true;
				}
			}
			else if (0.0f <= x && 800.0f >= x && 0.0f <= y && 600.0f >= y && GFlag[0] == true)
			{
				if (Input::GetMouButtonL() == true)
				{
					while (Input::GetMouButtonL() == true)
					{

					}
					Audio::Start(1);
					GFlag[0] = false;
				}
			}
		}
	}
	if (Gleft == 1)
	{
		if (GFlag[1] == false)
		{
			//左矢印
			if (HIT_LEFTARROW_LEFT <= x && HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y)
			{
				if (Input::GetMouButtonL() == true && scroll_flag == false)
				{
					Audio::Start(1);
					while (Input::GetMouButtonL() == true)
					{

					}
					scroll_flag = true;	//スクロール中にする
				}
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
		if (scroll_flag == false && RFlag[0] == true && RFlag[1] == true && RFlag[2] == true)
		{
			if (GRAPHIC_LEFT <= x && GRAPHIC_RIGHT >= x && GRAPHIC_TOP <= y && GRAPHIC_BOTTOM >= y && GFlag[1] == false)
			{
				if (Input::GetMouButtonL() == true)
				{
					while (Input::GetMouButtonL() == true)
					{

					}
					Audio::Start(1);
					GFlag[1] = true;
				}
			}
			else if (0.0f <= x && 800.0f >= x && 0.0f <= y && 600.0f >= y && GFlag[1] == true)
			{
				if (Input::GetMouButtonL() == true)
				{
					while (Input::GetMouButtonL() == true)
					{

					}
					Audio::Start(1);
					GFlag[1] = false;
				}
			}
		}
	}
}

//ドロー
void CObjGallery::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

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
		Draw::Draw(0, &src, &dst, c, 0.0f);
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
	if (SFlag[0] == true && SFlag[1] == true && SFlag[2] == true)
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
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 4032.0f;
		src.m_bottom = 3024.0f;
		if (GFlag[0] == false)
		{
			dst.m_top = GRAPHIC_TOP;
			dst.m_left = GRAPHIC_LEFT + m_scroll;
			dst.m_right = GRAPHIC_RIGHT + m_scroll;
			dst.m_bottom = GRAPHIC_BOTTOM;
		}
		else if (GFlag[0] == true)
		{
			dst.m_top = 0.0f;
			dst.m_left = 0.0f + m_scroll;
			dst.m_right = 800.0f + m_scroll;
			dst.m_bottom = 600.0f;
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
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}



	//仮表示
	if (RFlag[0] == true && RFlag[1] == true && RFlag[2] == true)
	{
		//ギャラリー開放(仮)
		/*src.m_top   = 0.0f;
		src.m_left  = 559.0f;
		src.m_right = 639.0f;
		src.m_bottom= 140.0f;*/
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 4032.0f;
		src.m_bottom = 3024.0f;
		if (GFlag[1] == false)
		{
			dst.m_top = GRAPHIC_TOP;
			dst.m_left = GRAPHIC_LEFT + SCROLL_DISTANCE + m_scroll;
			dst.m_right = GRAPHIC_RIGHT + SCROLL_DISTANCE + m_scroll;
			dst.m_bottom = GRAPHIC_BOTTOM;
		}
		else if (GFlag[1] == true)
		{
			dst.m_top = 0.0f;
			dst.m_left = 0.0f + SCROLL_DISTANCE + m_scroll;
			dst.m_right = 800.0f + SCROLL_DISTANCE + m_scroll;
			dst.m_bottom = 600.0f;
		}
		/*
		dst.m_top   = 245.0f;
		dst.m_left  = 300.0f+ SCROLL_DISTANCE +m_scroll;
		dst.m_right = 375.0f+ SCROLL_DISTANCE +m_scroll;
		dst.m_bottom= 385.0;*/
		//Draw::Draw(0, &src, &dst, c, 0.0f);
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
	else
	{
		Font::StrDraw(L"解放条件", 280 + m_scroll, 100, 64, c);
		Font::StrDraw(L"Reversible Panel", 150 + m_scroll, 250, 64, c);
		Font::StrDraw(L"全てPerfect達成", 160 + m_scroll, 400, 64, c);

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

		//クリックエフェクト(仮)
		if (mouse_flag == true)
		{
			src.m_top = 72;
			src.m_left = 800 + (m_ani_flame * 40);
			src.m_right = src.m_left + 40;
			src.m_bottom = 112;
			dst.m_top = y - 19;
			dst.m_left = x - 19;
			dst.m_right = dst.m_left + 40;
			dst.m_bottom = dst.m_top + 40;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}
	}
}