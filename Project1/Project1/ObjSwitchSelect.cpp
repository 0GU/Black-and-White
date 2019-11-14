//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include "GameL/UserData.h"
#include"GameHead.h"
#include"ObjSwitchSelect.h"
#include"ObjSwitchMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSwitchSelect::Init()
{

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
			while (Input::GetMouButtonL() == true)
			{

			}
			for (int i = 0; i < 3; i++)
			{
				((UserData*)Save::GetData())->SPStageSelect[i] = false;
			}
			((UserData*)Save::GetData())->SPStageSelect[0] = true;
			Save::Seve();
			Scene::SetScene(new CSceneSwitchMain());
		}
	}
	else if (120 <= x && 670 >= x && 300 <= y && 390 >= y)//stage2
	{
		if (Input::GetMouButtonL() == true)
		{
			while (Input::GetMouButtonL() == true)
			{

			}
			for (int i = 0; i < 3; i++)
			{
				((UserData*)Save::GetData())->SPStageSelect[i] = false;
			}
			((UserData*)Save::GetData())->SPStageSelect[1] = true;
			Save::Seve();
			Scene::SetScene(new CSceneSwitchMain());

		}
	}
	else if (120 <= x && 670 >= x && 420 <= y && 510 >= y)//stage3
	{
		if (Input::GetMouButtonL() == true)
		{
			while (Input::GetMouButtonL() == true)
			{

			}
			for (int i = 0; i < 3; i++)
			{
				((UserData*)Save::GetData())->SPStageSelect[i] = false;
			}
			((UserData*)Save::GetData())->SPStageSelect[2] = true;
			Save::Seve();
			Scene::SetScene(new CSceneSwitchMain());
			
		}
	}

	//戻るボタン
	if (5 <= x && 125 >= x && 35 <= y && 135 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			while (Input::GetMouButtonL() == true)
			{

			}
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
	src.m_top = 267.0f;
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
	dst.m_right = 225.0;
	dst.m_bottom = 135.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

}