//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\DrawFont.h"
#include"GameL/SceneManager.h"

#include"ObjMouse.h"
#include"SceneReversibleMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMouse::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_l = false;
}

//アクション
void CObjMouse::Action()
{

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_l = Input::GetMouButtonL();
}
//ドロー
void CObjMouse::Draw()
{	
	float c[4] = { 0.5,1,1,1 };
	/*
	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 10, 20, 36, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=押してる", 20, 60, 24, c);
	else
		Font::StrDraw(L"L=押してない", 20, 60, 24, c);*/
}
