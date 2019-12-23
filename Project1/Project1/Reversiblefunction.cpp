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
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,1,1,1,1},
	{0,0,0,0,0},
	{0,0,0,0,0},
	};
	int Count2[2] = { 6,16 };

	int Stage3[5][5] =
	{
	{0,1,1,0,1},
	{1,0,1,1,0},
	{1,1,0,1,0},
	{1,0,0,0,1},
	{0,1,1,1,1},
	};
	int Count3[2] = { 6,18 };

	int Stage4[5][5] =
	{
	{0,1,0,1,0},
	{0,0,0,0,0},
	{1,1,0,1,1},
	{1,1,0,1,1},
	{0,0,0,0,0},
	};
	int Count4[2] = { 10,20 };

	int Stage5[5][5] =
	{
	{1,0,0,1,0},
	{1,0,1,0,1},
	{1,1,1,1,1},
	{1,0,1,0,1},
	{1,0,0,1,0},
	};
	int Count5[2] = { 10,22 };

	int Stage6[5][5] =
	{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	};
	int Count6[2] = { 13,25 };

	int Stage99[5][5] =
	{
	{0,3,2,3,0},
	{3,1,3,1,3},
	{2,3,3,3,2},
	{3,1,3,1,3},
	{0,3,2,3,0},
	};

	//指定されたステージデータのコピー
	switch (StaNum)
	{
	case 99:
		memcpy(Stage, Stage99, sizeof(int)*(5 * 5));
		break;
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
	case 4:
		memcpy(Stage, Stage4, sizeof(int)*(5 * 5));
		memcpy(Count, Count4, sizeof(int) * 2);
		break;
	case 5:
		memcpy(Stage, Stage5, sizeof(int)*(5 * 5));
		memcpy(Count, Count5, sizeof(int) * 2);
		break;
	case 6:
		memcpy(Stage, Stage6, sizeof(int)*(5 * 5));
		memcpy(Count, Count6, sizeof(int) * 2);
		break;
	}
}

//ReversibleProcess関数---------------------------------------------------------------------
//引数1　int bx			：クリックしたステージ配列のX座標
//引数2　int by			：クリックしたステージ配列のY座標
//引数3　int *ax		：変更したxの値を保存するポインタ変数
//引数4　int *ay		：変更したyの値を保存するポインタ変数
//引数5  int loop		：スイッチに使用する変数
//引数6　int *stage[][5]：ステージ配列のポインタ
//戻り値　無し
//内容：クリックした配列とその上下左右の値をポインタで渡す
void ReversibleProcess(int bx, int by, int *ax,int *ay,int loop,int stage[][5])
{
	switch (loop)
	{
	case 0://上
		*ax = bx;
		*ay = by - 1;
		break;
	case 1://左
		*ax = bx - 1;
		*ay = by;
		break;
	case 2://クリックした場所
		*ax = bx;
		*ay = by;
		break;
	case 3://右
		*ax = bx + 1;
		*ay = by;
		break;
	case 4://下
		*ax = bx;
		*ay = by + 1;
		break;
	}
}
