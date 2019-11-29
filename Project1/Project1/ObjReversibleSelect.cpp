//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjReversibleSelect.h"
#include"ObjReversibleMain.h"
#include"Windows.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjReversibleSelect::Init()
{
	m_y1 = BACKGROUND_TL;
	m_y2 = BACKGROUND_B;

	bool set_Pflag[3] = { false, false ,false};
	bool set_Cflag[3] = { false, false ,false };

	Save::Open();

	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->RClearFlag[i] == true)
		{
			set_Cflag[i] = true;
		}

		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			set_Pflag[i] = true;
		}
	}
	memcpy(Pflag, set_Pflag, sizeof(bool)*(3));
	memcpy(Cflag, set_Cflag, sizeof(bool)*(3));
	
}

//アクション
void CObjReversibleSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();





	//right値が描画とズレているため右方向を-10.0f調整
	//Stage1--------------------------------------------------------------
	if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP1 <= y && HIT_BOTTOM_RP1 >= y)
	{

		//この場所を左クリックでリバーシブルのステージ1へ
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SELECT_WAIT);

			Scene::SetScene(new CSceneReversibleMain(1));


		}
	}


	//Stage2----------------------------------------------------------------
	if (Cflag[0] == true)
	{
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP2 <= y && HIT_BOTTOM_RP2 >= y)
		{

			//この場所を左クリックでリバーシブルのステージ2へ
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);

				Scene::SetScene(new CSceneReversibleMain(2));


			}
		}
	}


	//Stage3----------------------------------------------------------------
	if (Cflag[1] == true)
	{
		if (HIT_LEFT_RP <= x && HIT_RIGHT_RP - 10.0f >= x && HIT_TOP_RP3 <= y && HIT_BOTTOM_RP3 >= y)
		{

			//この場所を左クリックでリバーシブルのステージ3へ
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Sleep(SELECT_WAIT);

				Scene::SetScene(new CSceneReversibleMain(3));


			}
		}
	}

	//戻るボタン
	if (HIT_LEFT_SCENEBACK <= x && HIT_RIGHT_SCENEBACK >= x && HIT_TOP_SCENEBACK <= y && HIT_BOTTOM_SCENEBACK >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			//SEを鳴らす
			Audio::Start(2);
			while (Input::GetMouButtonL() == true)
			{

			}
			Sleep(SCENEBACK_WAIT);
			Scene::SetScene(new CSceneGameSelect());

		}
	}
	//背景スクロール
	m_y1 -= BACKGROUND_T_GAP;
	if (m_y1 < -BACKGROUND_B)
		m_y1 = BACKGROUND_B;
	m_y2 -= BACKGROUND_T_GAP;
	if (m_y2 < -BACKGROUND_B)
		m_y2 = BACKGROUND_B;
}

