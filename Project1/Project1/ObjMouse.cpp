//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\DrawFont.h"
#include"GameL/SceneManager.h"

#include"ObjMouse.h"
#include"SceneReversibleMain.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjMouse::CObjMouse(bool back)
{
	back_col = back;
}

//イニシャライズ
void CObjMouse::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_l = false;

	m_ani_flame = 0;
	m_time = 0;
	mouse_flag = false;

}

//アクション
void CObjMouse::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_l = Input::GetMouButtonL();

	if (m_mou_l == true)
	{
		mouse_flag = true;
	}
	if (mouse_flag == true)
	{
		//タイムを増やす（ループ中１回のみ）
		m_time += 1;

		//アニメーションを動かす
		if (m_time == 3)
		{
			m_ani_flame += 1;
			m_time = 0;
		}
		//アニメーションが終了したら黒パネルに変更
		if (m_ani_flame == 4)
		{
			m_ani_flame = 0;
			mouse_flag = false;
		}

	}

}
//ドロー
void CObjMouse::Draw()
{	
	float c[4] = { 0.5,1,1,1 };
	float ew[4] = { 1.0f,1.0f,1.0f,1.0f };
	float eb[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 10, 20, 36, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=押してる", 20, 60, 24, c);
	else
		Font::StrDraw(L"L=押してない", 20, 60, 24, c);

	//クリックエフェクト(仮)
	if (mouse_flag == true)
	{
		src.m_top = 72;
		src.m_left = 800 + (m_ani_flame * 40);
		src.m_right = src.m_left + 40;
		src.m_bottom = 112;
		dst.m_top = m_mou_y - 19;
		dst.m_left = m_mou_x - 19;
		dst.m_right = dst.m_left + 40;
		dst.m_bottom = dst.m_top + 40;

		if (back_col == true)
		{
			Draw::Draw(10, &src, &dst, ew, 0.0f);
		}
		else
		{
			Draw::Draw(10, &src, &dst, eb, 0.0f);

		}
	}

}
