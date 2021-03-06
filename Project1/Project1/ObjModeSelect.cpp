//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameHead.h"
#include"ObjModeSelect.h"
#include"windows.h"
#include "MoveScenefunction.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjModeSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;
	m_r1 = RESET_POS_CREDIT;
	m_r2 = RESET_POS_CREDIT;
	C_m_y1 = RESET_POS_CREDIT;
	C_m_y2 = RESET_POS_CREDIT;
	
	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	memcpy(col_flag, flag_set, sizeof(bool)*(2));

	back = true;
	mou_call = true;
	credit_flag = true;
	help_flag = true;
	buttom_name = 0;
}

//アクション
void CObjModeSelect::Action()
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

	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_SELECT <= y && HIT_BOTTOM_SELECT >= y &&
		credit_flag == true && help_flag == true)
	{
		buttom_name = 's';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGameSelect());
		}
		ButtomCol(c_flag, col_flag);
	}

	else if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_GALLERY <= y && HIT_BOTTOM_GALLERY >= y &&
			 credit_flag == true && help_flag == true)
	{
		buttom_name = 'g';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGallery());
		}
		ButtomCol(c_flag, col_flag);
	}
	//クレジット
	else if (POS_CREDITBUTTON_L <= x && POS_CREDITBUTTON_R >= x && POS_CREDITBUTTON_T <= y && POS_CREDITBUTTON_B >= y && credit_flag == true && help_flag == true)
	{
		buttom_name = 'c';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			credit_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	//ヘルプ
	else if (POS_BUTTON_HELP_L <= x && POS_BUTTON_HELP_R >= x && POS_BUTTON_HELP_T <= y && POS_BUTTON_HELP_B >= y && credit_flag == true && help_flag == true)
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
	
	else
	{
		col_flag[0] = false;
		col_flag[1] = false;
	}


	if (credit_flag == false&&c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		credit_flag = true;
		c_flag[0] = false;
	}
	if (help_flag == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag = true;
		c_flag[0] = false;
	}
	//背景スクロール
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B;

	//クレジットのスクロール
	m_r1 += 1.5f;
	if (m_r1 > CIRCLE)
		m_r1 = RESET_POS_CREDIT;

	C_m_y1 = sin(3.14 / 180 * m_r1);
	
	m_r2  -= 1.5f;
	if (m_r2 < -CIRCLE)
		m_r2 = RESET_POS_CREDIT;

	C_m_y2 = sin(3.14 / 180 * m_r2);
	C_m_y1 *= CREDIT_MOVE_SPEED;
	C_m_y2 *= CREDIT_MOVE_SPEED;

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
void CObjModeSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//ボタン以外、ボタン位置にカーソル
	float	b[4] = { 0.7f,0.7f,0.7f,1.0f };//ボタン通常
	float	t[4] = { 0.4f,0.4f,0.4f,1.0f };//ボタン押している

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
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//Gallery表示
	src.m_top = CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_GALLERY;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_GALLERY;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'g')
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'g')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, b, 0.0f);

	//GameSelect表示
	src.m_top = CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_SELECT;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_SELECT;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 's')
		Draw::Draw(1, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 's')
		Draw::Draw(1, &src, &dst, t, 0.0f);
	else
		Draw::Draw(1, &src, &dst, b, 0.0f);

	//まとめ表示
	src.m_top = CUT_CONCLUSION_T;
	src.m_left = CUT_CONCLUSION_L;
	src.m_right = CUT_CONCLUSION_R;
	src.m_bottom = CUT_CONCLUSION_B;
	dst.m_top = POS_CONCLUSION_T;
	dst.m_left = POS_CONCLUSION_L;
	dst.m_right = POS_CONCLUSION_R;
	dst.m_bottom = POS_CONCLUSION_B;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//クレジットボタン
	src.m_top = CUT_CREDITBUTTON_T;
	src.m_left = CUT_CREDITBUTTON_L;
	src.m_right = CUT_CREDITBUTTON_R;
	src.m_bottom = CUT_CREDITBUTTON_B;
	dst.m_top = POS_CREDITBUTTON_T;
	dst.m_left = POS_CREDITBUTTON_L;
	dst.m_right = POS_CREDITBUTTON_R;
	dst.m_bottom = POS_CREDITBUTTON_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, t, 0.0f);
	else
		Draw::Draw(5, &src, &dst, b, 0.0f);
	//helpボタン
	src.m_top = CUT_BUTTON_HELP_T;
	src.m_left = CUT_BUTTON_HELP_L;
	src.m_right = CUT_BUTTON_HELP_R;
	src.m_bottom = CUT_BUTTON_HELP_B;
	dst.m_top = POS_BUTTON_HELP_T;
	dst.m_left = POS_BUTTON_HELP_L;
	dst.m_right = POS_BUTTON_HELP_R;
	dst.m_bottom = POS_BUTTON_HELP_B;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'h')
		Draw::Draw(5, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'h')
		Draw::Draw(5, &src, &dst, t, 0.0f);
	else
		Draw::Draw(5, &src, &dst, b, 0.0f);
	//クレジット表示
	if (credit_flag == false)
	{
		src.m_top = CUT_CREDIT_T;
		src.m_left = CUT_CREDIT_L;
		src.m_right = CUT_CREDIT_R;
		src.m_bottom = CUT_CREDIT_B;
		dst.m_top = POS_CREDIT_T;
		dst.m_left = POS_CREDIT_L;
		dst.m_right = POS_CREDIT_R;
		dst.m_bottom = POS_CREDIT_B;
		Draw::Draw(4, &src, &dst, c, 0.0f);
		
		src.m_top = CUT_CRE_OBJ_TOP_LEFT;
		src.m_left = CUT_LEFT_CRE_OBJ_L;
		src.m_right = CUT_LEFT_CRE_OBJ_R;
		src.m_bottom = CUT_LEFT_CRE_OBJ_B;
		dst.m_top = POS_LEFT_CRE_OBJ_T+C_m_y1;
		dst.m_left = POS_LEFT_CRE_OBJ_L;
		dst.m_right = POS_LEFT_CRE_OBJ_R;
		dst.m_bottom = POS_LEFT_CRE_OBJ_B+C_m_y1;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		src.m_top = CUT_CRE_OBJ_TOP_LEFT;
		src.m_left = CUT_CRE_OBJ_TOP_LEFT;
		src.m_right = CUT_RIGHT_CRE_OBJ_R;
		src.m_bottom = CUT_RIGHT_CRE_OBJ_B;
		dst.m_top = POS_RIGHT_CRE_OBJ_T +C_m_y2;
		dst.m_left = POS_RIGHT_CRE_OBJ_L;
		dst.m_right = POS_RIGHT_CRE_OBJ_R;
		dst.m_bottom = POS_RIGHT_CRE_OBJ_B +C_m_y2;
		Draw::Draw(7, &src, &dst, c, 0.0f);
		
	}
	
	//ヘルプ表示
	if (help_flag == false)
	{
		src.m_top = HELP_TOP_LEFT;
		src.m_left = HELP_TOP_LEFT;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = HELP_TOP_LEFT;
		dst.m_left = HELP_TOP_LEFT;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}