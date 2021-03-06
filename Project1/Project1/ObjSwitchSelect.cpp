//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjSwitchSelect.h"
#include"ObjSwitchMain.h"
#include"Windows.h"
#include "MoveScenefunction.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSwitchSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;

	bool set_Pflag[6] = { false, false ,false ,false,false,false };
	bool set_Cflag[6] = { false, false ,false,false,false,false };

	Save::Open();

	for (int i = 0; i < 6; i++)
	{
		if (((UserData*)Save::GetData())->SClearFlag[i] == true)
		{
			set_Cflag[i] = true;
		}

		if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
		{
			set_Pflag[i] = true;
		}
	}
	//フラグを初期化
	memcpy(Pflag, set_Pflag, sizeof(bool)*(6));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(6));
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	memcpy(col_flag, flag_set, sizeof(bool)*(2));

	m_scroll = 0.0f;
	speed = 0.0f;
	scroll_flag = false;

	back = false;
	mou_call = true;

	Rright = 1;
	Rleft = 0;
	buttom_name = 0;

	help_flag = true;
	help_flag2 = true;
	help_flag3 = true;
}

//アクション
void CObjSwitchSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	col_flag[0] = false;
	col_flag[1] = false;


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
				scroll_flag == false && help_flag == true && help_flag2==true && help_flag3 == true)
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
			scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)
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

	//right値が描画とズレていた為調整
	if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_ONE_T <= y && STAGE_SW_SELECT_ONE_B >= y &&
		Rleft == 0 && Rright == 1 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage1
	{
		buttom_name = 1;//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneSwitchMain(1));
		}
		ButtomCol(c_flag, col_flag);
	}
	if (Cflag[0] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_TWO_T <= y && STAGE_SW_SELECT_TWO_B >= y &&
			Rleft == 0 && Rright == 1 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage2
		{
			buttom_name = 2;//明るさ変更用

			if (c_flag[0] == true && c_flag[1] == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				Sleep(SELECT_WAIT);
				Scene::SetScene(new CSceneSwitchMain(2));
			}
			ButtomCol(c_flag, col_flag);
		}
	}
	if (Cflag[1] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_THREE_T <= y && STAGE_SW_SELECT_THREE_B >= y &&
			Rleft == 0 && Rright == 1 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage3
		{
			buttom_name = 3;//明るさ変更用

			if (c_flag[0] == true && c_flag[1] == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				Sleep(SELECT_WAIT);
				Scene::SetScene(new CSceneSwitchMain(3));
			}
			ButtomCol(c_flag, col_flag);
		}
	}
	if (Cflag[2] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_ONE_T <= y && STAGE_SW_SELECT_ONE_B >= y &&
			Rleft == 1 && Rright == 0 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage4
		{
			buttom_name = 4;//明るさ変更用

			if (c_flag[0] == true && c_flag[1] == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				Sleep(SELECT_WAIT);

				Scene::SetScene(new CSceneSwitchMain(4));
			}
			ButtomCol(c_flag, col_flag);
		}
	}
	if (Cflag[3] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_TWO_T <= y && STAGE_SW_SELECT_TWO_B >= y &&
			Rleft == 1 && Rright == 0 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage5
		{
			buttom_name = 5;//明るさ変更用

			if (c_flag[0] == true && c_flag[1] == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				Sleep(SELECT_WAIT);

				Scene::SetScene(new CSceneSwitchMain(5));
			}
			ButtomCol(c_flag, col_flag);
		}
	}
	if (Cflag[4] == true)
	{
		if (STAGE_SW_SELECT_L <= x && STAGE_SW_SELECT_R >= x && STAGE_SW_SELECT_THREE_T <= y && STAGE_SW_SELECT_THREE_B >= y &&
			Rleft == 1 && Rright == 0 && scroll_flag == false && help_flag == true && help_flag2 == true && help_flag3 == true)//stage6
		{
			buttom_name = 6;//明るさ変更用

			if (c_flag[0] == true && c_flag[1] == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				Sleep(SELECT_WAIT);
				Scene::SetScene(new CSceneSwitchMain(6));
			}
			ButtomCol(c_flag, col_flag);
		}
	}
	//戻るボタン
	if (BACKBUTTON_POS_L <= x && BACKBUTTON_POS_R >= x && BACKBUTTON_POS_T <= y && BACKBUTTON_POS_B >= y && 
		help_flag == true && help_flag2 == true && help_flag3 == true)
	{
		buttom_name = 'b';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(2);
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneGameSelect());
		}
		ButtomCol(c_flag, col_flag);
	}

	//背景スクロール
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B_GAP;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B_GAP;

	//ヘルプボタン
	if (POS_HELPBUTTON_L <= x && POS_HELPBUTTON_R >= x && POS_HELPBUTTON_T <= y && POS_HELPBUTTON_B >= y &&
		help_flag == true && help_flag2 == true && help_flag3 == true)
	{
		buttom_name = 'h';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			help_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	if (help_flag == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag = true;
		help_flag2 = false;
		c_flag[0] = false;
	}
	if (help_flag2 == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag2 = true;
		help_flag3 = false;
		c_flag[0] = false;
	}
	if (help_flag3 == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag3 = true;
		c_flag[0] = false;
	}

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
void CObjSwitchSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//ボタン以外、ボタン位置にカーソル
	float	b[4] = { 0.7f,0.7f,0.7f,1.0f };//ボタン通常
	float	t[4] = { 0.4f,0.4f,0.4f,1.0f };//ボタン押している
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置
	//helpボタン
	

	//背景スクロール
	src.m_top = BACKGROUND_TL;
	src.m_left = BACKGROUND_TL;
	src.m_right = BACKGROUND_R;
	src.m_bottom = BACKGROUND_B;

	dst.m_top = BACKGROUND_TL + m_y1;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//ステージを選択してください。
	src.m_top = CUT_STAGE_T;
	src.m_left = CUT_STAGE_L;
	src.m_right = CUT_STAGE_R;
	src.m_bottom = CUT_STAGE_B;	//542x95
	dst.m_top = POS_STAGE_T;
	dst.m_left = POS_STAGE_L;
	dst.m_right = POS_STAGE_R;
	dst.m_bottom = POS_STAGE_B;
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
			if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'r')
				Draw::Draw(0, &src, &dst, b, 0.0f);
			else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'r')
				Draw::Draw(0, &src, &dst, t, 0.0f);
			else
				Draw::Draw(0, &src, &dst, c, 0.0f);
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
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'l')
			Draw::Draw(0, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'l')
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//STAGE1
	src.m_top = RESOURCE_STAGE1_T;
	src.m_left = RESOURCE_STAGE_L;
	src.m_right = RESOURCE_STAGE_R;
	src.m_bottom = RESOURCE_STAGE1_B;
	dst.m_top = STAGE_SW_SELECT_ONE_T;
	dst.m_left = STAGE_SW_SELECT_L + m_scroll;
	dst.m_right = STAGE_SW_SELECT_R_DRAW + m_scroll;
	dst.m_bottom = STAGE_SW_SELECT_ONE_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 1)
		Draw::Draw(0, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 1)
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, c, 0.0f);

	//STAGE2
	if (Cflag[0] == true)
	{
		src.m_top = RESOURCE_STAGE2_T;
		src.m_bottom = RESOURCE_STAGE2_B;
		dst.m_top = STAGE_SW_SELECT_TWO_T;
		dst.m_bottom = STAGE_SW_SELECT_TWO_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 2)
			Draw::Draw(0, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 2)
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//STAGE3
	if (Cflag[1] == true)
	{
		src.m_top = RESOURCE_STAGE3_T;
		src.m_bottom = RESOURCE_STAGE3_B;
		dst.m_top = STAGE_SW_SELECT_THREE_T;
		dst.m_bottom = STAGE_SW_SELECT_THREE_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 3)
			Draw::Draw(0, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 3)
			Draw::Draw(0, &src, &dst, t, 0.0f);
		else
			Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//STAGE4
	if (Cflag[2] == true)
	{
		src.m_top = RESOURCE_STAGE4_T;
		src.m_bottom = RESOURCE_STAGE4_B;
		dst.m_top = STAGE_SW_SELECT_ONE_T;
		dst.m_left = STAGE_SW_SELECT_L + SCROLL_DISTANCE + m_scroll;
		dst.m_right = STAGE_SW_SELECT_R_DRAW + SCROLL_DISTANCE + m_scroll;
		dst.m_bottom = STAGE_SW_SELECT_ONE_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 4)
			Draw::Draw(4, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 4)
			Draw::Draw(4, &src, &dst, t, 0.0f);
		else
			Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	//STAGE5
	if (Cflag[3] == true)
	{
		src.m_top = RESOURCE_STAGE5_T;
		src.m_bottom = RESOURCE_STAGE5_B;
		dst.m_top = STAGE_SW_SELECT_TWO_T;
		dst.m_bottom = STAGE_SW_SELECT_TWO_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 5)
			Draw::Draw(4, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 5)
			Draw::Draw(4, &src, &dst, t, 0.0f);
		else
			Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	//STAGE6
	if (Cflag[4] == true)
	{
		src.m_top = RESOURCE_STAGE6_T;
		src.m_bottom = RESOURCE_STAGE6_B;
		dst.m_top = STAGE_SW_SELECT_THREE_T;
		dst.m_bottom = STAGE_SW_SELECT_THREE_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 6)
			Draw::Draw(4, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 6)
			Draw::Draw(4, &src, &dst, t, 0.0f);
		else
			Draw::Draw(4, &src, &dst, c, 0.0f);
	}

	//戻るボタン
	src.m_top = RESOURCE_BACKBUTTON_T;
	src.m_left = RESOURCE_BACKBUTTON_L;
	src.m_right = RESOURCE_BACKBUTTON_R;
	src.m_bottom = RESOURCE_BACKBUTTON_B;
	dst.m_top = BACKBUTTON_POS_T;
	dst.m_left = BACKBUTTON_POS_L;
	dst.m_right = BACKBUTTON_POS_R;
	dst.m_bottom = BACKBUTTON_POS_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'b')
		Draw::Draw(0, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'b')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, c, 0.0f);

	//黒星の描画---------------------------------------------------------------------------
	src.m_top = RESOURCE_STAR_T;
	src.m_left = RESOURCE_STAR_L;
	src.m_right = RESOURCE_STAR_R;
	src.m_bottom = RESOURCE_STAR_B;
	dst.m_left = STAGE_SW_STAR_L + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + m_scroll;


	//星の描画判定:クリア時orパーフェクト時の場合

	//(1)
	if (Pflag[0] == false && Cflag[0] == true)
	{
		dst.m_top = STAGE_SW_STAR_14_T ;
		dst.m_bottom = STAGE_SW_STAR_14_B ;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 1)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 1)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(2)
	if (Pflag[1] == false && Cflag[1] == true)
	{
		dst.m_top = STAGE_SW_STAR_25_T ;
		dst.m_bottom = STAGE_SW_STAR_25_B ;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 2)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 2)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(3)
	if (Pflag[2] == false && Cflag[2] == true)
	{
		dst.m_top = STAGE_SW_STAR_36_T + m_scroll;
		dst.m_bottom = STAGE_SW_STAR_36_B + m_scroll;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 3)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 3)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	dst.m_left = STAGE_SW_STAR_L + SCROLL_DISTANCE + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + SCROLL_DISTANCE + m_scroll;
	//(4)
	if (Pflag[3] == false && Cflag[3] == true)
	{
		dst.m_top = STAGE_SW_STAR_14_T ;
		dst.m_bottom = STAGE_SW_STAR_14_B ;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 4)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 4)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(5)
	if (Pflag[4] == false && Cflag[4] == true)
	{
		dst.m_top = STAGE_SW_STAR_25_T;
		dst.m_bottom = STAGE_SW_STAR_25_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 5)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 5)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(6)
	if (Pflag[5] == false && Cflag[5] == true)
	{
		dst.m_top = STAGE_SW_STAR_36_T;
		dst.m_bottom = STAGE_SW_STAR_36_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 6)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 6)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//白星の描画---------------------------------------------------------------------------
	//(1)
	src.m_top = RESOURCE_PSTAR_T;
	src.m_left = RESOURCE_PSTAR_L;
	src.m_right = RESOURCE_PSTAR_R;
	src.m_bottom = RESOURCE_PSTAR_B;
	dst.m_left = STAGE_SW_STAR_L + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + m_scroll;


	if (Pflag[0] == true)
	{
		dst.m_top = STAGE_SW_STAR_14_T;
		dst.m_bottom = STAGE_SW_STAR_14_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 1)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 1)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		dst.m_top = STAGE_SW_STAR_25_T;
		dst.m_bottom = STAGE_SW_STAR_25_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 2)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 2)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		dst.m_top = STAGE_SW_STAR_36_T;
		dst.m_bottom = STAGE_SW_STAR_36_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 3)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 3)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	dst.m_left = STAGE_SW_STAR_L + SCROLL_DISTANCE + m_scroll;
	dst.m_right = STAGE_SW_STAR_R + SCROLL_DISTANCE + m_scroll;
	//(4)
	if (Pflag[3] == true)
	{
		dst.m_top = STAGE_SW_STAR_14_T;
		dst.m_bottom = STAGE_SW_STAR_14_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 4)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 4)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(5)
	if (Pflag[4] ==true)
	{
		dst.m_top = STAGE_SW_STAR_25_T;
		dst.m_bottom = STAGE_SW_STAR_25_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 5)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 5)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//(6)
	if (Pflag[5] == true)
	{
		dst.m_top = STAGE_SW_STAR_36_T;
		dst.m_bottom = STAGE_SW_STAR_36_B;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 6)
			Draw::Draw(10, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 6)
			Draw::Draw(10, &src, &dst, t, 0.0f);
		else
			Draw::Draw(10, &src, &dst, c, 0.0f);
	}
	//ヘルプボタン
	src.m_top = CUT_HELPBUTTON_T2;
	src.m_left = CUT_HELPBUTTON_L;
	src.m_right = CUT_HELPBUTTON_R;
	src.m_bottom = CUT_HELPBUTTON_B2;
	dst.m_top = POS_HELPBUTTON_T;
	dst.m_left = POS_HELPBUTTON_L;
	dst.m_right = POS_HELPBUTTON_R;
	dst.m_bottom = POS_HELPBUTTON_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'h')
		Draw::Draw(0, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'h')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, c, 0.0f);
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
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	//ヘルプ表示
	if (help_flag2 == false)
	{
		src.m_top = CUT_HELP_T;
		src.m_left = CUT_HELP_L;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = POS_HELP_T;
		dst.m_left = POS_HELP_L;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//ヘルプ表示
	if (help_flag3 == false)
	{
		src.m_top = CUT_HELP_T;
		src.m_left = CUT_HELP_L;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = POS_HELP_T;
		dst.m_left = POS_HELP_L;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}