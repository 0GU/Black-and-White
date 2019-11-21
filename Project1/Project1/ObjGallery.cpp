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

#define HIT_BACK_TOP (35.0f)
#define HIT_BACK_LEFT (5.0f)
#define HIT_BACK_RIGHT (125.0f)
#define HIT_BACK_BOTTOM (135.0f)

#define HIT_RIGHTARROW_TOP (240.0f)
#define HIT_RIGHTARROW_LEFT (700.0f)
#define HIT_RIGHTARROW_RIGHT (775.0f)
#define HIT_RIGHTARROW_BOTTOM (360.0f)

#define HIT_LEFTARROW_TOP (245.0f)
#define HIT_LEFTARROW_LEFT (26.0f)
#define HIT_LEFTARROW_RIGHT (101.0f)
#define HIT_LEFTARROW_BOTTOM (365.0f)

#define CUT_BACK_TOP (35.0f)
#define CUT_BACK_LEFT (5.0f)
#define HIT_BACK_RIGHT (125.0f)
#define HIT_BACK_BOTTOM (135.0f)

#define HIT_RIGHTARROW_TOP (240.0f)
#define HIT_RIGHTARROW_LEFT (700.0f)
#define HIT_RIGHTARROW_RIGHT (775.0f)
#define HIT_RIGHTARROW_BOTTOM (360.0f)

#define HIT_LEFTARROW_TOP (245.0f)
#define HIT_LEFTARROW_LEFT (26.0f)
#define HIT_LEFTARROW_RIGHT (101.0f)
#define HIT_LEFTARROW_BOTTOM (365.0f)
//#define
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

}

//アクション
void CObjGallery::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	
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
	if (HIT_BACK_LEFT <= x && HIT_BACK_RIGHT >= x && HIT_BACK_TOP <= y && HIT_BACK_BOTTOM >= y)
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

	if (Gright == 1)
	{
		//右矢印
		if (HIT_RIGHTARROW_LEFT <= x && HIT_RIGHTARROW_RIGHT >= x && HIT_RIGHTARROW_TOP <= y && HIT_RIGHTARROW_BOTTOM >= y)
		{
			if (Input::GetMouButtonL() == true)
			{
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);
				Gright = 0;
				Gleft = 1;

			}
		}
	}
	if (Gleft == 1)
	{
		//左矢印
		if (HIT_LEFTARROW_LEFT <= x &&HIT_LEFTARROW_RIGHT >= x && HIT_LEFTARROW_TOP <= y && HIT_LEFTARROW_BOTTOM >= y)
		{
			if (Input::GetMouButtonL() == true)
			{
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);
				Gleft = 0;
				Gright = 1;

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
	src.m_top = 139.0f;
	src.m_left = 559.0f;
	src.m_right = 679.0f;
	src.m_bottom = 239.0f;
	dst.m_top = HIT_BACK_TOP;
	dst.m_left = HIT_BACK_LEFT;
	dst.m_right = HIT_BACK_RIGHT;
	dst.m_bottom = HIT_BACK_BOTTOM;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	if (Gright == 1)
	{
		//矢印ボタン
		src.m_top = 0.0f;
		src.m_left = 559.0f;
		src.m_right = 639.0f;
		src.m_bottom = 140.0f;
		dst.m_top =HIT_RIGHTARROW_TOP;
		dst.m_left = HIT_RIGHTARROW_LEFT;
		dst.m_right = HIT_RIGHTARROW_RIGHT;
		dst.m_bottom = HIT_RIGHTARROW_BOTTOM;
		Draw::Draw(0, &src, &dst, c, 0.0f);

		//仮枠
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 50.0f;
		dst.m_left = 145.0f;
		dst.m_right = 657.0f;
		dst.m_bottom = 560.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		//仮表示
		if (SFlag[0]==true && SFlag[1] == true && SFlag[2] == true)
		{
			//ギャラリー開放(仮)
			src.m_top = 0.0f;
			src.m_left = 559.0f;
			src.m_right = 639.0f;
			src.m_bottom = 140.0f;
			dst.m_top = 245.0f;
			dst.m_left = 300.0f;
			dst.m_right = 375.0;
			dst.m_bottom = 385.0;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}

	}

	if (Gleft == 1)
	{
		//左矢印ボタン
		src.m_top = 0.0f;
		src.m_left = 638.0f;
		src.m_right = 718.0f;
		src.m_bottom = 140.0f;
		dst.m_top = HIT_LEFTARROW_TOP;
		dst.m_left = HIT_LEFTARROW_LEFT;
		dst.m_right = HIT_LEFTARROW_RIGHT;
		dst.m_bottom = HIT_LEFTARROW_BOTTOM;
		Draw::Draw(0, &src, &dst, c, 0.0f);

		//仮枠
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 50.0f;
		dst.m_left = 145.0f;
		dst.m_right = 657.0f;
		dst.m_bottom = 560.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		//仮表示
		if (RFlag[0] == true && RFlag[1] == true && RFlag[2] == true)
		{
			//ギャラリー開放(仮)
			src.m_top = 0.0f;
			src.m_left = 559.0f;
			src.m_right = 639.0f;
			src.m_bottom = 140.0f;
			dst.m_top = 245.0f;
			dst.m_left = 300.0f;
			dst.m_right = 375.0;
			dst.m_bottom = 385.0;
			Draw::Draw(0, &src, &dst, c, 0.0f);

		}
	}

}