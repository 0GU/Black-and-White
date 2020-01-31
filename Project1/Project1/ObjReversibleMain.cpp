#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL\Audio.h"
#include "Reversiblefunction.h"


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
	LoadRPStage(StageSlect, *stage, count);

	//カウントリセット用に初期カウントを保存する
	count[2] = count[1];

	//リセット用配列にコピー
	memcpy(stage_reset, stage, sizeof(int)*(5 * 5));

	//フラグを初期化
	bool flag_set[8] =
	{ false,false,false,false,false,false,false,false };
	memcpy(flag, flag_set, sizeof(bool)*(8));


	m_ani_flame = INITIALIZE;
	m_time = INITIALIZE;
	m_ani_flag = false;
	sx = INITIALIZE;
	sy = INITIALIZE;
	lx = INITIALIZE;
	ly = INITIALIZE;

	Save::Open();
	j = 0;
	for (i = 0; i < 6; i++)
	{

		if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
		{
			++j;
			if (j == 6)
			{
				flag[7] = true;
			}
		}
	}
	j = 0;


		colorchange = 0;
		colorflag = false;
	
	//フラグを初期化
		
	memcpy(c_flag, flag_set, sizeof(bool)*(2));
	back = true;
	mou_call = true;

	Debugflag = false;

	help_flag = true;
	help_flag2 = true;
}

