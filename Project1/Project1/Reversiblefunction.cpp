#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Reversiblefunction.h"
#include"GameL/WinInputs.h"

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
