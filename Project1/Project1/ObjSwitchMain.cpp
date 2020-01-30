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
	LoadSPStage(StageSlect, *stage, count);
	count[INITIAL_CNT_ARRAY_NUM] = count[REMAINING_CNT_ARRAY_NUM];
	//マップデータをコピー
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));

	bool flag_set[8] =
	{ false,false,false,false,false,false,false,false };
	memcpy(flag, flag_set, sizeof(bool)*(8));

	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
	r = 0.0f;

	Save::Open();
	j = 0;
	for (i = 0; i < 6; i++)
	{

		if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
		{
			++j;
			if (j == 6)
			{
				flag[7] = true;
			}
		}
	}
	j = 0;


	//フラグを初期化
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;

}

//アクション
void CObjSwitchMain::Action()
{
	int lx = 0;
	int ly = 0;
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

	//当たり判定
	if (PUZZLE_POS_L <= x && PUZZLE_POS_L + PUZZLE_SIZE >= x && PUZZLE_POS_T <= y && PUZZLE_POS_T + PUZZLE_SIZE >= y &&
		((((int)(y - PUZZLE_POS_T) / PANEL_SIZE) % 2 == 0 && ((int)(x - PUZZLE_POS_L) / PANEL_SIZE) % 2 == 1) ||
		(((int)(y - PUZZLE_POS_T) / PANEL_SIZE) % 2 == 1 && ((int)(x - PUZZLE_POS_L) / PANEL_SIZE) % 2 == 0))
		&& flag[CLEAR_FLAG] == false && flag[GAMEOVER_FLAG] == false && flag[BACK_SELECT_FLAG] == false &&
		c_flag[0] == true && c_flag[1] == true && m_change == true)
	{
		//左クリック時パネルを反転させる
		m_change = false;	//反転中はほかのパネルを反転できないようにする

		//SEを鳴らす
		Audio::Start(1);

		//Countを減らす
		count[REMAINING_CNT_ARRAY_NUM]--;

		sy = (int)(y - PUZZLE_POS_T) / PANEL_SIZE;   //クリック時のy座標を配列で使えるように直す
		sx = (int)(x - PUZZLE_POS_L) / PANEL_SIZE;  //クリック時のx座標を配列で使えるように直す
		for (int m = 0; m < 4; m++)
		{
			switch (stage[sy][sx])
			{
			case 2://横
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
				case 2:
				case 3:
					break;
				}
				break;
			case 3://縦
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
				case 2:
				case 3:
					break;
				}
				break;
			case 4://左抜き3方向
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
				case 2:
					break;
				case 3://右
					ly = sy;
					lx = sx + 1;
					break;
				}
				break;
			case 5://上抜き3方向
				switch (m)
				{
				case 0:
					break;
				case 1://下
					ly = sy + 1;
					lx = sx;
					break;
				case 2://左
					ly = sy;
					lx = sx - 1;
					break;
				case 3://右
					ly = sy;
					lx = sx + 1;
					break;
				}
				break;
			case 6://右抜き3方向
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
				case 2://左
					ly = sy;
					lx = sx - 1;
					break;
				case 3:
					break;
				}
				break;
			case 7://下抜き3方向
				switch (m)
				{
				case 0://上
					ly = sy - 1;
					lx = sx;
					break;
				case 1:
					break;
				case 2://左
					ly = sy;
					lx = sx - 1;
					break;
				case 3://右
					ly = sy;
					lx = sx + 1;
					break;
				}
				break;
			case 8://4方向
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
				case 2://左
					ly = sy;
					lx = sx - 1;
					break;
				case 3://右
					ly = sy;
					lx = sx + 1;
					break;
				}
				break;
			}
			if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)//判定の正常化
			{
				if (stage[ly][lx] == WHITE_PANEL_ID)
				{
					stage[ly][lx] = CH_WHITE_PANEL_ID;
				}
				else if (stage[ly][lx] == BLACK_PANEL_ID)
				{
					stage[ly][lx] = CH_BLACK_PANEL_ID;
				}
			}
		}
	}

	//アニメーション処理-----

	time_flag = true;//ループ中１回だけタイムを増やす

	for (int m = 0; m < 4; m++)
	{
		switch (stage[sy][sx])
		{
		case 2://横
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
			case 2:
			case 3:
				break;
			}
			break;
		case 3://縦
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
			case 2:
			case 3:
				break;
			}
			break;
		case 4://左抜き3方向
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
			case 2:
				break;
			case 3://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		case 5://上抜き3方向
			switch (m)
			{
			case 0:
				break;
			case 1://下
				ly = sy + 1;
				lx = sx;
				break;
			case 2://左
				ly = sy;
				lx = sx - 1;
				break;
			case 3://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		case 6://右抜き3方向
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
			case 2://左
				ly = sy;
				lx = sx - 1;
				break;
			case 3:
				break;
			}
			break;
		case 7://下抜き3方向
			switch (m)
			{
			case 0://上
				ly = sy - 1;
				lx = sx;
				break;
			case 1:
				break;
			case 2://左
				ly = sy;
				lx = sx - 1;
				break;
			case 3://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		case 8://4方向
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
			case 2://左
				ly = sy;
				lx = sx - 1;
				break;
			case 3://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[ly][lx] == CH_WHITE_PANEL_ID)	//変化中白パネル
			{
				//タイムを増やす（ループ中１回のみ）
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//アニメーションを動かす
				if (m_time == M_TIME_MAX)
				{
					m_ani_flame++;
					m_time = 0;
				}
				//アニメーションが終了したら黒パネルに変更
				if (m_ani_flame == M_ANI_FRAME_MAX)
				{
					stage[ly][lx] = BLACK_PANEL_ID;
				}
			}
			if (stage[ly][lx] == CH_BLACK_PANEL_ID)	//変化中黒パネル
			{
				//タイムを増やす（ループ中一回のみ）
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				//アニメーションを動かす
				if (m_time == M_TIME_MAX)
				{
					m_ani_flame++;
					m_time = 0;
				}
				//アニメーションが終了したら白パネルに変更
				if (m_ani_flame == M_ANI_FRAME_MAX)
				{
					stage[ly][lx] = WHITE_PANEL_ID;
				}
			}
		}
	}
	//反転終了処理
	if (m_ani_flame == M_ANI_FRAME_MAX)
	{
		m_ani_flame = 0;	//初期化
		m_change = true;	//パネルを動かせるようにする

		if (SwitchClearCheck(stage) == true)	//クリア条件を満たした
		{
			//パーフェクト条件を満たしている
			if (count[INITIAL_CNT_ARRAY_NUM] - count[PERFECT_CNT_ARRAY_NUM] == count[REMAINING_CNT_ARRAY_NUM])
			{
				flag[PERFECT_FLAG] = true;
				Audio::Start(4);
			}
			flag[1] = true;
			if (flag[PERFECT_FLAG] == false)
			{
				Audio::Start(3);
			}
		}
		else if (SwitchClearCheck(stage) == false && count[REMAINING_CNT_ARRAY_NUM] == 0)		//ゲームオーバー条件を満たした
		{
			flag[GAMEOVER_FLAG] = true;
			Audio::Start(2);
		}
	}

	//GameClear時の判定
	if (flag[CLEAR_FLAG] == true)
	{
		//BGM停止
		if (StageSlect == 3)
			Audio::Stop(7);
		else
			Audio::Stop(0);

		//StageSELECTへ戻るボタン判定
		if (x >= CLEARBACK_POS_L && x <= CLEARBACK_POS_R && y >= CLEARBACK_POS_T && y <= CLEARBACK_POS_B &&
			c_flag[0] == true && c_flag[1] == true)
		{
			Save::Open();
			for (i = 0; i < 6; i++)
			{

				if (((UserData*)Save::GetData())->SPerfectFlag[i] == true)
				{
					++j;
					if (j == 6)
					{
						flag[6] = true;
					}
				}
			}

			if (flag[6] == true && flag[7] == false)
			{
				Scene::SetScene(new CSceneGalleryadd());
			}
			else if (flag[6] == false || flag[7] == true)
			{
				Scene::SetScene(new CSceneSwitchSelect());
			}
		}
	}
	
	//GameOver時の判定
	if (flag[GAMEOVER_FLAG] == true)
	{
		//BGM停止
		if (StageSlect == 3)
			Audio::Stop(7);
		else
			Audio::Stop(0);

		//Yesボタン判定
		if (x >= YES_BUTTON_POS_L && x <= YES_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B &&
			c_flag[0] == true && c_flag[1] == true)
		{
			count[REMAINING_CNT_ARRAY_NUM] = COUNT;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));

			//BGM停止
			if (StageSlect == 3)
				Audio::Start(7);
			else
				Audio::Start(0);
			//SEを鳴らす
			Audio::Start(1);

			flag[GAMEOVER_FLAG] = false;
			if (StageSlect == 3)
				Audio::Start(7);
			else
				Audio::Start(0);
			c_flag[0] = false;
		}
		//Noボタン判定
		if (x >= NO_BUTTON_POS_L && x <= NO_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(new CSceneSwitchSelect());
			flag[GAMEOVER_FLAG] = false;
		}
	}

	//リセットボタン当たり判定
	if (HIN_RESE_BUTTON_POS_L <= x && HIN_RESE_BUTTON_POS_L + BUTTON_SIZE_X >= x &&
		RESET_BUTTON_POS_T <= y && RESET_BUTTON_POS_T + BUTTON_SIZE_Y >= y &&
		flag[CLEAR_FLAG] == false && flag[GAMEOVER_FLAG] == false && flag[BACK_SELECT_FLAG] == false &&
		c_flag[0] == true && c_flag[1] == true)
	{
		count[REMAINING_CNT_ARRAY_NUM] = COUNT;
		memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
		//SEを鳴らす
		Audio::Start(6);
		m_change = true;
		c_flag[0] = false;
	}

	//ヒントボタン当たり判定
	if (HIN_RESE_BUTTON_POS_L <= x && HIN_RESE_BUTTON_POS_L + BUTTON_SIZE_X >= x &&
		HINT_BUTTON_POS_T <= y && HINT_BUTTON_POS_T + BUTTON_SIZE_Y >= y &&
		flag[CLEAR_FLAG] == false && flag[GAMEOVER_FLAG] == false && flag[BACK_SELECT_FLAG] == false &&
		c_flag[0] == true && c_flag[1] == true)
	{
		flag[HINT_FLAG] = true;
		//SEを鳴らす
		Audio::Start(5);

		c_flag[0] = false;
	}
	//StageSelectへ戻るボタン判定------------------------------------------------------------
	if (x >= STAGESELE_BUTTON_POS_L && x <= STAGESELE_BUTTON_POS_L + BUTTON_SIZE_X &&
		y >= STAGESELE_BUTTON_POS_T && y <= STAGESELE_BUTTON_POS_T + BUTTON_SIZE_Y &&
		flag[CLEAR_FLAG] == false && flag[GAMEOVER_FLAG] == false &&
		c_flag[0] == true && c_flag[1] == true)
	{
		flag[BACK_SELECT_FLAG] = true;
		//SEを鳴らす
		Audio::Start(1);

		c_flag[0] = false;
	}
	if (flag[BACK_SELECT_FLAG] == true)
	{
		//Yesボタン判定
		if (x >= YES_BUTTON_POS_L && x <= YES_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Stop(1);
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(new CSceneSwitchSelect());
		}
		//Noボタン判定
		if (x >= NO_BUTTON_POS_L && x <= NO_BUTTON_POS_R && y >= YESNO_BUTTON_POS_T && y <= YESNO_BUTTON_POS_B &&
			c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			flag[BACK_SELECT_FLAG] = false;
			c_flag[0] = false;
		}
	}

	//Perfectフラグの管理
	Save::Seve();
	if (flag[CLEAR_FLAG] == true && count[REMAINING_CNT_ARRAY_NUM] == count[PERFECT_CNT_ARRAY_NUM])
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
		case 4:
			((UserData*)Save::GetData())->SPerfectFlag[3] = true;
			break;
		case 5:
			((UserData*)Save::GetData())->SPerfectFlag[4] = true;
			break;
		case 6:
			((UserData*)Save::GetData())->SPerfectFlag[5] = true;
			break;
		}
	}
	//Clearフラグの管理
	if (flag[CLEAR_FLAG] == true)
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
		case 4:
			((UserData*)Save::GetData())->SClearFlag[3] = true;
			break;
		case 5:
			((UserData*)Save::GetData())->SClearFlag[4] = true;
			break;
		case 6:
			((UserData*)Save::GetData())->SClearFlag[5] = true;
			break;
		}
	}

	//ボタン類がない、もしくは動作が終わったら押していない状態に戻す
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
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
	src.m_top = CUT_BACKGROUND_T;
	src.m_left = CUT_BACKGROUND_L;
	src.m_right = CUT_BACKGROUND_R;
	src.m_bottom = CUT_BACKGROUND_B;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_X;
	dst.m_bottom = WINDOW_SIZE_Y;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//stageの描画
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };

	//左下ステージ表記
	//切り取り
	src.m_top = 820.0f;
	src.m_left = 180.0f;
	src.m_right = 280.0f;
	src.m_bottom = 865.0f;
	//表示
	dst.m_top = 450.0f;
	dst.m_left = 10.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 495.0f;
	Draw::Draw(12, &src, &dst, c, 0.0f);

	switch (StageSlect)
	{
	case 1:
		src.m_top = 0.0f;
		src.m_left = 1.0f;
		src.m_right = 119.0f;
		src.m_bottom = 119.0f;
		break;
	case 2:
		src.m_top = 0.0f;
		src.m_left = 120.0f;
		src.m_right = 120.0f * 2;
		src.m_bottom = 119.0f;

		break;
	case 3:
		src.m_top = 0.0f;
		src.m_left = 120.0f * 2;
		src.m_right = 120.0f * 3;
		src.m_bottom = 119.0f;

		break;
	case 4:
		src.m_top = 0.0f;
		src.m_left = 120.0f * 3;
		src.m_right = 120.0f * 4;
		src.m_bottom = 119.0f;
		break;
	case 5:
		src.m_top = 120.0f;
		src.m_left = 0.0f;
		src.m_right = 120.0f;
		src.m_bottom = 240.0f;
		break;
	case 6:
		src.m_top = 120.0f;
		src.m_left = 120.0f;
		src.m_right = 120.0f * 2;
		src.m_bottom = 240.0f;
		break;
	}
	dst.m_top = 450.0f;
	dst.m_left = 105.0f;
	dst.m_right = 155.0f;
	dst.m_bottom = 500.0f;
	Draw::Draw(11, &src, &dst, c, 0.0f);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//上下左右でアニメーションの角度を変えるやつ
			if (sy == i - 1 && sx == j)
			{
				r = CHANGE_ANI_R_T;
			}
			else if (sy == i && sx == j - 1)
			{
				r = CHANGE_ANI_R_L;
			}
			else if (sy == i && sx == j + 1)
			{
				r = CHANGE_ANI_R_R;
			}
			else if (sy == i + 1 && sx == j)
			{
				r = CHANGE_ANI_R_B;
			}


			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + PANEL_SIZE;
			src.m_bottom = src.m_top + PANEL_SIZE;

			//表示位置の設定
			dst.m_top = i * PANEL_SIZE + PUZZLE_POS_T;
			dst.m_left = j * PANEL_SIZE + PUZZLE_POS_L;
			dst.m_right = dst.m_left + PANEL_SIZE;
			dst.m_bottom = dst.m_top + PANEL_SIZE;
			if (stage[i][j] == WHITE_PANEL_ID)
			{
				//白パネル
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL_ID)
			{
				//黒パネル
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == UP_DOWN_SWIT_ID)
			{
				//縦スイッチ
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == LEF_RIG_SWIT_ID)
			{
				//横スイッチ
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == CH_WHITE_PANEL_ID)
			{
				//変化中白パネル
				src.m_top = 0.0f;
				src.m_left = 0.0f + (m_ani_flame * PANEL_SIZE);
				src.m_right = src.m_left + PANEL_SIZE;
				src.m_bottom = src.m_top + PANEL_SIZE;

				Draw::Draw(8, &src, &dst, c, r);
			}
			else if (stage[i][j] == CH_BLACK_PANEL_ID)
			{
				//変化中黒パネル
				src.m_top = 96.0f;
				src.m_left = 0.0f + (m_ani_flame * PANEL_SIZE);
				src.m_right = src.m_left + PANEL_SIZE;
				src.m_bottom = src.m_top + PANEL_SIZE;

				Draw::Draw(8, &src, &dst, c, r);
			}
		}
	}
	//ヒントボタン-----------------------------------------------
	//切り取り
	src.m_top = CUT_HIN_RESE_BUTTON_T;
	src.m_left = CUT_HIN_RESE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom = src.m_top + BUTTON_SIZE_Y;
	//表示
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = HINT_BUTTON_POS_T;
	dst.m_left = HIN_RESE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom = dst.m_top + BUTTON_SIZE_Y;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//ヒントの表示
	if (flag[HINT_FLAG] == true)
	{
		/*Font::StrDraw(L"最短手数", HIN_TEXT_POS_X_1, HIN_TEXT_POS_Y_1, HIN_TEXT_SIZE, f);
		Font::StrDraw(L"6手"	 , HIN_TEXT_POS_X_2, HIN_TEXT_POS_Y_2, HIN_TEXT_SIZE, f);*/
		if (StageSlect == 1)
		{
			Font::StrDraw(L"まずはパネル", 15, 260, 24, f);
			Font::StrDraw(L"をクリック！", 15, 300, 24, f);
		}
		else if (StageSlect == 2)
		{
			Font::StrDraw(L"まずはパネル", 15, 260, 24, f);
			Font::StrDraw(L"をクリック！", 15, 300, 24, f);
		}
		else if (StageSlect == 3)
		{
			wchar_t str2[128];
			Font::StrDraw(L"最短手数", 20, 260, 32, f);
			swprintf_s(str2, L"%d手", count[0]);


			Font::StrDraw(str2, 40, 320, 32, f);

		}
	}

	//リセットボタン--------------------------------------------
	//切り取り
	src.m_top = CUT_HIN_RESE_BUTTON_T;
	src.m_left = CUT_HIN_RESE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom = src.m_top + BUTTON_SIZE_Y;
	//表示
	//プログラムの問題でx値y値10fずらしています
	dst.m_top = RESET_BUTTON_POS_T;
	dst.m_left = HIN_RESE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom = dst.m_top + BUTTON_SIZE_Y;
	Draw::Draw(4, &src, &dst, c, 0.0f);

	//StageSelectボタン-----------------------------------------------
	src.m_top = CUT_SELE_BUTTON_T;
	src.m_left = CUT_SELE_BUTTON_L;
	src.m_right = src.m_left + BUTTON_SIZE_X;
	src.m_bottom = src.m_top + BUTTON_SIZE_Y;
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = STAGESELE_BUTTON_POS_T;
	dst.m_left = STAGESELE_BUTTON_POS_L;
	dst.m_right = dst.m_left + BUTTON_SIZE_X;
	dst.m_bottom = dst.m_top + BUTTON_SIZE_Y;
	Draw::Draw(5, &src, &dst, c, 0.0f);


	//Countの値を文字列化---------------------------------------
	wchar_t str[128];
	swprintf_s(str, L"%d", count[1]);

	if (count[REMAINING_CNT_ARRAY_NUM] >= 10)
		Font::StrDraw(str, CNT_NUM_MANY_POS_X, CNT_NUM_POS_Y, CNT_SIZE, f);
	else if (count[REMAINING_CNT_ARRAY_NUM] <= 9)
		Font::StrDraw(str, CNT_NUM_FEW_POS_X, CNT_NUM_POS_Y, CNT_SIZE, f);
	//Countの文字表示----------------------------------------------
	//切り取り
	src.m_top = 820.0f;
	src.m_left = 20.0f;
	src.m_right = 130.0f;
	src.m_bottom = 860.0f;
	//表示
	dst.m_top = 40.0f;
	dst.m_left = 660.0f;
	dst.m_right = 770.0f;
	dst.m_bottom = 80.0f;
	Draw::Draw(12, &src, &dst, c, 0.0f);
	//シーン描画：PerFect!------------------------------------
	if (flag[PERFECT_FLAG] == true)
	{
		//PerFect!
		src.m_top = CUT_PERFECT_T;
		src.m_left = CUT_PERFECT_L;
		src.m_right = CUT_PERFECT_R;
		src.m_bottom = CUT_PERFECT_B;
		dst.m_top = PERFECT_TEXT_POS_T;
		dst.m_left = PERFECT_TEXT_POS_L;
		dst.m_right = PERFECT_TEXT_POS_R;
		dst.m_bottom = PERFECT_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 30.0f);
		//ステージ選択に戻る
		src.m_top = CUT_CLEARBACK_T;
		src.m_left = CUT_CLEARBACK_L;
		src.m_right = CUT_CLEARBACK_R;
		src.m_bottom = CUT_CLEARBACK_B;
		dst.m_top = CLEARBACK_POS_T;
		dst.m_left = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom = CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//GameClear------------------------------------------
	else if (flag[CLEAR_FLAG] == true)
	{
		//Game Clear!!
		src.m_top = CUT_GAMECLEAR_T;
		src.m_left = CUT_GAMECLEAR_L;
		src.m_right = CUT_GAMECLEAR_R;
		src.m_bottom = CUT_GAMECLEAR_B;
		dst.m_top = GAMECLEAR_TEXT_POS_T;
		dst.m_left = GAMECLEAR_TEXT_POS_L;
		dst.m_right = GAMECLEAR_TEXT_POS_R;
		dst.m_bottom = GAMECLEAR_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//ステージ選択に戻る
		src.m_top = CUT_CLEARBACK_T;
		src.m_left = CUT_CLEARBACK_L;
		src.m_right = CUT_CLEARBACK_R;
		src.m_bottom = CUT_CLEARBACK_B;
		dst.m_top = CLEARBACK_POS_T;
		dst.m_left = CLEARBACK_POS_L;
		dst.m_right = CLEARBACK_POS_R;
		dst.m_bottom = CLEARBACK_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//GameOver------------------------------------
	if (flag[GAMEOVER_FLAG] == true)
	{
		//GameOver表示
		src.m_top = CUT_GAMEOVER_T;
		src.m_left = CUT_GAMEOVER_L;
		src.m_right = CUT_GAMEOVER_R;
		src.m_bottom = CUT_GAMEOVER_B;
		dst.m_top = GAMEOVER_TEXT_POS_T;
		dst.m_left = GAMEOVER_TEXT_POS_L;
		dst.m_right = GAMEOVER_TEXT_POS_R;
		dst.m_bottom = GAMEOVER_TEXT_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//Yes・Noボタン、ステージに戻りますか？の描画
	if (flag[GAMEOVER_FLAG] == true || flag[BACK_SELECT_FLAG] == true)
	{
		//Yesボタン
		src.m_top = CUT_YESNO_BUTTON_T;
		src.m_left = CUT_YES_BUTTON_L;
		src.m_right = CUT_YES_BUTTON_R;
		src.m_bottom = CUT_YESNO_BUTTON_B;
		dst.m_top = YESNO_BUTTON_POS_T;
		dst.m_left = YES_BUTTON_POS_L;
		dst.m_right = YES_BUTTON_POS_R;
		dst.m_bottom = YESNO_BUTTON_POS_B;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//Noボタン
		src.m_left = CUT_NO_BUTTON_L;
		src.m_right = CUT_NO_BUTTON_R;
		dst.m_left = NO_BUTTON_POS_L;
		dst.m_right = NO_BUTTON_POS_R;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//ステージに戻りますか？の描画
	if (flag[BACK_SELECT_FLAG] == true)
	{
		src.m_top = CUT_BACKSELECT_T;
		src.m_left = CUT_BACKSELECT_L;
		src.m_right = CUT_BACKSELECT_R;
		src.m_bottom = CUT_BACKSELECT_B;
		dst.m_top = BACKSELE_TEXT_POS_T;
		dst.m_left = BACKSELE_TEXT_POS_L;
		dst.m_right = BACKSELE_TEXT_POS_R;
		dst.m_bottom = BACKSELE_TEXT_POS_B;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}