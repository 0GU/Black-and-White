#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjSwitchMain.h"
#include "GameL\Audio.h"
#include "Switchfunction.h"


//使用するネームスペース
using namespace GameL;

CObjSwitchMain::CObjSwitchMain(int stage)
{
	StageSlect = stage;
}

//イニシャライズ
void CObjSwitchMain::Init()
{
	LoadSPStage(StageSlect, *stage,count);
	count[2] = count[1];
	//マップデータをコピー
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));

	bool flag_set[6] =
	{ false,false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(6));
	   	
	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
	r = 0.0f;

}

//アクション
void CObjSwitchMain::Action()
{
	int lx = 0;
	int ly = 0;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//当たり判定
	if (160 <= x && 640 >= x && 60 <= y && 540 >= y &&
		((((int)(y - 60) / 96) % 2 == 0 && ((int)(x - 160) / 96) % 2 == 1) || (((int)(y - 60) / 96) % 2 == 1 && ((int)(x - 160) / 96) % 2 == 0))
		&& flag[1] == false && flag[2] == false && flag[3] == false)
	{
		if (m_change == true)
		{

			if (Input::GetMouButtonL() == true)    //左クリック時パネルを反転させる
			{
				m_change = false;	//反転中はほかのパネルを反転できないようにする

				//SEを鳴らす
				Audio::Start(1);

				//Countを減らす
				count[1]--;

				sy = (int)(y - 60) / 96;   //クリック時のy座標を配列で使えるように直す
				sx = (int)(x - 160) / 96;  //クリック時のx座標を配列で使えるように直す
				for (int m = 0; m < 2; m++)
				{
					switch (stage[sy][sx])
					{
					case 2:
						switch (m)
						{
						case 0://左
							ly = sy;
							lx = sx - 1;
							break;
						case 1://右
							ly = sy;
							lx = sx + 1;
							break;
						}
						break;
					case 3:
						switch (m)
						{
						case 0://上
							ly = sy - 1;
							lx = sx;
							break;

						case 1://下
							ly = sy + 1;
							lx = sx;
							break;
						}
						break;
					}
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)//判定の正常化
					{
						if (stage[ly][lx] == 0)
						{
							stage[ly][lx] = 4;
						}
						else if (stage[ly][lx] == 1)
						{
							stage[ly][lx] = 5;
						}
					}

				}
				while (Input::GetMouButtonL() == true)
				{

				}


			}
		}
	}
	//アニメーション処理-----

	time_flag = true;//ループ中１回だけタイムを増やす

	for (int m = 0; m < 2; m++)
	{
		switch (stage[sy][sx])
		{
		case 2://左右ボタン
			switch (m)
			{
			case 0://左
				ly = sy;
				lx = sx - 1;
				break;
			case 1://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		case 3://上下ボタン
			switch (m)
			{
			case 0://上
				ly = sy - 1;
				lx = sx;
				break;

			case 1://下
				ly = sy + 1;
				lx = sx;
				break;
			}
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[ly][lx] == 4)	//変化中白パネル
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
				if (m_ani_flame == 3)
				{
					stage[ly][lx] = 1;
				}

			}
			if (stage[ly][lx] == 5)	//変化中黒パネル
			{
				//タイムを増やす（ループ中一回のみ）
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
				if (m_ani_flame == 3)
				{
					stage[ly][lx] = 0;
				}

			}

		}

	}
	//反転終了処理
	if (m_ani_flame == 3)
	{
		m_ani_flame = 0;	//初期化
		m_change = true;	//パネルを動かせるようにする

		if (SwitchClearCheck(stage) == true)	//クリア条件を満たした
		{
			//パーフェクト条件を満たしている
			if (count[2] - count[0] == count[1])
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
		else if (SwitchClearCheck(stage) == false && count[1] == 0)		//ゲームオーバー条件を満たした
		{
			flag[2] = true;
			Audio::Start(2);
		}


	}

	//GameClear時の判定
	if (flag[1] == true)
	{
		//BGM停止
		Audio::Stop(0);

		//StageSELECTへ戻るボタン判定
		if (x >= 130 && x <= 690 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{

				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());

			}
		}
	}
	//GameOver時の判定
	if (flag[2] == true)
	{
	
		//BGM停止
		Audio::Stop(0);



		//Yesボタン判定
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = 12;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM停止
				Audio::Start(0);
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				flag[2] = false;
				Audio::Start(0);
			}

		}
		//Noボタン判定
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{

				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
				flag[2] = false;
			}
		}
	}

	//リセットボタン当たり判定
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = 12;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(6);
			m_change = true;
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//ヒントボタン当たり判定
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y && flag[1] == false && flag[2] == false)
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
	if (x >= 30 && x <= 130 && y >= 60 && y <= 160 && flag[1] == false && flag[2] == false)
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
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Stop(1);
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
			}
		}
		//Noボタン判定
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
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
	if (flag[1] == true && count[1] == count[0])
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->SPerfectFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->SPerfectFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->SPerfectFlag[2] = true;
			break;
		}
	}
	//Clearフラグの管理
	if (flag[1] == true)
	{
		switch (StageSlect)
		{
		case 1:
			((UserData*)Save::GetData())->SClearFlag[0] = true;
			break;
		case 2:
			((UserData*)Save::GetData())->SClearFlag[1] = true;
			break;
		case 3:
			((UserData*)Save::GetData())->SClearFlag[2] = true;
			break;
		}
	}

}

