//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"
#include"windows.h"
#include"GameHead.h"
#include"ObjTitle.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define WINDOW_SIZE_X (800.0f)
#define WINDOW_SIZE_Y (600.0f)
#define CLICK_WAIT (300)

//イニシャライズ
void CObjTitle::Init()
{
	Save::Open();

/*	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			((UserData*)Save::GetData())->SPerfectFlag[i] = false;
			((UserData*)Save::GetData())->SClearFlag[i] = false;
		}

		((UserData*)Save::GetData())->RPerfectFlag[i] = false;
		((UserData*)Save::GetData())->RClearFlag[i] = false;
	}*/
	//(UserData*)Save::Seve;

	//フラグを初期化
	bool flag_set[2] =
	{ false,false };
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;
}

//アクション
void CObjTitle::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//クリックエフェクト呼び出し（１回のみ）
	if (mou_call == true)
	{
		CObjMouse*m = new CObjMouse(back);
		Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
		mou_call = false;
	}

	//クリック判別
	//[0]のみ true = 押している状態　
	//[1]のみ true = 押していない状態
	//両方    true = 押してから離した状態
	if (Input::GetMouButtonL() == true)
	{
		c_flag[0] = true;
		c_flag[1] = false;
	}

	if (Input::GetMouButtonL() == false)
	{
		c_flag[1] = true;
	}



	if (0 <= x && WINDOW_SIZE_X >= x && 0 <= y && WINDOW_SIZE_Y >= y &&
		c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(CLICK_WAIT);
		Scene::SetScene(new CSceneModeSelect());
	}
	if (Input::GetVKey(VK_UP) == true && Input::GetVKey(VK_DOWN) == true)
	{
		for (int i = 0; i < 6; i++)
		{

			((UserData*)Save::GetData())->SPerfectFlag[i] = true;
			((UserData*)Save::GetData())->SClearFlag[i] = true;

			((UserData*)Save::GetData())->RPerfectFlag[i] = true;
			((UserData*)Save::GetData())->RClearFlag[i] = true;
		}
		Save::Seve();
	}

	if (Input::GetVKey('R') == true && Input::GetVKey('S') == true)
	{
		for (int i = 0; i < 6; i++)
		{

			((UserData*)Save::GetData())->SPerfectFlag[i] = false;
			((UserData*)Save::GetData())->SClearFlag[i] = false;

			((UserData*)Save::GetData())->RPerfectFlag[i] = false;
			((UserData*)Save::GetData())->RClearFlag[i] = false;
		}
		Save::Seve();
	}

	//ボタン類がない、もしくは動作が終わったら押していない状態に戻す
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
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
	src.m_right = WINDOW_SIZE_X;
	src.m_bottom = WINDOW_SIZE_Y;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom = WINDOW_SIZE_Y;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	Font::StrDraw(L"クリックしてスタート！", 230, 500, 32, c);
}