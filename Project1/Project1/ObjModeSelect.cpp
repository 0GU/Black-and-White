//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"UtilityModule.h"
#include"ObjModeSelect.h"
#include"windows.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjModeSelect::Init()
{

}

//アクション
void CObjModeSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	if (119 <= x && 670 >= x && 320 <= y && 455 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{
					
				}
				Sleep(100);
			Scene::SetScene(new CSceneGallery());
		}

	}

	if (119 <= x && 670 >= x && 125 <= y && 260 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{
				
			}
			Sleep(100);
			Scene::SetScene(new CSceneGameSelect());
		}

	}
}

//ドロー
void CObjModeSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 135.0f;
	dst.m_top = 330.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 465.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 561.0f;
	src.m_bottom = 135.0f;
	dst.m_top = 135.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 265.0;
	Draw::Draw(1, &src, &dst, c, 0.0f);



}