//アクション
void CObjReversibleMain::Action()
{

	if (Input::GetVKey('D')==true&& Input::GetVKey('G')==true)
	{
		count[1] = 0;
		Debugflag = true;
	}

	//マウスの座標を読み込む
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//
	col_flag[0] = false;
	col_flag[1] = false;

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


	//当たり判定---------------------------------------------------------------------------------------------------------
	if (HIT_PANEL_LEFT <= x && HIT_PANEL_RIGHT >= x && HIT_PANEL_TOP <= y && HIT_PANEL_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false && m_ani_flag == false && help_flag == true && help_flag2 == true)
	{
		sy = (y - HIT_PANEL_TOP) / PANEL_SIZE_Y; //クリック時のy座標を配列で使えるように直す
		sx = (x - HIT_PANEL_LEFT) / PANEL_SIZE_X; //クリック時のx座標を配列で使えるように直す

		buttom_name = 'p';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			for (int m = 0; m < 5; m++)
			{
				ReversibleProcess(sx, sy, &lx, &ly, m, stage);

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

			//SEを鳴らす
			Audio::Start(1);
			//Countを減らす
			count[1]--;
		}
		ButtomCol(c_flag, col_flag);
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

		if (ReversibleClearCheck(stage) == true && Debugflag == false)	//クリア条件を満たした
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
		else if (ReversibleClearCheck(stage) == false && count[1] == 0 && m_ani_flag == false && Debugflag == false)	//ゲームオーバー条件を満たした
		{
			flag[2] = true;
			Audio::Start(2);
		}
	}


	//Perfectフラグの管理
	Save::Seve();
	if (flag[1] == true && flag[4] == true)
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
		case 4:
			((UserData*)Save::GetData())->RPerfectFlag[3] = true;
			break;
		case 5:
			((UserData*)Save::GetData())->RPerfectFlag[4] = true;
			break;
		case 6:
			((UserData*)Save::GetData())->RPerfectFlag[5] = true;
			break;
		}
		(UserData*)Save::Seve;

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
		case 4:
			((UserData*)Save::GetData())->RClearFlag[3] = true;
			break;
		case 5:
			((UserData*)Save::GetData())->RClearFlag[4] = true;
			break;
		case 6:
			((UserData*)Save::GetData())->RClearFlag[5] = true;
			break;
		}
		(UserData*)Save::Seve;
	}
	
	//GameClear時の判定-----------------------------------------------------------------------------------------------
	if (flag[1] == true)
	{
		//BGM停止
		if (StageSlect == 5 || StageSlect == 6)
			Audio::Stop(7);
		else
			Audio::Stop(0);
		CObjReversibleMain::Reverse();
		//StageSelectへ戻るボタン判定
		if (x >= STAGE_SELECT_LEFT && x <= STAGE_SELECT_RIGHT && y >= STAGE_SELECT_TOP && y <= STAGE_SELECT_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true && help_flag == true && help_flag2 == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(300);
			Save::Open();
			for (i = 0; i < 6; i++)
			{

				if (((UserData*)Save::GetData())->RPerfectFlag[i] == true)
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
				Scene::SetScene(new CSceneReversibleSelect());
			}


		}
	}
	//GameOver時の判定--------------------------------------------------------------------------------------------------
	if (flag[2] == true)
	{
		//BGM停止
		if (StageSlect == 5 || StageSlect == 6)
			Audio::Stop(7);
		else
			Audio::Stop(0);
		//Yesボタン判定
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true && help_flag == true && help_flag2 == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//BGM再再生
			if (StageSlect == 5 || StageSlect == 6)
				Audio::Start(7);
			else
				Audio::Start(0);
			//SEを鳴らす
			Audio::Start(1);
			flag[2] = false;
			c_flag[0] = false;
		}
		//Noボタン判定
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true && help_flag == true && help_flag2 == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Scene::SetScene(new CSceneReversibleSelect());
			flag[2] = false;
		}

	}

	//リセットボタン当たり判定-------------------------------------------------------------
	if (RESET_BUTTON_LEFT <= x && RESET_BUTTON_RIGHT >= x && RESET_BUTTON_TOP <= y && RESET_BUTTON_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false && m_ani_flame == 0 && help_flag == true && help_flag2 == true)
	{
		buttom_name = 'r';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(6);
		}
		ButtomCol(c_flag, col_flag);
	}

	//ヒントボタン当たり判定----------------------------------------------------------------
	else if (HINT_BUTTON_LEFT <= x && HINT_BUTTON_RIGHT >= x && HINT_BUTTON_TOP <= y && HINT_BUTTON_BOTTOM >= y &&
		flag[1] == false && flag[2] == false && flag[3] == false && help_flag == true && help_flag2 == true)
	{
		buttom_name = 'i';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			flag[0] = true;
			//SEを鳴らす
			Audio::Start(5);
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}

	//StageSelectへ戻るボタン判定------------------------------------------------------------
	else if (x >= SELECT_BUTTON_LEFT && x <= SELECT_BUTTON_RIGHT && y >= SELECT_BUTTON_TOP && y <= SELECT_BUTTON_BOTTOM &&
		flag[1] == false && flag[2] == false && flag[3] == false && help_flag == true && help_flag2 == true)
	{
		buttom_name = 's';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			flag[3] = true;
			//SEを鳴らす
			Audio::Start(1);
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}
	else if (flag[3] == true)
	{
		//Yesボタン判定
		if (x >= YES_BUTTON_LEFT && x <= YES_BUTTON_RIGHT && y >= YES_BUTTON_TOP && y <= YES_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true && help_flag == true && help_flag2 == true)
		{
			//SEを鳴らす
			Audio::Stop(1);
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(new CSceneReversibleSelect());
		}
		//Noボタン判定
		if (x >= NO_BUTTON_LEFT && x <= NO_BUTTON_RIGHT && y >= NO_BUTTON_TOP && y <= NO_BUTTON_BOTTOM &&
			c_flag[0] == true && c_flag[1] == true && help_flag == true && help_flag2 == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			c_flag[0] = false;
			flag[3] = false;
		}
	}

	//ヘルプボタン
	else if (POS_HELPBUTTON_L_RB <= x && POS_HELPBUTTON_R_RB >= x && POS_HELPBUTTON_T_RB <= y && POS_HELPBUTTON_B_RB >= y 
		&&flag[1] == false && flag[2] == false && flag[3]==false && help_flag == true)
	{
		buttom_name = 'h';//明るさ変更用

		if (c_flag[0] == true && c_flag[1] == true)
		{
			//SEを鳴らす
			Audio::Start(1);
			Sleep(SCENEBACK_WAIT);
			help_flag = false;
			c_flag[0] = false;
		}
		ButtomCol(c_flag, col_flag);
	}

	//ヘルプ
	if (help_flag == false && c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag = true;
		help_flag2 = false;
		c_flag[0] = false;
	}
	 if (help_flag2==false&&c_flag[0] == true && c_flag[1] == true)
	{
		//SEを鳴らす
		Audio::Start(1);
		Sleep(SCENEBACK_WAIT);
		help_flag2 = true;
		c_flag[0] = false;
	}

	//ボタン類がない、もしくは動作が終わったら押していない状態に戻す
	if (c_flag[0] == true && c_flag[1] == true)
	{
		c_flag[0] = false;
	}

}

