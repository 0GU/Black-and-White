#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL\Audio.h"
#include "Reversiblefunction.h"

//マクロ
#define INITIALIZE (0)
#define HIT_PANEL_TOP (60.0f)
#define HIT_PANEL_LEFT (160.0f)
#define HIT_PANEL_RIGHT (640.0f)
#define HIT_PANEL_BOTTOM (540.0f)
#define PANEL_SIZE_X (96.0f)
#define PANEL_SIZE_Y (96.0f)
#define ANIMATIONPANEL_SIZE_X (96)
#define ANIMATIONPANEL_SIZE_Y (120)
#define POSITION_WHITE (120.0)
#define PANEL_POSITION_CORRECTION (12.0f)
#define POSITION_CORRECTION (10.0f)
#define PANEL_TOP (0.0f)
#define PANEL_LEFT (0.0f)
#define ARRAY_SIZE_TOP (0)
#define ARRAY_SIZE_LEFT (0)
#define ARRAY_SIZE_RIGHT (4)
#define ARRAY_SIZE_BOTTOM (4)
#define WHITE_PANEL (0)
#define BLACK_PANEL (1)
#define WHITE_PANEL_REVERSAL (2)
#define BLACK_PANEL_REVERSAL (3)
#define STAGE_SELECT_TOP (370.0f)
#define STAGE_SELECT_LEFT (130.0f)
#define STAGE_SELECT_RIGHT (690.0f)
#define STAGE_SELECT_BOTTOM (490.0f)
#define YES_BUTTON_TOP (370.0f)
#define YES_BUTTON_LEFT (130.0f)
#define YES_BUTTON_RIGHT (370.0f)
#define YES_BUTTON_BOTTOM (490.0f)
#define NO_BUTTON_TOP (370.0f)
#define NO_BUTTON_LEFT (410.0f)
#define NO_BUTTON_RIGHT (650.0f)
#define NO_BUTTON_BOTTOM (490.0f)
#define RESET_BUTTON_TOP (430.0f)
#define RESET_BUTTON_LEFT (650.0f)
#define RESET_BUTTON_RIGHT (770.0f)
#define RESET_BUTTON_BOTTOM (530.0f)
#define HINT_BUTTON_TOP (250.0f)
#define HINT_BUTTON_LEFT (650.0f)
#define HINT_BUTTON_RIGHT (770.0f)
#define HINT_BUTTON_BOTTOM (350.0f)
#define SELECT_BUTTON_TOP (60.0f)
#define SELECT_BUTTON_LEFT (30.0f)
#define SELECT_BUTTON_RIGHT (130.0f)
#define SELECT_BUTTON_BOTTOM (160.0f)
#define SRC_BACKGROUND_TOP  (0.0f)
#define SRC_BACKGROUND_LEFT  (0.0f)
#define SRC_BACKGROUND_RIGHT (800.0f)
#define SRC_BACKGROUND_BOTTOM  (600.0f)
#define DST_BACKGROUND_TOP  (0.0f)
#define DST_BACKGROUND_LEFT  (0.0f)
#define DST_BACKGROUND_RIGHT  (800.0f)
#define DST_BACKGROUND_BOTTOM  (600.0f)
#define SRC_HINT_TOP  (0.0f)
#define SRC_HINT_LEFT  (0.0f)
#define SRC_HINT_RIGHT (120.0f)
#define SRC_HINT_BOTTOM  (100.0f)
#define SRC_RESET_TOP  (0.0f)
#define SRC_RESET_LEFT  (0.0f)
#define SRC_RESET_RIGHT (120.0f)
#define SRC_RESET_BOTTOM  (100.0f)



//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjReversibleMain::CObjReversibleMain(int stage)
{
	StageSlect = stage;
}

