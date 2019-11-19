#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "UtilityModule.h"
#include"GameL/WinInputs.h"


//ReversibleClearCheck関数------------------------------------------------------------------
//リバーシブルパネルがすべて1(黒パネル)になった時の対応
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



//SwitchClearCheck関数---------------------------------------------------------------------
int SwitchClearCheck(int rcc[5][5])
{
	int Check[5][5] =
	{
		{1,2,1,2,1},
		{3,1,2,1,3},
		{1,3,1,3,1},
		{3,1,2,1,3},
		{1,2,1,2,1},
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (rcc[i][j] != Check[i][j])
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


//LoadRPStage関数---------------------------------------------------------------------------
void LoadRPStage(int StaNum, int *Stage)
{
	int Stage1[5][5] =
	{
	{1,1,1,0,1},
	{1,0,0,0,0},
	{0,0,0,1,1},
	{1,0,0,0,0},
	{1,1,1,0,1},
	};

	int Stage2[5][5] =
	{
	{0,1,1,0,1},
	{1,0,1,1,0},
	{1,1,0,1,0},
	{1,0,0,0,1},
	{0,1,1,1,1},
	};

	int Stage3[5][5] =
	{
	{1,0,0,1,0},
	{1,0,1,0,1},
	{1,1,1,1,1},
	{1,0,1,0,1},
	{1,0,0,1,0},
	};

	switch (StaNum)
	{
	case 1:
		memcpy(Stage, Stage1, sizeof(int)*(5 * 5));
		break;
	case 2:
		memcpy(Stage, Stage2, sizeof(int)*(5 * 5));
		break;
	case 3:
		memcpy(Stage, Stage3, sizeof(int)*(5 * 5));
		break;
	}
}

//LoadSPStage関数---------------------------------------------------------------------------
void LoadSPStage(int StaNum, int *Stage)
{
	int SPStage1[5][5] =
	{
		{0,2,0,2,0},
		{3,0,2,0,3},
		{0,3,1,3,0},
		{3,0,2,0,3},
		{0,2,0,2,0},
	};

	int SPStage2[5][5] =
	{
		{0,2,1,2,0},
		{3,1,2,0,3},
		{0,3,1,3,0},
		{3,0,2,1,3},
		{0,2,1,2,0},
	};

	int SPStage3[5][5] =
	{
		{1,2,1,2,1},
		{3,0,2,1,3},
		{0,3,1,3,0},
		{3,1,2,0,3},
		{1,2,1,2,1},
	};

	switch (StaNum)
	{
	case 0:
		memcpy(Stage, SPStage1, sizeof(int)*(5 * 5));
		break;
	case 1:
		memcpy(Stage, SPStage2, sizeof(int)*(5 * 5));
		break;
	case 2:
		memcpy(Stage, SPStage3, sizeof(int)*(5 * 5));
		break;
	}
}

//LoadRPCount関数------------------------------------------------------------------------------
void LoadRPCount(int StaNum,int *Count)
{
	int Count1[2] = { 3,6 };

	int Count2[2] = { 6,22 };

	int Count3[2] = { 10,25 };

	switch (StaNum)
	{
	case 1:
		memcpy(Count, Count1, sizeof(int)*(2));
		break;
	case 2:
		memcpy(Count, Count2, sizeof(int)*(2));
		break;
	case 3:
		memcpy(Count, Count3, sizeof(int)*(2));
		break;
	}
}

//LoadSPCount関数------------------------------------------------------------------------------
void LoadSPCount(int StaNum, int *Count)
{
	int Count1[2] = { 6,12 };
	int Count2[2] = { 6,12 };
	int Count3[2] = { 6,12 };

	switch (StaNum)
	{
	case 0:
		memcpy(Count, Count1, sizeof(int)*(2));
		break;
	case 1:
		memcpy(Count, Count2, sizeof(int)*(2));
		break;
	case 2:
		memcpy(Count, Count3, sizeof(int)*(2));
		break;
	}
}