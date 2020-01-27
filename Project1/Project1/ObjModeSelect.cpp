//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameHead.h"
#include"ObjModeSelect.h"
#include"windows.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjModeSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;

	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;
	credit_flag = true;
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
		credit_flag == true)
	{
		buttom_name = 's';

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
			 credit_flag == true)
	{
		buttom_name = 'g';

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
	else if (460.0f <= x && 680.0f >= x && 480.0f <= y && 580.0f >= y && credit_flag == true)
	{
		buttom_name = 'c';

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
	src.m_top = 456.0f;
	src.m_left = 1.0f;
	src.m_right = 658.0f;
	src.m_bottom = 543.0f;
	dst.m_top = 20.0f;
	dst.m_left = 80.0f;
	dst.m_right = 740.0f;
	dst.m_bottom = 110.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//クレジットボタン
	src.m_top = 927.0f;
	src.m_left = 0.0f;
	src.m_right = 150.0f;
	src.m_bottom = 998.0f;
	dst.m_top = 480.0f;
	dst.m_left = 460.0f;
	dst.m_right = 680.0f;
	dst.m_bottom = 580.0f;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'c')
		Draw::Draw(5, &src, &dst, t, 0.0f);
	else
		Draw::Draw(5, &src, &dst, b, 0.0f);

	//クレジット表示
	if (credit_flag == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 620.0f;
		src.m_bottom = 450.0f;
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
}