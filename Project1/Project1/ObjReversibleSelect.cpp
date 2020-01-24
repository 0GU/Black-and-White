//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjReversibleSelect.h"
#include"ObjReversibleMain.h"
#include"Windows.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjReversibleSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;

	bool set_Pflag[6] = { false, false ,false ,false, false ,false };
	bool set_Cflag[6] = { false, false ,false ,false, false ,false };

	Save::Open();

	for (int i = 0; i < 6; i++)
	{
		if (((UserData*)Save::GetData())->RClearFlag[i] == true)
		{
			set_Cflag[i] = true;
		}

		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			set_Pflag[i] = true;
		}
	}
	memcpy(Pflag, set_Pflag, sizeof(bool)*(6));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(6));

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;

	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = false;
	mou_call = true;
	Rflag = true;
	Rright = 1;
	Rleft = 0;
}

//アクション
void CObjReversibleSelect::Action()
{
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
	if (Cflag[2] == true)
	{
		if (Rright == 1)
		{

			//右矢印
			if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y &&
				c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
			{
				Audio::Start(1);
				scroll_flag = true;
				c_flag[0] = true;
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
				Rright = 0;
				Rleft = 1;
				Rflag = false;
			}
		}
	}
	if (Rleft == 1)
	{
		//左矢印
		if (HIT_LEFTARROW_LEFT <= x && HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y &&
			c_flag[0] == true && c_flag[1] == true && scroll_flag == false)
		{
			Audio::Start(1);
			scroll_flag = true;	//スクロール中にする
			c_flag[0] = true;
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
			Rleft = 0;
			Rright = 1;
		}


	}

	//right値が描画とズレているため右方向を-10.0f調整
	//Stage1--------------------------------------------------------------
	//この場所を左クリックでリバーシブルのステージ1へ
	if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP1 <= y && HIT_BOTTOM_RP1 >= y &&
		c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SELECT_WAIT);
		Scene::SetScene(new CSceneReversibleMain(1));
	}

	//Stage2----------------------------------------------------------------
	if (Cflag[0] == true)
	{
		//この場所を左クリックでリバーシブルのステージ2へ
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP2 <= y && HIT_BOTTOM_RP2 >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleMain(2));
		}
	}

	//Stage3----------------------------------------------------------------
	if (Cflag[1] == true)
	{
		//この場所を左クリックでリバーシブルのステージ3へ
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP3 <= y && HIT_BOTTOM_RP3 >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 0 && Rright == 1 && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleMain(3));
		}
	}

	//Stage4----------------------------------------------------------------
	if (Cflag[2] == true)
	{
		//この場所を左クリックでリバーシブルのステージ2へ
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP1 <= y && HIT_BOTTOM_RP1 >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleMain(4));
		}
	}

	//Stage5----------------------------------------------------------------
	if (Cflag[3] == true)
	{
		//この場所を左クリックでリバーシブルのステージ2へ
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP2 <= y && HIT_BOTTOM_RP2 >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleMain(5));
		}
	}

	//Stage6----------------------------------------------------------------
	if (Cflag[4] == true)
	{
		//この場所を左クリックでリバーシブルのステージ3へ
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP3 <= y && HIT_BOTTOM_RP3 >= y &&
			c_flag[0] == true && c_flag[1] == true && Rleft == 1 && Rright == 0 && scroll_flag == false)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleMain(6));
		}
	}
	//戻るボタン
	if (HIT_LEFT_SCENEBACK <= x && HIT_RIGHT_SCENEBACK >= x && HIT_TOP_SCENEBACK <= y && HIT_BOTTOM_SCENEBACK >= y &&
		c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(2);
		Sleep(SCENEBACK_WAIT);
		Scene::SetScene(new CSceneGameSelect());
	}
	//背景スクロール
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B;

	//ボタン類がない、もしくは動作が終わったら押していない状態に戻す
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
	}
}