//イニシャライズ
void CObjReversibleMain::Init()
{
	//ステージデータ読み込み用関数
	LoadRPStage(StageSlect, *stage,count);

	//カウントリセット用に初期カウントを保存する
	count[2] = count[1];

	//リセット用配列にコピー
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));
	
	//フラグを初期化
	bool flag_set[6] =
	{ false,false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(6));

	m_ani_flame = INITIALIZE;
	m_time = INITIALIZE;
	m_ani_flag = false;
	sx = INITIALIZE;
	sy = INITIALIZE;
	lx = INITIALIZE;
	ly = INITIALIZE;
}

//アクション
void CObjReversibleMain::Action()
{
	

	//マウスの座標を読み込む
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	

	//当たり判定---------------------------------------------------------------------------------------------------------
	if (HIT_PANEL_LEFT <= x && HIT_PANEL_RIGHT >= x && HIT_PANEL_TOP <= y && HIT_PANEL_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false)
	{
		if (m_ani_flag == false)
		{
			if (Input::GetMouButtonL() == true)    //左クリック時パネルを反転させる
			{
				//SEを鳴らす
				Audio::Start(1);

				//Countを減らす
				count[1]--;

				sy = (y - HIT_PANEL_TOP) / PANEL_SIZE_Y; //クリック時のy座標を配列で使えるように直す
				sx = (x - HIT_PANEL_LEFT) / PANEL_SIZE_X; //クリック時のx座標を配列で使えるように直す
				for (int m = 0; m < 5; m++)
				{
					ReversibleProcess(sx, sy,&lx,&ly, m, stage);
		
					//反転処理の準備
					if (lx >= ARRAY_SIZE_LEFT && ly >= ARRAY_SIZE_TOP && lx <= ARRAY_SIZE_RIGHT && ly <= ARRAY_SIZE_BOTTOM)
					{
						//反転中を示す値に変更する
						if (stage[ly][lx] == WHITE_PANEL)
						{
							stage[ly][lx] = WHITE_PANEL_REVERSAL;
						}
						else if (stage[ly][lx] == BLACK_PANEL)
						{

							stage[ly][lx] = BLACK_PANEL_REVERSAL;
						}
					}
				}
				m_ani_flag = true;	//反転中はほかのパネルを反転できないようにする
				while (Input::GetMouButtonL() == true)
				{

				}
				
			}
		}

	
	
	}
	//反転アニメーション処理------------------------------
	if (flag[4] == false)
	{
		time_flag = true;//ループ中１回だけタイムを増やす

		for (int m = 0; m < 5; m++)
		{
			ReversibleProcess(sx, sy, &lx, &ly, m, stage);

			if (lx >= ARRAY_SIZE_LEFT && ly >= ARRAY_SIZE_TOP && lx <= ARRAY_SIZE_RIGHT && ly <= ARRAY_SIZE_BOTTOM)
			{
				if (stage[ly][lx] == WHITE_PANEL_REVERSAL)//反転白パネル
				{
					//タイムを増やす（ループ中１回のみ）
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//アニメーションを動かす
					if (m_time == 3) {
						m_ani_flame++;
						m_time = 0;
					}
					//アニメーションが終了したら黒パネルに変更
					if (m_ani_flame == 8)
					{
						stage[ly][lx] = BLACK_PANEL;
					}

				}
				if (stage[ly][lx] == BLACK_PANEL_REVERSAL)//反転黒パネル
				{
					//タイムを増やす（ループ中１回のみ）
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//アニメーションを動かす
					if (m_time == 3) {
						m_ani_flame++;
						m_time = 0;
					}
					//アニメーションが終了したら白パネルに変更
					if (m_ani_flame == 8)
					{
						stage[ly][lx] = WHITE_PANEL;
					}

				}

			}

		}
	}

	//反転終了処理
	if (m_ani_flame == 8)
	{
		m_ani_flame = INITIALIZE;	//初期化
		m_ani_flag = false;	//パネルを動かせるようにする

		if (ReversibleClearCheck(stage) == true)	//クリア条件を満たした
		{
			//パーフェクト条件を満たしている
			if (count[2] - count[0]==count[1])
			{
				flag[4] = true;
				Audio::Start(4);
			}			
			flag[1] = true;
			if (flag[4] == false)
			{
				Audio::Start(3);
			}
		}
		else if (ReversibleClearCheck(stage) == false && count[1] == 0&&m_ani_flag==false)	//ゲームオーバー条件を満たした
		{
			flag[2] = true;
			Audio::Start(2);
		}
	}

	//GameClear時の判定-----------------------------------------------------------------------------------------------
	if (flag[1] == true)
	{
		//BGM停止
		Audio::Stop(0);
		CObjReversibleMain::Reverse();
		//StageSelectへ戻るボタン判定
		if (x >= STAGE_SELECT_LEFT && x <= STAGE_SELECT_RIGHT && y >= STAGE_SELECT_TOP && y <= STAGE_SELECT_BOTTOM)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneReversibleSelect());

			}

		}
	}
	//GameOver時の判定--------------------------------------------------------------------------------------------------
	if (flag[2] == true)
	{
		//BGM停止
		Audio::Stop(0);
		//Yesボタン判定
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = count[2];
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM再再生
				Audio::Start(0);
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				flag[2] = false;
			}
		}
		//Noボタン判定
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM)
		{

			if (Input::GetMouButtonL() == true)
			{

				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneReversibleSelect());
				flag[2] = false;
			}
		}

	}

	//リセットボタン当たり判定-------------------------------------------------------------
	if (RESET_BUTTON_LEFT <= x && RESET_BUTTON_RIGHT >= x && RESET_BUTTON_TOP <= y && RESET_BUTTON_BOTTOM >= y && flag[1] == false && flag[2] == false&& m_ani_flame == 0)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(6);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//ヒントボタン当たり判定----------------------------------------------------------------
	if (HINT_BUTTON_LEFT <= x && HINT_BUTTON_RIGHT>= x && HINT_BUTTON_TOP <= y && HINT_BUTTON_BOTTOM >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{

			flag[0] = true;
			//SEを鳴らす
			Audio::Start(5);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}

	//StageSelectへ戻るボタン判定------------------------------------------------------------
	if (x >= SELECT_BUTTON_LEFT && x <= SELECT_BUTTON_RIGHT && y >= SELECT_BUTTON_TOP && y <= SELECT_BUTTON_BOTTOM && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			flag[3] = true;

			//SEを鳴らす
			Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
		}
	}
	if (flag[3] == true)
	{

		//Yesボタン判定
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Stop(1);
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneReversibleSelect());
			}
		}
		//Noボタン判定
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM)
		{

			if (Input::GetMouButtonL() == true)
			{

				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}

				flag[3] = false;
			}
		}
	}

	//Perfectフラグの管理
	Save::Seve();
	if (flag[1] == true && flag[4]==true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->RPerfectFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->RPerfectFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->RPerfectFlag[2] = true;
			break;
		}
	}
	//Clearフラグの管理
	if (flag[1] == true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->RClearFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->RClearFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->RClearFlag[2] = true;
			break;
		}
	}

}