//ドロー
void CObjReversibleSelect::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用



	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景スクロール
	src.m_top = BACKGROUND_TL;
	src.m_left = BACKGROUND_TL;
	src.m_right = BACKGROUND_R;
	src.m_bottom = BACKGROUND_B;

	dst.m_top = BACKGROUND_TL + m_y1;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y1;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//背景リスタート
	dst.m_top = BACKGROUND_TL + m_y2;
	dst.m_left = BACKGROUND_TL;
	dst.m_right = BACKGROUND_R;
	dst.m_bottom = BACKGROUND_B + m_y2;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//Stage1の描画
	src.m_top = CUT_PIC_TOP_RP1;
	src.m_left = CUT_PIC_LEFT_RP;
	src.m_right = CUT_PIC_RIGHT_RP;
	src.m_bottom = CUT_PIC_BOTTOM_RP1;
	dst.m_top = HIT_TOP_RP1;
	dst.m_left = HIT_LEFT_RP;
	dst.m_right = HIT_RIGHT_RP;
	dst.m_bottom = HIT_BOTTOM_RP1;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//Stage2の描画
	if (Cflag[0] == true)
	{
		src.m_top = CUT_PIC_TOP_RP2;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP2;
		dst.m_top = HIT_TOP_RP2;
		dst.m_left = HIT_LEFT_RP;
		dst.m_right = HIT_RIGHT_RP;
		dst.m_bottom = HIT_BOTTOM_RP2;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//Stage3の描画
	if (Cflag[1] == true)
	{
		src.m_top = CUT_PIC_TOP_RP3;
		src.m_left = CUT_PIC_LEFT_RP;
		src.m_right = CUT_PIC_RIGHT_RP;
		src.m_bottom = CUT_PIC_BOTTOM_RP3;
		dst.m_top = HIT_TOP_RP3;
		dst.m_left = HIT_LEFT_RP;
		dst.m_right = HIT_RIGHT_RP;
		dst.m_bottom = HIT_BOTTOM_RP3;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	//戻るボタン
	src.m_top = CUT_PIC_TOP_SCENEBACK;
	src.m_left = CUT_PIC_LEFT_SCENEBACK;
	src.m_right = CUT_PIC_RIGHT_SCENEBACK;
	src.m_bottom = CUT_PIC_BOTTOM_SCENEBACK;
	dst.m_top = HIT_TOP_SCENEBACK;
	dst.m_left = HIT_LEFT_SCENEBACK;
	dst.m_right = HIT_RIGHT_SCENEBACK;
	dst.m_bottom = HIT_BOTTOM_SCENEBACK;
	Draw::Draw(1, &src, &dst, c, 0.0f);


	//黒星の描画---------------------------------------------------------------------------



	//(1)
	if (Pflag[0] == false && Cflag[0]==true)
	{
		src.m_top = CUT_PIC_TOP_BLACKSTAR;
		src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR1;
		dst.m_left = HIT_LEFT_BLACKSTAR;
		dst.m_right = HIT_RIGHT_BLACKSTAR;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR1;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	//(2)
	 if (Pflag[1] == false && Cflag[1] == true)
	{
		 src.m_top = CUT_PIC_TOP_BLACKSTAR;
		 src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		 src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		 src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		dst.m_top = HIT_TOP_BLACKSTAR2;
		dst.m_left = HIT_LEFT_BLACKSTAR;
		dst.m_right = HIT_RIGHT_BLACKSTAR;
		dst.m_bottom = HIT_BOTTOM_BLACKSTAR2;
		Draw::Draw(0, &src, &dst, c, 0.0f);
}
	//(3)
	 if (Pflag[2] == false && Cflag[2] == true)
	 {
		 src.m_top = CUT_PIC_TOP_BLACKSTAR;
		 src.m_left = CUT_PIC_LEFT_BLACKSTAR;
		 src.m_right = CUT_PIC_RIGHT_BLACKSTAR;
		 src.m_bottom = CUT_PIC_BOTTOM_BLACKSTAR;
		 dst.m_top = HIT_TOP_BLACKSTAR3;
		 dst.m_left = HIT_LEFT_BLACKSTAR;
		 dst.m_right = HIT_RIGHT_BLACKSTAR;
		 dst.m_bottom = HIT_BOTTOM_BLACKSTAR3;
		 Draw::Draw(0, &src, &dst, c, 0.0f);
	 }
	//白星の描画---------------------------------------------------------------------------


	//(1)
	if (Pflag[0] == true)
	{
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR1;
		dst.m_left = HIT_LEFT_WHITESTAR;
		dst.m_right = HIT_RIGHT_WHITESTAR;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR1;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	if (Pflag[1] == true)
	{
		//(2)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR2;
		dst.m_left = HIT_LEFT_WHITESTAR;
		dst.m_right = HIT_RIGHT_WHITESTAR;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR2;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
	if (Pflag[2] == true)
	{
		//(3)
		src.m_top = CUT_PIC_TOP_WHITESTAR;
		src.m_left = CUT_PIC_LEFT_WHITESTAR;
		src.m_right = CUT_PIC_RIGHT_WHITESTAR;
		src.m_bottom = CUT_PIC_BOTTOM_WHITESTAR;
		dst.m_top = HIT_TOP_WHITESTAR3;
		dst.m_left = HIT_LEFT_WHITESTAR;
		dst.m_right = HIT_RIGHT_WHITESTAR;
		dst.m_bottom = HIT_BOTTOM_WHITESTAR3;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

}