//ドロー
void CObjReversibleSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用



	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置



	//背景スクロール
	src.m_top = BACKGROUND_TL;
	src.m_left = BACKGROUND_TL;
	src.m_right = BACKGROUND_R;
	src.m_bottom = BACKGROUND_B;

	dst.m_top = BACKGROUND_TL + m_y1;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y1;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//ステージを選択
	src.m_top = 362;
	src.m_left = 2;
	src.m_right = 537;
	src.m_bottom = 430;	//542x95
	dst.m_top = 15.0f;
	dst.m_left = 140.0f;
	dst.m_right = 690.0f;
	dst.m_bottom = 135.0;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	if (Cflag[2] == true)
	{
		//右矢印の描画-------------------------
		if (Rright == 1 && scroll_flag == false)
		{
			//右矢印ボタン
			src.m_top = RIGHT_ARROW_T;
			src.m_left = RIGHT_ARROW_L;
			src.m_right = RIGHT_ARROW_R;
			src.m_bottom = RIGHT_ARROW_B;
			dst.m_top = HIT_RIGHTARROW_TOP;
			dst.m_left = HIT_RIGHTARROW_LEFT;
			dst.m_right = HIT_RIGHTARROW_RIGHT;
			dst.m_bottom = HIT_RIGHTARROW_BOTTOM;
			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
	}
	//左矢印の描画------------------------
	if (Rleft == 1 && scroll_flag == false)
	{

		//左矢印ボタン
		src.m_top = RIGHT_ARROW_T;
		src.m_left = LEFT_ARROW_L;
		src.m_right = LEFT_ARROW_R;
		src.m_bottom = RIGHT_ARROW_B;
		dst.m_top = HIT_LEFTARROW_TOP;
		dst.m_left = HIT_LEFTARROW_LEFT;
		dst.m_right = HIT_LEFTARROW_RIGHT;
		dst.m_bottom = HIT_LEFTARROW_BOTTOM;
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
	//Stage1の描画
	src.m_top = CUT_PIC_TOP_RP1;
	src.m_left = CUT_PIC_LEFT_RP;
	src.m_right = CUT_PIC_RIGHT_RP;
	src.m_bottom = CUT_PIC_BOTTOM_RP1;
	dst.m_top = HIT_TOP_RP1;
	dst.m_left = HIT_LEFT_RP + m_scroll;
	dst.m_right = HIT_RIGHT_RP + m_scroll;
	dst.m_bottom = HIT_BOTTOM_RP1;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//Stage2の描画
	if (Cflag[0] == true)
	{
		src.m_top = CUT_PIC_TOP_RP2;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP2;
		dst.m_top = HIT_TOP_RP2;
		dst.m_left = HIT_LEFT_RP + m_scroll;
		dst.m_right = HIT_RIGHT_RP + m_scroll;
		dst.m_bottom = HIT_BOTTOM_RP2;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//Stage3の描画
	if (Cflag[1] == true)
	{
		src.m_top = CUT_PIC_TOP_RP3;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP3;
		dst.m_top = HIT_TOP_RP3;
		dst.m_left = HIT_LEFT_RP + m_scroll;
		dst.m_right = HIT_RIGHT_RP + m_scroll;
		dst.m_bottom = HIT_BOTTOM_RP3;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

	//Stage4の描画
	if (Cflag[2] == true)
	{
		src.m_top = CUT_PIC_TOP_RP4;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP4;
		dst.m_top = HIT_TOP_RP4;
		dst.m_left = HIT_LEFT_RP + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_RP + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_RP4;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//Stage5の描画
	if (Cflag[3] == true)
	{
		src.m_top = CUT_PIC_TOP_RP5;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP5;
		dst.m_top = HIT_TOP_RP5;
		dst.m_left = HIT_LEFT_RP + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_RP + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_RP5;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//Stage6の描画
	if (Cflag[4] == true)
	{
		src.m_top = CUT_PIC_TOP_RP6;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP6;
		dst.m_top = HIT_TOP_RP6;
		dst.m_left = HIT_LEFT_RP + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_RP  + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_RP6;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//戻るボタン
	src.m_top = CUT_PIC_TOP_SCENEBACK;
	src.m_left = CUT_PIC_LEFT_SCENEBACK;
	src.m_right = CUT_PIC_RIGHT_SCENEBACK;
	src.m_bottom = CUT_PIC_BOTTOM_SCENEBACK;
	dst.m_top = HIT_TOP_SCENEBACK;
	dst.m_left = HIT_LEFT_SCENEBACK;
	dst.m_right = HIT_RIGHT_SCENEBACK;
	dst.m_bottom = HIT_BOTTOM_SCENEBACK;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//黒星の描画-------------------------------------------------------------------------------------------



	//(1)
	if (Pflag[0] == false && Cflag[0] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR1;
		dst.m_left = HIT_LEFT_BLACKSTAR + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR1;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(2)
	if (Pflag[1] == false && Cflag[1] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR2;
		dst.m_left = HIT_LEFT_BLACKSTAR + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR2;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(3)
	if (Pflag[2] == false && Cflag[2] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR3;
		dst.m_left = HIT_LEFT_BLACKSTAR + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR3;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}//(4)
	if (Pflag[3] == false && Cflag[3] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR1;
		dst.m_left = HIT_LEFT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR1;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(5)
	if (Pflag[4] == false && Cflag[4] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR2;
		dst.m_left = HIT_LEFT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR2;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(6)
	if (Pflag[5] == false && Cflag[5] == true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR3;
		dst.m_left = HIT_LEFT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_BLACKSTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR3;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//白星の描画-------------------------------------------------------------------------------------------------


	//(1)
	if (Pflag[0] == true)
	{
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR1;
		dst.m_left = HIT_LEFT_WHITESTAR + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR1;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR2;
		dst.m_left = HIT_LEFT_WHITESTAR + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR2;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR3;
		dst.m_left = HIT_LEFT_WHITESTAR + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR3;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(4)
	if (Pflag[3] == true)
	{
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR1;
		dst.m_left = HIT_LEFT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR1;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[4] == true)
	{
		//(5)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR2;
		dst.m_left = HIT_LEFT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR2;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[5] == true)
	{
		//(6)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR3;
		dst.m_left = HIT_LEFT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_right = HIT_RIGHT_WHITESTAR + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR3;
		Draw::Draw(10, &src, &dst, c, 0.0f);
	}
}