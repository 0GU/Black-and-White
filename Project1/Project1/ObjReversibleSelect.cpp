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

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//イニシャライズ
void CObjReversibleSelect::Init()
{
	
	bool set_flag[3] = { false, false ,false};

	Save::Open();

	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			set_flag[i] = true;
		}
	}
	memcpy(flag, set_flag, sizeof(bool)*(3));
	
}

//アクション
void CObjReversibleSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();





	//right値が描画とズレていた為調整
	if (120 <= x && 670 >= x && 160 <= y && 250 >= y)
	{

		//この場所を左クリックでリバーシブルのステージ1へ
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
		
			Scene::SetScene(new CSceneReversibleMain(1));


		}
	}
	if (120 <= x && 670 >= x && 290 <= y && 380 >= y )
	{

		//この場所を左クリックでリバーシブルのステージ2へ
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
			
			Scene::SetScene(new CSceneReversibleMain(2));


		}
	}
	if (120 <= x && 670 >= x && 420 <= y && 510 >= y)
	{

		//この場所を左クリックでリバーシブルのステージ3へ
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);
		
			Scene::SetScene(new CSceneReversibleMain(3));


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

	/*
	//仮置き:後に削除-----------------------------
	if (500 <= x && 540 >= x && 0 <= y && 40 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (flag[0] == false)
			{
				flag[0] = true;
			}
			else if(flag[0]==true)
			{
				flag[0] = false;
			}
			//SEを鳴らす
			Audio::Start(2);

			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(200);


		}

		
	}

	if (540 <= x && 580 >= x && 0 <= y && 40 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (flag[1] == false)
			{
				flag[1] = true;
			}
			else if (flag[1] == true)
			{
				flag[1] = false;
			}
			//SEを鳴らす
			Audio::Start(1);

			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(200);
		}
	}

	if (580 <= x && 620 >= x && 0 <= y && 40 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (flag[2] == false)
			{
				flag[2] = true;
			}
			else if (flag[2] == true)
			{
				flag[2] = false;
			}
			//SEを鳴らす
			Audio::Start(1);

			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(200);
		}
	}*/
	//---------------------------------------------
}

//ドロー
void CObjReversibleSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用



	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//Stage1の描画
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 90.0f;
	dst.m_top = 160.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 250.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//Stage2の描画
	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 180.0f;
	dst.m_top = 290.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 380.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//Stage3の描画
	src.m_top = 180.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 271.0f;
	dst.m_top = 420.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
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
	Draw::Draw(1, &src, &dst, c, 0.0f);


	//黒星の描画---------------------------------------------------------------------------



	//(1)
	if (flag[0] == false)
	{
		src.m_top = 1.5f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 40.0f;
		dst.m_top = 184.0f;
		dst.m_left = 268.0f;
		dst.m_right = 307.0;
		dst.m_bottom = 225.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//(2)
	 if (flag[1] == false)
	{
		src.m_top = 1.5f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 40.0f;	
		dst.m_top = 314.0f;
		dst.m_left = 268.0f;
		dst.m_right = 307.0;
		dst.m_bottom = 353.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);
}
	//(3)
	 if (flag[2] == false)
	 {
		 src.m_top = 1.5f;
		 src.m_left = 562.0f;
		 src.m_right = 600.0f;
		 src.m_bottom = 40.0f;
		 dst.m_top = 445.0f;
		 dst.m_left = 268.0f;
		 dst.m_right = 307.0;
		 dst.m_bottom = 483.0;
		 Draw::Draw(0, &src, &dst, c, 0.0f);
	 }
	//白星の描画---------------------------------------------------------------------------


	//(1)
	if (flag[0] == true)
	{
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 184.0f;
		dst.m_left = 268.0f;
		dst.m_right = 307.0;
		dst.m_bottom = 225.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	if (flag[1] == true)
	{
		//(2)
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 314.0f;
		dst.m_left = 268.0f;
		dst.m_right = 307.0;
		dst.m_bottom = 353.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	if (flag[2] == true)
	{
		//(3)
		src.m_top = 43.0f;
		src.m_left = 562.0f;
		src.m_right = 600.0f;
		src.m_bottom = 82.0f;
		dst.m_top = 445.0f;
		dst.m_left = 268.0f;
		dst.m_right = 307.0;
		dst.m_bottom = 483.0;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//仮置:チェンジ------------------------
	/*dst.m_top = 0.0f;
	dst.m_left = 500.0f;
	dst.m_right = 540.0;
	dst.m_bottom = 40.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	dst.m_top = 0.0f;
	dst.m_left = 540.0f;
	dst.m_right = 580.0;
	dst.m_bottom = 40.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	dst.m_top = 0.0f;
	dst.m_left = 580.0f;
	dst.m_right = 620.0;
	dst.m_bottom = 40.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	//切り替えが出来たら削除-------------
	*/
}