//ドロー
void CObjReversibleMain::Draw()
{
	int AniData[8]{
		0,1,2,3,7,6,5,4,
	};
	//描画カラー情報
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };//ボタン以外、ボタン位置にカーソル
	float	b[4] = { 0.7f,0.7f,0.7f,1.0f };//ボタン通常
	float	t[4] = { 0.4f,0.4f,0.4f,1.0f };//ボタン押している
	float	bl[4] = { 1.0f,1.0f,1.0f,0.8f };//黒ボタン位置にカーソル
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用
	float   cchange[4] = { colorchange,0.0f,0.0f,1.0f };//テキスト用

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
	//swprintf_s(str1, L"STAGE%d", StageSlect);
	//Font::StrDraw(str1, 30, 470, 36, f);
	Font::StrDraw(L"全てのパネルを黒色に変えろ！", 180, 25, 32, f);
	//左下ステージ表記
	//切り取り
	src.m_top = SRC_STAGE_TOP;
	src.m_left = SRC_STAGE_LEFT;
	src.m_right = SRC_STAGE_RIGHT;
	src.m_bottom = SRC_STAGE_BOTTOM;
	//表示
	dst.m_top = DST_STAGE_TOP;
	dst.m_left = DST_STAGE_LEFT;
	dst.m_right = DST_STAGE_RIGHT;
	dst.m_bottom = DST_STAGE_BOTTOM;
	Draw::Draw(12, &src, &dst, c, 0.0f);

	//左下のSTAGEの数（書き方が曖昧かもなのでだれか改良してｗ）
	switch (StageSlect)
	{
	case 1:
		src.m_top = SRC_STAGECOUNT_TOP_1234;
		src.m_left = SRC_STAGECOUNT_LEFT_1;
		src.m_right = SRC_STAGECOUNT_RIGHT_1;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_1234;
		break;
	case 2:
		src.m_top = SRC_STAGECOUNT_TOP_1234;
		src.m_left = SRC_STAGECOUNT_LEFT_2;
		src.m_right = SRC_STAGECOUNT_RIGHT_2 *2;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_1234;
		break;
	case 3:
		src.m_top = SRC_STAGECOUNT_TOP_1234;
		src.m_left = SRC_STAGECOUNT_LEFT_3 *2;
		src.m_right = SRC_STAGECOUNT_RIGHT_3 *3;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_1234;
		break;
	case 4:
		src.m_top = SRC_STAGECOUNT_TOP_1234;
		src.m_left = SRC_STAGECOUNT_LEFT_4 * 3;
		src.m_right = SRC_STAGECOUNT_RIGHT_4 * 4;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_1234;
		break;
	case 5:
		src.m_top = SRC_STAGECOUNT_TOP_56;
		src.m_left = SRC_STAGECOUNT_LEFT_5;
		src.m_right = SRC_STAGECOUNT_RIGHT_5;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_56;
		break;
	case 6:
		src.m_top = SRC_STAGECOUNT_TOP_56;
		src.m_left = SRC_STAGECOUNT_LEFT_6;
		src.m_right = SRC_STAGECOUNT_RIGHT_6 * 2;
		src.m_bottom = SRC_STAGECOUNT_BOTTOM_56;
		break;
	}
	dst.m_top = DST_STAGECOUNT_TOP;
	dst.m_left = DST_STAGECOUNT_LEFT;
	dst.m_right = DST_STAGECOUNT_RIGHT;
	dst.m_bottom = DST_STAGECOUNT_BOTTOM;
	Draw::Draw(11, &src, &dst, c, 0.0f);

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
				//カーソルのあるパネルとその上下左右の色を変更する
				if (((i == sy + 1 && j == sx) || (i == sy - 1 && j == sx) || (i == sy && j == sx) || (i == sy && j == sx + 1) || (i == sy && j == sx - 1)) &&
					col_flag[0] == true && col_flag[1] == false && buttom_name == 'p')
					Draw::Draw(6, &src, &dst, b, 0.0f);
				else
					Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == BLACK_PANEL)
			{
				src.m_top = PANEL_TOP;
				src.m_left = PANEL_TOP;
				src.m_right = ANIMATIONPANEL_SIZE_X + src.m_left;
				src.m_bottom = ANIMATIONPANEL_SIZE_Y + src.m_top;
				//黒パネル
				//カーソルのあるパネルとその上下左右の色を変更する
				if (((i == sy + 1 && j == sx) || (i == sy - 1 && j == sx) || (i == sy && j == sx) || (i == sy && j == sx + 1) || (i == sy && j == sx - 1)) &&
					col_flag[0] == true && col_flag[1] == false && buttom_name == 'p')
					Draw::Draw(6, &src, &dst, bl, 0.0f);
				else
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
	//プログラムの問題でx値を10f,y値を5fずらしてます
	dst.m_top = HINT_BUTTON_TOP + POSITION_CORRECTION_HEIGHT;
	dst.m_left = HINT_BUTTON_LEFT + POSITION_CORRECTION_WIDTH;
	dst.m_right = HINT_BUTTON_RIGHT + POSITION_CORRECTION_WIDTH;
	dst.m_bottom = HINT_BUTTON_BOTTOM + POSITION_CORRECTION_HEIGHT;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'i')
		Draw::Draw(3, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'i')
		Draw::Draw(3, &src, &dst, t, 0.0f);
	else
		Draw::Draw(3, &src, &dst, c, 0.0f);

	//ヒントの表示
	if (flag[0] == true)
	{
		switch (StageSlect)
		{
		case 1:
			Font::StrDraw(L"白の十字を", 15, 260, 24, f);
			Font::StrDraw(L"クリック！", 15, 300, 24, f);
			break;

		case 2:
			Font::StrDraw(L" 四隅を", 25, 260, 24, f);
			Font::StrDraw(L"クリック！", 15, 300, 24, f);
			break;

		case 3:
			Font::StrDraw(L" 左の角を", 15, 260, 24, f);
			Font::StrDraw(L"クリック！", 15, 300, 24, f);
			break;
		case 4:
			Font::StrDraw(L" 最上段は", 15, 260, 24, f);
			Font::StrDraw(L" クリック", 15, 300, 24, f);
			Font::StrDraw(L" しない!", 15, 340, 24, f);
			break;
		case 5:
		case 6:
			wchar_t str2[128];
			Font::StrDraw(L"最短手数", 20, 260, 32, f);
			swprintf_s(str2, L"%d手", count[0]);


			Font::StrDraw(str2, 40, 320, 32, f);
		}
	}

	//リセットボタン--------------------------------------------
	//切り取り
	src.m_top = SRC_RESET_TOP;
	src.m_left = SRC_RESET_LEFT;
	src.m_right = SRC_RESET_RIGHT;
	src.m_bottom = SRC_RESET_BOTTOM;
	//表示
	//プログラムの問題でx値10f,y値5fずらしています
	dst.m_top = RESET_BUTTON_TOP + POSITION_CORRECTION_HEIGHT;
	dst.m_left = RESET_BUTTON_LEFT + POSITION_CORRECTION_WIDTH;
	dst.m_right = RESET_BUTTON_RIGHT + POSITION_CORRECTION_WIDTH;
	dst.m_bottom = RESET_BUTTON_BOTTOM + POSITION_CORRECTION_HEIGHT;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'r')
		Draw::Draw(4, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'r')
		Draw::Draw(4, &src, &dst, t, 0.0f);
	else
		Draw::Draw(4, &src, &dst, c, 0.0f);

	//helpボタン
	src.m_top = CUT_HELPBUTTON_T2;
	src.m_left = CUT_HELPBUTTON_L;
	src.m_right = CUT_HELPBUTTON_R;
	src.m_bottom = CUT_HELPBUTTON_B2;
	dst.m_top = POS_HELPBUTTON_T_RB;
	dst.m_left = POS_HELPBUTTON_L_RB;
	dst.m_right = POS_HELPBUTTON_R_RB;
	dst.m_bottom = POS_HELPBUTTON_B_RB;
	if (col_flag[0] == true && col_flag[1] == false && buttom_name == 'h')
		Draw::Draw(13, &src, &dst, b, 0.0f);
	else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 'h')
		Draw::Draw(13, &src, &dst, t, 0.0f);
	else
		Draw::Draw(13, &src, &dst, c, 0.0f);

	//ヘルプ表示
	if (help_flag == false)
	{
		src.m_top = CUT_HELP_T;
		src.m_left = CUT_HELP_L;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = POS_HELP_T;
		dst.m_left = POS_HELP_L;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(14, &src, &dst, c, 0.0f);
	}

	//ヘルプ表示
	if (help_flag2 == false)
	{
		src.m_top = CUT_HELP_T;
		src.m_left = CUT_HELP_L;
		src.m_right = CUT_HELP_R;
		src.m_bottom = CUT_HELP_B;
		dst.m_top = POS_HELP_T;
		dst.m_left = POS_HELP_L;
		dst.m_right = POS_HELP_R;
		dst.m_bottom = POS_HELP_B;
		Draw::Draw(15, &src, &dst, c, 0.0f);
	}

	//StageSelectボタン-----------------------------------------------
	//切り取り
	
	src.m_top = SRC_SELECT_TOP;
	src.m_left = SRC_SELECT_LEFT;
	src.m_right = SRC_SELECT_RIGHT;
	src.m_bottom = SRC_SELECT_BOTTOM;
	//表示
	if (help_flag == true&&help_flag2==true)
	{
		dst.m_top = SELECT_BUTTON_TOP;
		dst.m_left = SELECT_BUTTON_LEFT;
		dst.m_right = SELECT_BUTTON_RIGHT;
		dst.m_bottom = SELECT_BUTTON_BOTTOM;
		if (col_flag[0] == true && col_flag[1] == false && buttom_name == 's')
			Draw::Draw(5, &src, &dst, b, 0.0f);
		else if (col_flag[0] == false && col_flag[1] == true && buttom_name == 's')
			Draw::Draw(5, &src, &dst, t, 0.0f);
		else
			Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//Countの文字表示----------------------------------------------
	//切り取り
	src.m_top = SRC_COUNT_TOP;
	src.m_left = SRC_COUNT_LEFT;
	src.m_right = SRC_COUNT_RIGHT;
	src.m_bottom = SRC_COUNT_BOTTOM;
	//表示
	if (help_flag == true&&help_flag2==true)
	{
		dst.m_top = DST_COUNT_TOP;
		dst.m_left = DST_COUNT_LEFT;
		dst.m_right = DST_COUNT_RIGHT;
		dst.m_bottom = DST_COUNT_BOTTOM;
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	//Countの値を文字列化---------------------------------------
	wchar_t str3[128];
	swprintf_s(str3, L"%d", count[1]);

	if (count[1] >= 10&&help_flag == true && help_flag2 == true)
		Font::StrDraw(str3, 700, 80, 32, f);
	else if (count[1] <= 9 && help_flag == true && help_flag2 == true)
		Font::StrDraw(str3, 710, 80, 32, f);
	//CountとStageSelectにhelp_flagが入っているのは
	//描画の都合上画像の上にCount等が表示されるため
	//シーン描画:Perfect!---------------------------------------

	if (flag[4] == true)
	{

		//Perfect
		src.m_top = SRC_PERFECT_TOP;
		src.m_left = SRC_PERFECT_LEFT;
		src.m_right = SRC_PERFECT_RIGHT;
		src.m_bottom = SRC_PERFECT_BOTTOM;
		dst.m_top = DST_PERFECT_TOP;
		dst.m_left = DST_PERFECT_LEFT;
		dst.m_right = DST_PERFECT_RIGHT;
		dst.m_bottom = DST_PERFECT_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 30.0f);
		//StageSelectへ戻る
		src.m_top = SRC_STAGE_SELECT_TOP;
		src.m_left = SRC_STAGE_SELECT_LEFT;
		src.m_right = SRC_STAGE_SELECT_RIGHT;
		src.m_bottom = SRC_STAGE_SELECT_BOTTOM;
		dst.m_top = STAGE_SELECT_TOP + 5;
		dst.m_left = STAGE_SELECT_LEFT;
		dst.m_right = STAGE_SELECT_RIGHT;
		dst.m_bottom = STAGE_SELECT_BOTTOM + 5;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}
	//シーン描画：GameClear!------------------------------------
	else if (flag[1] == true)
	{

		//GameClear
		src.m_top = SRC_CLERE_TOP;
		src.m_left = SRC_CLERE_LEFT;
		src.m_right = SRC_CLERE_RIGHT;
		src.m_bottom = SRC_CLERE_BOTTOM;
		dst.m_top = DST_CLERE_TOP;
		dst.m_left = DST_CLERE_LEFT;
		dst.m_right = DST_CLERE_RIGHT;
		dst.m_bottom = DST_CLERE_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//StageSelectへ戻る
		src.m_top = SRC_STAGE_SELECT_TOP;
		src.m_left = SRC_STAGE_SELECT_LEFT;
		src.m_right = SRC_STAGE_SELECT_RIGHT;
		src.m_bottom = SRC_STAGE_SELECT_BOTTOM;
		dst.m_top = STAGE_SELECT_TOP;
		dst.m_left = STAGE_SELECT_LEFT;
		dst.m_right = STAGE_SELECT_RIGHT;
		dst.m_bottom = STAGE_SELECT_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}

	//GameOver---------------------------------------------------
	if (flag[2] == true)
	{
		//GameOver表示
		src.m_top = SRC_GAMEOVER_TOP;
		src.m_left = SRC_GAMEOVER_LEFT;
		src.m_right = SRC_GAMEOVER_RIGHT;
		src.m_bottom = SRC_GAMEOVER_BOTTOM;
		dst.m_top = DST_GAMEOVER_TOP;
		dst.m_left = DST_GAMEOVER_LEFT;
		dst.m_right = DST_GAMEOVER_RIGHT;
		dst.m_bottom = DST_GAMEOVER_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
	//Yes・Noボタンの描画
	if (flag[2] == true || flag[3] == true)
	{
		//Yes
		src.m_top = SRC_YES_TOP;
		src.m_left = SRC_YES_LEFT;
		src.m_right = SRC_YES_RIGHT;
		src.m_bottom = SRC_YES_BOTTOM;
		dst.m_top = YES_BUTTON_TOP;
		dst.m_left = YES_BUTTON_LEFT;
		dst.m_right = YES_BUTTON_RIGHT;
		dst.m_bottom = YES_BUTTON_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//NO
		src.m_top = SRC_NO_TOP;
		src.m_left = SRC_NO_LEFT;
		src.m_right = SRC_NO_RIGHT;
		src.m_bottom = SRC_NO_BOTTOM;
		dst.m_top = NO_BUTTON_TOP;
		dst.m_left = NO_BUTTON_LEFT;
		dst.m_right = NO_BUTTON_RIGHT;
		dst.m_bottom = NO_BUTTON_BOTTOM;
		Draw::Draw(5, &src, &dst, c, 0.0f);

	}
	//ステージに戻りますか？の描画
	if (flag[3] == true)
	{
		src.m_top = SRC_RETURNSELECT_TOP;
		src.m_left = SRC_RETURNSELECT_LEFT;
		src.m_right = SRC_RETURNSELECT_RIGHT;
		src.m_bottom = SRC_RETURNSELECT_BOTTOM;
		dst.m_top = DST_RETURNSELECT_TOP;
		dst.m_left = DST_RETURNSELECT_LEFT;
		dst.m_right = DST_RETURNSELECT_RIGHT;
		dst.m_bottom = DST_RETURNSELECT_BOTTOM;
		Draw::Draw(7, &src, &dst, c, 0.0f);

	}


}

void CObjReversibleMain::Reverse() //Perfectクリア時にパネルを回転させ続ける
{
	if (flag[4] == true)
	{
		if (flag[5] == false)
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
					if (m_time == 1) {
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
					if (m_time == 1) {
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