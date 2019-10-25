//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

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

}

//ドロー
void CObjGameSelect::Draw()
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
	dst.m_top = 30.0f;
	dst.m_left = 120.0f;
	dst.m_right = 600.0;
	dst.m_bottom = 150.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);



}