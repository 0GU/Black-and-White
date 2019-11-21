#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Reversiblefunction.h"
#include"GameL/WinInputs.h"
#include "ObjReversibleMain.h"

//ReversibleClearCheck関数------------------------------------------------------------------
//引数1	 int　rcc[5][5]	:ReversiblePanelのステージ配列
//戻り値 bool			:true…クリア　false…クリアではない
//内容	：ReversiblePanelのクリアチェック	
bool ReversibleClearCheck(int rcc[5][5])
{
	int Check[5][5] =
	{
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
	};

	//全て1(黒色)になっているかチェック
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (rcc[i][j] != Check[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

//LoadRPStage関数---------------------------------------------------------------------------
//引数1　int StaNum：コピーするステージデータの指定
//引数2　int *Stage：コピー先のステージ配列のポインタ
//引数3　int *Count：コピー先のカウント配列のポインタ
//戻り値　無し
//内容：指定されたステージデータをコピーする
void LoadRPStage(int StaNum, int *Stage, int *Count)
{
	int Stage1[5][5] =
	{
	{1,1,1,0,1},
	{1,0,0,0,0},
	{0,0,0,1,1},
	{1,0,0,0,0},
	{1,1,1,0,1},
	};
	int Count1[2] = { 3,6 };

	int Stage2[5][5] =
	{
	{0,1,1,0,1},
	{1,0,1,1,0},
	{1,1,0,1,0},
	{1,0,0,0,1},
	{0,1,1,1,1},
	};
	int Count2[2] = { 6,22 };

	int Stage3[5][5] =
	{
	{1,0,0,1,0},
	{1,0,1,0,1},
	{1,1,1,1,1},
	{1,0,1,0,1},
	{1,0,0,1,0},
	};
	int Count3[2] = { 10,25 };

	//指定されたステージデータのコピー
	switch (StaNum)
	{
	case 1:
		memcpy(Stage, Stage1, sizeof(int)*(5 * 5));
		memcpy(Count, Count1, sizeof(int) * 2);
		break;
	case 2:
		memcpy(Stage, Stage2, sizeof(int)*(5 * 5));
		memcpy(Count, Count2, sizeof(int) * 2);
		break;
	case 3:
		memcpy(Stage, Stage3, sizeof(int)*(5 * 5));
		memcpy(Count, Count3, sizeof(int) * 2);
		break;
	}
}

//ReversibleProcess関数---------------------------------------------------------------------
//引数1　int bx			：クリックしたステージ配列のX座標
//引数2　int by			：クリックしたステージ配列のY座標
//引数3  int loop		：スイッチに使用する変数
//引数4　int *stage[][5]：ステージ配列のポインタ
//引数5　bool flag		：false…タイムを増やすさない　true…タイムを増やす
//引数6  int *aniflame	：アニメーションを動かすためのポインタ変数
//引数7　bool aniflag	：false…配列の数値変更　true…反転アニメーション　(デフォルト…false)
//戻り値　無し
//内容：反転処理
/*void ReversibleProcess(int bx, int by, int loop,int stage[5][5],  bool flag,int *aniflame,bool aniflag)
{
	int ax, ay;
	int m_time = 0;
	switch (loop)
	{
	case 0://上
		ax = bx;
		ay = by - 1;
		break;
	case 1://左
		ax = bx - 1;
		ay = by;
		break;
	case 2://クリックした場所
		ax = bx;
		ay = by;
		break;
	case 3://右
		ax = bx + 1;
		ay = by;
		break;
	case 4://下
		ax = bx;
		ay = by + 1;
		break;
	}
	if (aniflag == false)
	{
		//反転処理の準備
		if (ax >= 0 && ay >= 0 && ax <= 4 && ay <= 4)
		{
			//反転中を示す値に変更する
			if (stage[ay][ax] == 0)
			{
				stage[ay][ax] = 2;
			}
			else if (stage[ay][ax] == 1)
			{

				stage[ay][ax] = 3;
			}
		}
	}
	else if(aniflag==true)
	{
		if (ax >= 0 && ay >= 0 && ax <= 4 && ay <= 4)
		{
			if (stage[ax][ay] == 2)//反転白パネル
			{
				//タイムを増やす（ループ中１回のみ）
				if (flag == true)
				{
					m_time++;
					flag = false;
				}
				//アニメーションを動かす
				if (m_time == 3) {
					*aniflame++;
					m_time = 0;
				}
				//アニメーションが終了したら黒パネルに変更
				if (*aniflame == 8)
				{
					stage[ay][ax] = 1;
				}

			}
			if (stage[ay][ax] == 3)//反転黒パネル
			{
				//タイムを増やす（ループ中１回のみ）
				if (flag == true)
				{
					m_time++;
					flag = false;
				}
				//アニメーションを動かす
				if (m_time == 3) {
					*aniflame++;
					m_time = 0;
				}
				//アニメーションが終了したら白パネルに変更
				if (*aniflame == 8)
				{
					stage[ay][ax] = 0;
				}

			}

		}
	}
}*/