//ドロー
void CObjReversibleMain::Draw()
{
	int AniData[8]{
		0,1,2,3,7,6,5,4,
	};
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景表示
	src.m_top = SRC_BACKGROUND_TOP;
	src.m_left = SRC_BACKGROUND_LEFT;
	src.m_right = SRC_BACKGROUND_RIGHT;
	src.m_bottom = SRC_BACKGROUND_BOTTOM;
	dst.m_top = DST_BACKGROUND_TOP;
	dst.m_left = DST_BACKGROUND_LEFT;
	dst.m_right = DST_BACKGROUND_RIGHT;
	dst.m_bottom = DST_BACKGROUND_BOTTOM;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//stageの描画--------------------------------------------------
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str1[128];
	swprintf_s(str1, L"STAGE%d",StageSlect);
	Font::StrDraw(str1, 30, 470, 36, f);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			//表示位置の設定
			dst.m_top = i * PANEL_SIZE_Y + HIT_PANEL_TOP - PANEL_POSITION_CORRECTION;
			dst.m_left = j * PANEL_SIZE_X + HIT_PANEL_LEFT;
			dst.m_right = dst.m_left + ANIMATIONPANEL_SIZE_X;
			dst.m_bottom = dst.m_top + ANIMATIONPANEL_SIZE_Y;
			if (stage[i][j] == WHITE_PANEL)
			{
				src.m_top = POSITION_WHITE;
				src.m_left = PANEL_TOP;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//白パネル
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL)
			{
				src.m_top = PANEL_TOP;
				src.m_left = PANEL_TOP;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//黒パネル
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			if (stage[i][j] == WHITE_PANEL_REVERSAL)
			{
				src.m_top = POSITION_WHITE - (AniData[m_ani_flame] / 4)*ANIMATIONPANEL_SIZE_Y;
				src.m_left = ANIMATIONPANEL_SIZE_X + (AniData[m_ani_flame] % 4) * ANIMATIONPANEL_SIZE_X;
				src.m_right = src.m_left - ANIMATIONPANEL_SIZE_X;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//反転白パネル
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL_REVERSAL)
			{
				src.m_top = PANEL_TOP + (AniData[m_ani_flame] / 4)*ANIMATIONPANEL_SIZE_Y;
				src.m_left = PANEL_LEFT + (AniData[m_ani_flame] % 4) * ANIMATIONPANEL_SIZE_X;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//反転黒パネル
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}

		}
	}
		//ヒントボタン-----------------------------------------------
		//切り取り
		src.m_top = SRC_HINT_TOP;
		src.m_left = SRC_HINT_LEFT;
		src.m_right = SRC_HINT_RIGHT;
		src.m_bottom = SRC_HINT_BOTTOM;
		//表示
		//プログラムの問題でx値を10fずらしてます
		dst.m_top = HINT_BUTTON_TOP;
		dst.m_left = HINT_BUTTON_LEFT+POSITION_CORRECTION;
		dst.m_right = HINT_BUTTON_RIGHT+POSITION_CORRECTION;
		dst.m_bottom = HINT_BUTTON_BOTTOM;
		Draw::Draw(3, &src, &dst, c, 0.0f);

		//ヒントの表示
		if (flag[0]==true)
		{
			Font::StrDraw(L"最短手数", 20, 260, 32, f);

			wchar_t str2[128];
			swprintf_s(str2, L"%d手", count[0]);

			
			Font::StrDraw(str2,40 , 320, 32, f);
			
		}

		//リセットボタン--------------------------------------------
		//切り取り
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 120.0f;
		src.m_bottom = 100.0f;
		//表示
		//プログラムの問題でx値y値10fずらしています
		dst.m_top = 440.0f;
		dst.m_left = 660.0f;
		dst.m_right = 780.0f;
		dst.m_bottom = 540.0f;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//StageSelectボタン-----------------------------------------------
		//切り取り
		src.m_top = 820.0f;
		src.m_left = 478.0f;
		src.m_right = 600.0f;
		src.m_bottom = 920.0f;
		//表示
		//プログラムの問題でx値を10fずらしてます
		dst.m_top = 60.0f;
		dst.m_left = 30.0f;
		dst.m_right = 130.0;
		dst.m_bottom = 160.0f;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//Countの文字表示----------------------------------------------
		Font::StrDraw(L"Count", 675, 45, 32, f);

		//Countの値を文字列化---------------------------------------
		wchar_t str3[128];
		swprintf_s(str3, L"%d", count[1]);

		if(count[1]>=10)
			Font::StrDraw(str3, 700, 80, 32, f);
		else if(count[1]<=9)
			Font::StrDraw(str3, 710, 80, 32, f);
		//シーン描画:Perfect!---------------------------------------

		if (flag[4] == true)
		{


			src.m_top = 370.0f;
			src.m_left = 0.0f;
			src.m_right = 560.0f;
			src.m_bottom = 491.0f;
			dst.m_top = 150.0f;
			dst.m_left = 100.0f;
			dst.m_right = 690.0;
			dst.m_bottom = 300.0;
			Draw::Draw(5, &src, &dst, c, 30.0f);

			src.m_top = 490.0f;
			src.m_left = 0.0f;
			src.m_right = 560.0f;
			src.m_bottom = 610.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 690.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

		}
		//シーン描画：GameClear!------------------------------------
		else if (flag[1] == true)
		{

			//GameClear
				src.m_top = 249.0f;
				src.m_left = 0.0f;
				src.m_right = 560.0f;
				src.m_bottom = 372.0f;
				dst.m_top = 150.0f;
				dst.m_left = 130.0f;
				dst.m_right = 690.0;
				dst.m_bottom = 270.0;
				Draw::Draw(5, &src, &dst, c, 0.0f);
			//StageSelectへ戻る
				src.m_top = 490.0f;
				src.m_left = 0.0f;
				src.m_right = 560.0f;
				src.m_bottom = 610.0f;
				dst.m_top = 370.0f;
				dst.m_left = 130.0f;
				dst.m_right = 690.0;
				dst.m_bottom = 490.0;
				Draw::Draw(5, &src, &dst, c, 0.0f);
			
		}

		//GameOver---------------------------------------------------
		if (flag[2] == true)
		{
			//GameOver表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 580.0f;
			src.m_bottom = 250.0f;
			dst.m_top = 70.0f;
			dst.m_left = 110.0f;
			dst.m_right = 690.0;
			dst.m_bottom = 320.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}
		//Yes・Noボタンの描画
		if (flag[2] == true || flag[3] == true)
		{
			//Yes
			src.m_top = 820.0f;
			src.m_left = 0.0f;
			src.m_right = 240.0f;
			src.m_bottom = 939.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
			//NO
			src.m_top = 820.0f;
			src.m_left = 239.0f;
			src.m_right = 479.0f;
			src.m_bottom = 940.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
				
		}
		//ステージに戻りますか？の描画
		if (flag[3] == true)
		{
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 520.0f;
			src.m_bottom = 90.0f;
			dst.m_top = 150.0f;
			dst.m_left = 130.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 270.0;
			Draw::Draw(7, &src, &dst, c, 0.0f);

		}		

		}
}

