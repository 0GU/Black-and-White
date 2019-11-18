//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include "GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjStageSelect.h"
#include"ObjReversibleMain.h"
#include"Windows.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageSelect::Init()
{

}

//アクション
void CObjStageSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//right値が描画とズレていた為調整
	if (120 <= x && 670 >= x && 420 <= y && 510 >= y )
	{

		//この場所を左クリックでリバーシブルのステージセレクトへ
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(300);
			for (int i = 0; i < 3; i++)
			{
				((UserData*)Save::GetData())->RPStageSelect[i] = false;
			}
			((UserData*)Save::GetData())->RPStageSelect[2] = true;
			Save::Seve();
			Scene::SetScene(new CSceneReversibleMain());


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
			Sleep(500);
			Scene::SetScene(new CSceneGameSelect());

		}
	}

}

//ドロー
void CObjStageSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置


	src.m_top = 448.0f;
	src.m_left = 0.0f;
	src.m_right = 560.0f;
	src.m_bottom = 540.0f;
	dst.m_top = 420.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom =510.0;
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

}