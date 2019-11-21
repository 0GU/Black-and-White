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

//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//イニシャライズ
void CObjSwitchSelect::Init()
{
	bool set_Pflag[3] = { false, false ,false };
	bool set_Cflag[3] = { false, false ,false };

	Save::Open();

	for (int i = 0; i < 3; i++)
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
	memcpy(Pflag, set_Pflag, sizeof(bool)*(3));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(3));
}

//アクション
void CObjSwitchSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//right値が描画とズレていた為調整
	if (120 <= x && 670 >= x && 180 <= y && 270 >= y)//stage1
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			
			
			Scene::SetScene(new CSceneSwitchMain(1));
		}
	}
	else if (120 <= x && 670 >= x && 300 <= y && 390 >= y)//stage2
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			
			
			Scene::SetScene(new CSceneSwitchMain(2));

		}
	}
	else if (120 <= x && 670 >= x && 420 <= y && 510 >= y)//stage3
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			
			
			Scene::SetScene(new CSceneSwitchMain(3));
			
		}
	}

	//戻るボタン
	if (5 <= x && 125 >= x && 35 <= y && 135 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(2);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneGameSelect());

		}
	}

}

//ドロー
void CObjSwitchSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//STAGE1
	src.m_top = 268.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 359.0f;
	dst.m_top = 180.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 270.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//STAGE2
	src.m_top = 358.0f;
	src.m_left = 0.0f;
	src.m_right = 560.0f;
	src.m_bottom = 449.0f;
	dst.m_top = 300.0f;
	dst.m_bottom = 390.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//STAGE3
	src.m_top = 448.0f;
	src.m_bottom = 540.0f;
	dst.m_top = 420.0f;
	dst.m_bottom = 510.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//戻るボタン
	src.m_top = 139.0f;
	src.m_left = 559.0f;
	src.m_right = 679.0f;
	src.m_bottom = 239.0f;
	dst.m_top = 35.0f;
	dst.m_left = 5.0f;
	dst.m_right = 125.0;
	dst.m_bottom = 135.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//黒星の描画---------------------------------------------------------------------------

	//(1)
	if (Pflag[0] == false && Cflag[0] == true)
	{
		src.m_top = 1.5f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 40.0f;
		dst.m_top = 206.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 245.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//(2)
	if (Pflag[1] == false && Cflag[1] == true)
	{
		src.m_top = 1.5f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 40.0f;
		dst.m_top = 324.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 363.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//(3)
	if (Pflag[2] == false && Cflag[2] == true)
	{
		src.m_top = 1.5f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 40.0f;
		dst.m_top = 442.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 481.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	//白星の描画---------------------------------------------------------------------------
	//(1)
	if (Pflag[0] == true)
	{
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 206.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 245.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 324.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 363.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 442.0f;
		dst.m_left = 281.0f;
		dst.m_right = 320.0;
		dst.m_bottom = 481.0;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}