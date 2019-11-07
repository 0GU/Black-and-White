//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"GameHead.h"
#include"ObjGameSelect.h"

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

	//RSGのステージセレクトへ移動
	if (400 <= x && 700 >= x && 100 <= y && 490 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			Scene::SetScene(new CSceneStageSelect());

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

	//GAME SELECT表示
	src.m_top = 135.0f;
	src.m_left = 1.0f;
	src.m_right = 560.0f;
	src.m_bottom = 265.0f;
	dst.m_top = 20.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom = 155.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//SwitchPanel表示
	src.m_top = 658.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 750.0f;
	dst.m_top = 200.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.0;
	dst.m_bottom = 292.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//ReversiblePanel
	src.m_top = 746.0f;
	src.m_left = 0.0f;
	src.m_right = 600.0f;
	src.m_bottom = 838.0f;
	dst.m_top = 400.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.0;
	dst.m_bottom = 492.0;
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