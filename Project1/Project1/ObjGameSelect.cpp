//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "Windows.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;
	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	memcpy(col_flag, flag_set, sizeof(bool)*(2));

	back = true;
	mou_call = true;
	but = 0;
}

//アクション
void CObjGameSelect::Action()
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

	//スイッチのステージセレクトへ移動
	if (SELECT_POS_L <= x && SELECT_POS_R >= x && SW_SELECT_POS_T <= y && SW_SELECT_POS_B >= y)
	{
		but = 's';
		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneSwitchSelect());
		}
		ButtomCol(c_flag, col_flag);
	}
	//リバーシブルのステージセレクトへ移動
	else if (SELECT_POS_L <= x && SELECT_POS_R >= x && RP_SELECT_POS_T <= y && RP_SELECT_POS_B >= y )
	{
		but = 'r';
		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleSelect());
		}
		ButtomCol(c_flag, col_flag);
	}
	//戻るボタン
	else if (BACKBUTTON_POS_L <= x && BACKBUTTON_POS_R >= x && BACKBUTTON_POS_T <= y && BACKBUTTON_POS_B >= y )
	{
		but = 'b';
		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(2);
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneModeSelect());
		}
		ButtomCol(c_flag, col_flag);
	}
	else
	{
		col_flag[0] = false;
		col_flag[1] = false;
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
void CObjGameSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//ボタン以外、ボタン位置にカーソル
	float	b[4] = { 0.8f,0.8f,0.8f,1.0f };//ボタン通常
	float	t[4] = { 0.6f,0.6f,0.6f,1.0f };//ボタン押している

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
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//GAME SELECT表示-----------------------------------------------------
	src.m_top = RESOURCE_SCENE_TEXT_T;
	src.m_left = RESOURCE_SCENE_TEXT_L;
	src.m_right = RESOURCE_SCENE_TEXT_R;
	src.m_bottom = RESOURCE_SCENE_TEXT_B;
	dst.m_top = SCENE_TEXT_POS_T;
	dst.m_left = SCENE_TEXT_POS_L;
	dst.m_right = SCENE_TEXT_POS_R;
	dst.m_bottom = SCENE_TEXT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//SwitchPanel表示-----------------------------------------------------
	src.m_top = RESOURCE_SW_SELECT_T;
	src.m_left = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom = RESOURCE_SW_SELECT_B;
	dst.m_top = SW_SELECT_POS_T;
	dst.m_left = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom = SW_SELECT_POS_B;
	
	 if(col_flag[0]==true&&col_flag[1]==false && but == 's')
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else if(col_flag[0]==false&&col_flag[1]==true&& but == 's')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else 
		Draw::Draw(0, &src, &dst, b, 0.0f);
	//ReversiblePanel-----------------------------------------------------
	src.m_top = RESOURCE_RP_SELECT_T;
	src.m_left = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom = RESOURCE_RP_SELECT_B;
	dst.m_top = RP_SELECT_POS_T;
	dst.m_left = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom = RP_SELECT_POS_B;
	
	if (col_flag[0] == true && col_flag[1] == false&&but=='r')
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && but == 'r')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else 
		Draw::Draw(0, &src, &dst, b, 0.0f);

	//戻るボタン-----------------------------------------------------------
	src.m_top = RESOURCE_BACK_T;
	src.m_left = RESOURCE_BACK_L;
	src.m_right = RESOURCE_BACK_R;
	src.m_bottom = RESOURCE_BACK_B;
	dst.m_top = BACKBUTTON_POS_T;
	dst.m_left = BACKBUTTON_POS_L;
	dst.m_right = BACKBUTTON_POS_R;
	dst.m_bottom = BACKBUTTON_POS_B;
	if (col_flag[0] == true && col_flag[1] == false && but == 'b')
		Draw::Draw(0, &src, &dst, c, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && but == 'b')
		Draw::Draw(0, &src, &dst, t, 0.0f);
	else
		Draw::Draw(0, &src, &dst, b, 0.0f);

}