void CObjReversibleMain::Reverse()
{
	if (flag[4] == true)
	{
		if (flag[5]==false)
		{
			LoadRPStage(99, *stage, count);
			flag[5] = true;
		}
		time_flag = true;//ループ中１回だけタイムを増やす

		for (int m = 0; m < 5; m++)
		{
			for (int i = 0; i < 5; i++)
			{




				if (stage[m][i] == WHITE_PANEL_REVERSAL)//反転白パネル
				{
					//タイムを増やす（ループ中１回のみ）
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//アニメーションを動かす
					if (m_time == 3) {
						m_ani_flame++;
						m_time = 0;
					}
					//アニメーションが終了したら黒パネルに変更
					if (m_ani_flame == 8)
					{
						stage[m][i] = BLACK_PANEL_REVERSAL;
					}

				}
				else if (stage[m][i] == BLACK_PANEL_REVERSAL)//反転黒パネル
				{
					//タイムを増やす（ループ中１回のみ）
					if (time_flag == true)
					{
						m_time++;
						time_flag = false;
					}
					//アニメーションを動かす
					if (m_time ==3) {
						m_ani_flame++;
						m_time = 0;
					}
					//アニメーションが終了したら白パネルに変更
					if (m_ani_flame == 8)
					{
						stage[m][i] = WHITE_PANEL_REVERSAL;
					}

				}
			}


		}

		//反転終了処理
		if (m_ani_flame == 8)
		{
			m_ani_flame = INITIALIZE;	//初期化
			
		}
	}
}