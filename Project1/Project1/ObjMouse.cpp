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
		//アニメーションが終了したら初期化
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
	/*wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 10, 20, 36, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=押してる", 20, 60, 24, c);
	else
		Font::StrDraw(L"L=押してない", 20, 60, 24, c);
		*/
	//クリックエフェクト(仮)
	if (mouse_flag == true)
	{
		src.m_top = CUT_CLICK_EFFECT_T;
		src.m_left = CUT_CLICK_EFFECT_L + (m_ani_flame * CLICK_EFFECT_40);
		src.m_right = src.m_left + CLICK_EFFECT_40;
		src.m_bottom = CUT_CLICK_EFFECT_B;
		dst.m_top = m_mou_y - CLICK_EFFECT_19;
		dst.m_left = m_mou_x - CLICK_EFFECT_19;
		dst.m_right = dst.m_left + CLICK_EFFECT_40;
		dst.m_bottom = dst.m_top + CLICK_EFFECT_40;

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

//ButtomCol関数---------------------------------------------------------------------------
//引数1　bool click[2]	：クリック状態を判別するフラグ変数
//引数2　bool *color	：ボタンの明るさフラグのポインタ
//戻り値　無し
//内容：クリック状態に応じてボタンの明るさフラグを変更する
void ButtomCol(bool click[2], bool*color)
{
	if (click[0] == false && click[1] == true)
	{
		*color = true;
		*(color + 1) = false;
	}
	if (click[0] == true && click[1] == false)
	{
		*color = false;
		*(color + 1) = true;
	}

}