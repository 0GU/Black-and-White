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
	m_y1 = 0.0f;
	m_y2 = 600.0f;
}

//アクション
void CObjModeSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_SELECT <= y && HIT_BOTTOM_SELECT >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGameSelect());
		}

	}

	if (HIT_LEFT <= x && HIT_RIGHT >= x && HIT_TOP_GALLERY <= y && HIT_BOTTOM_GALLERY >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			Scene::SetScene(new CSceneGallery());
		}

	}
	//背景スクロール
	m_y1 -= 1.0f;
	if (m_y1 < -600.0f)
		m_y1 = 600;
	m_y2 -= 1.0f;
	if (m_y2 < -600.0f)
		m_y2 = 600;
	
}

//ドロー
void CObjModeSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景スクロール
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 0.0f+m_y1;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f+ m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = 0.0f+ m_y2;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f+ m_y2;
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
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//GameSelect表示
	src.m_top =CUT_PICTURE_TOP;
	src.m_left = CUT_PICTURE_LEFT;
	src.m_right = CUT_PICTURE_RIGHT;
	src.m_bottom = CUT_PICTURE_BOTTOM;
	dst.m_top = HIT_TOP_SELECT;
	dst.m_left = HIT_LEFT;
	dst.m_right = HIT_RIGHT;
	dst.m_bottom = HIT_BOTTOM_SELECT;
	Draw::Draw(1, &src, &dst, c, 0.0f);



}