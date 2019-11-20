#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "UtilityModule.h"
#include"GameL/WinInputs.h"


//ReversibleClearCheck関数------------------------------------------------------------------
//引数1	 int	:ReversiblePanelのステージ配列
//戻り値 bool	:true…クリア　false…クリアではない
//内容	：ReversiblePanelのクリアチェック	
int ReversibleClearCheck(int rcc[5][5])
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
			if (rcc[i][j]!=Check[i][j])
			{
				return false;
			}
			else if (i==4&&j==4)
			{
				return true;
			}
		}
	}
}

//LoadRPStage関数---------------------------------------------------------------------------
//引数1　int：コピーするステージデータの指定
//引数2　int *：コピー先のステージ配列のポインタ
//引数3　int *：コピー先のカウント配列のポインタ
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

//SwitchClearCheck関数---------------------------------------------------------------------
//引数1	 int	:SwitchPanelのステージ配列
//戻り値 bool	:true…クリア　false…クリアではない
//内容	：SwitchPanelのクリアチェック	
int SwitchClearCheck(int scc[5][5])
{
	int Check[5][5] =
	{
		{1,2,1,2,1},
		{3,1,2,1,3},
		{1,3,1,3,1},
		{3,1,2,1,3},
		{1,2,1,2,1},
	};
	//ボタン以外が全て1(黒色)になっているかチェック
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (scc[i][j] != Check[i][j])
			{
				return false;
			}
			else if (i == 4 && j == 4)
			{
				return true;
			}
		}
	}
}

//LoadSPStage関数---------------------------------------------------------------------------
//引数1　int：コピーするステージデータの指定
//引数2　int *：コピー先のステージ配列のポインタ
//引数3　int *：コピー先のカウント配列のポインタ
//戻り値　無し
//内容：指定されたステージデータをコピーする
void LoadSPStage(int StaNum, int *Stage,int *Count)
{
	int SPStage1[5][5] =
	{
		{0,2,0,2,0},
		{3,0,2,0,3},
		{0,3,1,3,0},
		{3,0,2,0,3},
		{0,2,0,2,0},
	};
	int Count1[2] = { 6,12 };

	int SPStage2[5][5] =
	{
		{0,2,1,2,0},
		{3,1,2,0,3},
		{0,3,1,3,0},
		{3,0,2,1,3},
		{0,2,1,2,0},
	};
	int Count2[2] = { 6,12 };

	int SPStage3[5][5] =
	{
		{1,2,1,2,1},
		{3,0,2,1,3},
		{0,3,1,3,0},
		{3,1,2,0,3},
		{1,2,1,2,1},
	};
	int Count3[2] = { 6,12 };

	switch (StaNum)
	{
	case 1:
		memcpy(Stage, SPStage1, sizeof(int)*(5 * 5));
		memcpy(Count, Count1, sizeof(int) * 2);
		break;
	case 2:
		memcpy(Stage, SPStage2, sizeof(int)*(5 * 5));
		memcpy(Count, Count2, sizeof(int) * 2);
		break;
	case 3:
		memcpy(Stage, SPStage3, sizeof(int)*(5 * 5));
		memcpy(Count, Count3, sizeof(int) * 2);
		break;
	}
}