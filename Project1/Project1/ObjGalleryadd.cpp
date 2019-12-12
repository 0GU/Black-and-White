//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/Audio.h"
#include"windows.h"
#include"GameHead.h"
#include"ObjGalleryadd.h"
//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGalleryadd::Init()
{

}

//アクション
void CObjGalleryadd::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	if (0 <= x && WINDOW_SIZE_X >= x && 0 <= y && WINDOW_SIZE_Y >= y)
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
				Sleep(CLICK_WAIT);

				Scene::SetScene(new CSceneModeSelect());

			}
		}

	}
}

//ドロー
void CObjGalleryadd::Draw()
{
	// 描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = WINDOW_SIZE_X;
	src.m_bottom = WINDOW_SIZE_Y;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom = WINDOW_SIZE_Y;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//