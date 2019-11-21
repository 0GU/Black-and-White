#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Switchfunction.h"
#include"GameL/WinInputs.h"

//SwitchClearCheck関数---------------------------------------------------------------------
//引数1	 int scc[5][5]	:SwitchPanelのステージ配列
//戻り値 bool			:true…クリア　false…クリアではない
//内容	：SwitchPanelのクリアチェック	
bool SwitchClearCheck(int scc[5][5])
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
		}
	}
	return true;
}

//LoadSPStage関数---------------------------------------------------------------------------
//引数1　int StaNum：コピーするステージデータの指定
//引数2　int *Stage：コピー先のステージ配列のポインタ
//引数3　int *Count：コピー先のカウント配列のポインタ
//戻り値　無し
//内容：指定されたステージデータをコピーする
void LoadSPStage(int StaNum, int *Stage, int *Count)
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