//ドロー
void CObjSwitchMain::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//stageの描画
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };

	switch (StageSlect)
	{
	case 1:
		Font::StrDraw(L"STAGE1", 30, 470, 36, f);
		break;
	case 2:
		Font::StrDraw(L"STAGE2", 30, 470, 36, f);
		break;
	case 3:
		Font::StrDraw(L"STAGE3", 30, 470, 36, f);
		break;

	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//上下左右でアニメーションの角度を変えるやつ
			if (sy == i - 1 && sx == j)
			{
				r = 90.0f;
			}
			else if (sy == i && sx == j - 1)
			{
				r = 180.0f;
			}
			else if (sy == i + 1 && sx == j)
			{
				r = 270.0f;
			}
			else if (sy == i && sx == j + 1)
			{
				r = 0.0f;
			}

			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 96.0f;
			src.m_bottom = 96.0f;

			//表示位置の設定
			dst.m_top = i * 96.0f + 60.0f;
			dst.m_left = j * 96.0f + 160.0f;
			dst.m_right = dst.m_left + 96.0;
			dst.m_bottom = dst.m_top + 96.0;
			if (stage[i][j] == 0)
			{
				//白パネル
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 1)
			{
				//黒パネル
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 3)
			{
				//縦スイッチ
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 2)
			{
				//横スイッチ
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 4)
			{
				//変化中白パネル
				src.m_top = 0.0f;
				src.m_left = 0.0f + (m_ani_flame * 96.0f);
				src.m_right = src.m_left + 96.0f;
				src.m_bottom = 96.0f;

				Draw::Draw(8, &src, &dst, c, r);
			}
			else if (stage[i][j] == 5)
			{
				//変化中黒パネル
				src.m_top = 96.0f;
				src.m_left = 0.0f + (m_ani_flame * 96.0f);
				src.m_right = src.m_left + 96.0f;
				src.m_bottom = src.m_top + 96.0f;

				Draw::Draw(8, &src, &dst, c, r);
			}
		}
	}
	//ヒントボタン-----------------------------------------------
	//切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	//表示
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = 250.0f;
	dst.m_left = 660.0f;
	dst.m_right = 780.0;
	dst.m_bottom = 350.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//ヒントの表示
	if (flag[0] == true)
	{
		Font::StrDraw(L"最短手数", 20, 200, 32, f);
		Font::StrDraw(L"6手", 40, 260, 32, f);

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
	src.m_top   = RESOURCE_SELE_BUTTON_T;
	src.m_left  = RESOURCE_SELE_BUTTON_L;
	src.m_right = RESOURCE_SELE_BUTTON_R;
	src.m_bottom= RESOURCE_SELE_BUTTON_B;
	//プログラムの問題でx値を10fずらしてます
	dst.m_top   = STAGESELE_BUTTON_POS_T;
	dst.m_left  = STAGESELE_BUTTON_POS_L;
	dst.m_right = STAGESELE_BUTTON_POS_R;
	dst.m_bottom= STAGESELE_BUTTON_POS_B;
	Draw::Draw(5, &src, &dst, c, 0.0f);


	Font::StrDraw(L"Count", 675, 45, 32, f);

	//Countの値を文字列化---------------------------------------
	wchar_t str[128];
	swprintf_s(str, L"%d", count[1]);

	if (count[1] >= 10)
		Font::StrDraw(str, 700, 80, 32, f);
	else if (count[1] <= 9)
		Font::StrDraw(str, 710, 80, 32, f);
	//シーン描画：PerFect!------------------------------------
	if (flag[4] == true)
	{
		//PerFect!
		src.m_top   = RESOURCE_PERFECT_T;
		src.m_left  = RESOURCE_PERFECT_L;
		src.m_right = RESOURCE_PERFECT_R;
		src.m_bottom= RESOURCE_PERFECT_B;
		dst.m_top   = PERFECT_TEXT_POS_T;
		dst.m_left  = PERFECT_TEXT_POS_L;
		dst.m_right = PERFECT_TEXT_POS_R;
		dst.m_bottom= PERFECT_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 30.0f);
		//ステージ選択に戻る
		src.m_top   = RESOURCE_CLEARBACK_T;
		src.m_left  = RESOURCE_CLEARBACK_L;
		src.m_right = RESOURCE_CLEARBACK_R;
		src.m_bottom= RESOURCE_CLEARBACK_B;
		dst.m_top   = CLEARBACK_POS_T;
		dst.m_left  = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom= CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//GameClear------------------------------------------
	else if (flag[1] == true)
	{
		//Game Clear!!
		src.m_top   = RESOURCE_GAMECLEAR_T;
		src.m_left  = RESOURCE_GAMECLEAR_L;
		src.m_right = RESOURCE_GAMECLEAR_R;
		src.m_bottom= RESOURCE_GAMECLEAR_B;
		dst.m_top   = GAMECLEAR_TEXT_POS_T;
		dst.m_left  = GAMECLEAR_TEXT_POS_L;
		dst.m_right = GAMECLEAR_TEXT_POS_R;
		dst.m_bottom= GAMECLEAR_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//ステージ選択に戻る
		src.m_top   = RESOURCE_CLEARBACK_T;
		src.m_left  = RESOURCE_CLEARBACK_L;
		src.m_right = RESOURCE_CLEARBACK_R;
		src.m_bottom= RESOURCE_CLEARBACK_B;
		dst.m_top   = CLEARBACK_POS_T;
		dst.m_left  = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom= CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//GameOver------------------------------------
	if (flag[2] == true)
	{
		//GameOver表示
		src.m_top   = RESOURCE_GAMEOVER_T;
		src.m_left  = RESOURCE_GAMEOVER_L;
		src.m_right = RESOURCE_GAMEOVER_R;
		src.m_bottom= RESOURCE_GAMEOVER_B;
		dst.m_top   = GAMEOVER_TEXT_POS_T;
		dst.m_left  = GAMEOVER_TEXT_POS_L;
		dst.m_right = GAMEOVER_TEXT_POS_R;
		dst.m_bottom= GAMEOVER_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
		//Yes・Noボタン、ステージに戻りますか？の描画
		if (flag[2] == true || flag[3] == true)
		{
			//Yesボタン
			src.m_top   = RESOURCE_YESNO_BUTTON_T;
			src.m_left  = RESOURCE_YES_BUTTON_L;
			src.m_right = RESOURCE_YES_BUTTON_R;
			src.m_bottom= RESOURCE_YESNO_BUTTON_B;
			dst.m_top   = YESNO_BUTTON_POS_T;
			dst.m_left  = YES_BUTTON_POS_L;
			dst.m_right = YES_BUTTON_POS_R;
			dst.m_bottom= YESNO_BUTTON_POS_B;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			//Noボタン
			src.m_left  = RESOURCE_NO_BUTTON_L;
			src.m_right = RESOURCE_NO_BUTTON_R;
			dst.m_left  = NO_BUTTON_POS_L;
			dst.m_right = NO_BUTTON_POS_R;
			Draw::Draw(5, &src, &dst, c, 0.0f);			
		}
		//ステージに戻りますか？の描画
		if (flag[3] == true)
		{
			src.m_top   = RESOURCE_BACKSELECT_T;
			src.m_left  = RESOURCE_BACKSELECT_L;
			src.m_right = RESOURCE_BACKSELECT_R;
			src.m_bottom= RESOURCE_BACKSELECT_B;
			dst.m_top   = BACKSELECT_TEXT_POS_T;
			dst.m_left  = BACKSELECT_TEXT_POS_L;
			dst.m_right = BACKSELECT_TEXT_POS_R;
			dst.m_bottom= BACKSELECT_TEXT_POS_B;
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
}