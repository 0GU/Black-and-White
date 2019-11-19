#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL\Audio.h"
#include "UtilityModule.h"


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
	int stage_data[5][5] = {};   //ステージ用配列

	//ステージ読み込み用関数
	LoadRPStage(StageSlect, *stage_data);
	//カウント読み込み用関数
	LoadRPCount(StageSlect, count);
	//カウントリセット用に初期カウントを保存する
	count[2] = count[1];

	//マップデータをコピー
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
	//リセット用配列にコピー
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));
	
	//フラグを初期化
	bool flag_set[5] =
	{ false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(5));

	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
}

//アクション
void CObjReversibleMain::Action()
{
	int lx, ly;//反転処理用変数

	//マウスの座標を読み込む
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	//当たり判定---------------------------------------------------------------------------------------------------------
	if (160 <= x && 640 >= x && 60 <= y && 540 >= y && flag[1] == false && flag[2] == false && flag[3] == false)
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

				sx = (y - 60) / 96;   //クリック時のy座標を配列で使えるように直す
				sy = (x - 160) / 96;  //クリック時のx座標を配列で使えるように直す
				for (int m = 0; m < 5; m++)
				{
					switch (m)
					{
					case 0://上
						lx = sx;
						ly = sy - 1;
						break;
					case 1://左
						lx = sx - 1;
						ly = sy;
						break;
					case 2://クリックした場所
						lx = sx;
						ly = sy;
						break;
					case 3://右
						lx = sx + 1;
						ly = sy;
						break;
					case 4://下
						lx = sx;
						ly = sy + 1;
						break;
					}
					//反転処理の準備
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
					{
						//反転中を示す値に変更する
						if (stage[lx][ly] == 0)
						{
							stage[lx][ly] = 2;
						}
						else if (stage[lx][ly] == 1)
						{

							stage[lx][ly] = 3;
						}
					}
				}
				while (Input::GetMouButtonL() == true)
				{

				}
				
			}
		}

	
	
	}
	//反転アニメーション処理------------------------------
	
	time_flag = true;//ループ中１回だけタイムを増やす

	for (int m = 0; m < 5; m++)
	{
		switch (m)
		{
		case 0://上
			lx = sx;
			ly = sy - 1;
			break;
		case 1://左
			lx = sx - 1;
			ly = sy;
			break;
		case 2:
			lx = sx;
			ly = sy;
			break;
		case 3://右
			lx = sx + 1;
			ly = sy;
			break;
		case 4://下
			lx = sx;
			ly = sy + 1;
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[lx][ly] == 2)//反転白パネル
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
					stage[lx][ly] = 1;
				}

			}
			if (stage[lx][ly] == 3)//反転黒パネル
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
					stage[lx][ly] = 0;
				}

			}

		}
	}

	//反転終了処理
	if (m_ani_flame == 8)
	{
		m_ani_flame = 0;	//初期化
		m_change = true;	//パネルを動かせるようにする

		if (ReversibleClearCheck(stage) == true)	//クリア条件を満たした
		{
			//パーフェクト条件を満たしている
			if (count[2] - count[0]==count[1])
			{
				flag[4] = true;
			}
			Audio::Start(3);
			flag[1] = true;
		}
		else if (ReversibleClearCheck(stage) == false && count[1] == 0&&m_change==true)	//ゲームオーバー条件を満たした
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
		//StageSelectへ戻るボタン判定
		if (x >= 130 && x <= 690 && y >= 370 && y <= 490)
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
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = 22;
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
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
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
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y && flag[1] == false && flag[2] == false&& m_ani_flame == 0)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = count[2];
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//ヒントボタン当たり判定----------------------------------------------------------------
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{

			flag[0] = true;
			//SEを鳴らす
			Audio::Start(1);
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
		//BGM停止
		Audio::Stop(0);
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
				Scene::SetScene(new CSceneReversibleSelect());
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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 96.0f;
	src.m_bottom = 96.0f;
	
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
				dst.m_top = i * 96.0f+60.0f-12.0f;
				dst.m_left = j * 96.0f+160.0f;
				dst.m_right = dst.m_left + 96.0;
				dst.m_bottom = dst.m_top + 120.0;
				if (stage[i][j] == 0)
				{
					src.m_top = 120.0;
					src.m_left = 0.0f;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//白パネル
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				else if (stage[i][j] == 1)
				{
					src.m_top = 0.0f ;
					src.m_left = 0.0f;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//黒パネル
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				if (stage[i][j] == 2)
				{
					src.m_top = 120.0f- (AniData[m_ani_flame]/4)*120;
					src.m_left = 96.0f +( AniData[m_ani_flame]%4) * 96;
					src.m_right = src.m_left-96.0f;
					src.m_bottom = 120.0f + src.m_top;
					//反転白パネル
					Draw::Draw(6, &src, &dst, c, 0.0f);
				}
				else if (stage[i][j] == 3)
				{
					src.m_top = 0.0f+ (AniData[m_ani_flame]/4)*120;
					src.m_left = 0.0f +( AniData[m_ani_flame]%4) * 96;
					src.m_right = 96.0f + src.m_left;
					src.m_bottom = 120.0f + src.m_top;
					//反転黒パネル
					Draw::Draw(6, &src, &dst, c, 0.0f);
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
		//シーン描画：GameClear!------------------------------------
		if (flag[1] == true)
		{


				src.m_top = 249.0f;
				src.m_left = 0.0f;
				src.m_right = 560.0f;
				src.m_bottom = 372.0f;
				dst.m_top = 150.0f;
				dst.m_left = 130.0f;
				dst.m_right = 690.0;
				dst.m_bottom = 270.0;
				Draw::Draw(5, &src, &dst, c, 0.0f);

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
			src.m_top = 820.0f;
			src.m_left = 0.0f;
			src.m_right = 239.0f;
			src.m_bottom = 939.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = 820.0f;
			src.m_left = 239.0f;
			src.m_right = 478.0f;
			src.m_bottom = 939.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}
		//Perfect表示
		if (flag[4] == true)
		{
			Font::StrDraw(L"Perfect!!", 100, 10, 32, f);

		}
}