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

}

//アクション
void CObjGameSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//スイッチのステージセレクトへ移動
	if (SELECT_POS_L <= x && SELECT_POS_R >= x && SW_SELECT_POS_T <= y && SW_SELECT_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneSwitchSelect());

		}
	}
	//リバーシブルのステージセレクトへ移動
	if (SELECT_POS_L <= x && SELECT_POS_R >= x && RP_SELECT_POS_T <= y && RP_SELECT_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneReversibleSelect());
		}
	}
	//戻るボタン
	if (BACKBUTTON_POS_L <= x && BACKBUTTON_POS_R >= x && BACKBUTTON_POS_T <= y && BACKBUTTON_POS_B >= y)
	{
		if (Input::GetMouButtonL() == true)
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

}

//ドロー
void CObjGameSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//GAME SELECT表示-----------------------------------------------------
	src.m_top   = RESOURCE_SCENE_TEXT_T;
	src.m_left  = RESOURCE_SCENE_TEXT_L;
	src.m_right = RESOURCE_SCENE_TEXT_R;
	src.m_bottom= RESOURCE_SCENE_TEXT_B;
	dst.m_top   = SCENE_TEXT_POS_T;
	dst.m_left  = SCENE_TEXT_POS_L;
	dst.m_right = SCENE_TEXT_POS_R;
	dst.m_bottom= SCENE_TEXT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//SwitchPanel表示-----------------------------------------------------
	src.m_top   = RESOURCE_SW_SELECT_T;
	src.m_left  = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom= RESOURCE_SW_SELECT_B;
	dst.m_top   = SW_SELECT_POS_T;
	dst.m_left  = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom= SW_SELECT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//ReversiblePanel-----------------------------------------------------
	src.m_top   = RESOURCE_RP_SELECT_T;
	src.m_left  = RESOURCE_SELECT_L;
	src.m_right = RESOURCE_SELECT_R;
	src.m_bottom= RESOURCE_RP_SELECT_B;
	dst.m_top   = RP_SELECT_POS_T;
	dst.m_left  = SELECT_POS_L;
	dst.m_right = SELECT_POS_R;
	dst.m_bottom= RP_SELECT_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//戻るボタン-----------------------------------------------------------
	src.m_top   = RESOURCE_BACK_T;
	src.m_left  = RESOURCE_BACK_L;
	src.m_right = RESOURCE_BACK_R;
	src.m_bottom= RESOURCE_BACK_B;
	dst.m_top   = BACKBUTTON_POS_T;
	dst.m_left  = BACKBUTTON_POS_L;
	dst.m_right = BACKBUTTON_POS_R;
	dst.m_bottom= BACKBUTTON_POS_B;
	Draw::Draw(0, &src, &dst, c, 0.0f);

}