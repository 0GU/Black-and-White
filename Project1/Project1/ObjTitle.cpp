//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"windows.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_time = 0;
}

//アクション
void CObjTitle::Action()
{

	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	if (0 <= x && 800 >= x && 0 <= y && 600 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(500);
			
				Scene::SetScene(new CSceneModeSelect());
				
			}
		}
		
	}
}

//ドロー
void CObjTitle::Draw()
{
	// 描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//戻るボタン
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}