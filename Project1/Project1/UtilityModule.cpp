#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "UtilityModule.h"
#include"GameL/WinInputs.h"


//ReversibleClearCheck�֐�------------------------------------------------------------------
//���o�[�V�u���p�l�������ׂ�1(���p�l��)�ɂȂ������̑Ή�
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



//SwitchClearCheck�֐�---------------------------------------------------------------------
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


//LoadRPStage�֐�---------------------------------------------------------------------------
void LoadRPStage(int StaNum, int *Stage)
{
	int Stage3[5][5] =
	{
	{0,1,1,0,1},
	{1,0,1,1,0},
	{1,1,0,1,0},
	{1,0,0,0,1},
	{0,1,1,1,1},
	};
	switch (StaNum)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		memcpy(Stage, Stage3, sizeof(int)*(5 * 5));
		break;
	}
}

//LoadSPStage�֐�---------------------------------------------------------------------------
void LoadSPStage(int StaNum, int *Stage)
{
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
		break;
	case 1:
		break;
	case 2:
		memcpy(Stage, SPStage3, sizeof(int)*(5 * 5));
		break;
	}
}

//LoadRPCount�֐�------------------------------------------------------------------------------
void LoadRPCount(int StaNum,int *Count)
{
	int Count3[2] = { 6,22 };

	switch (StaNum)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		memcpy(Count, Count3, sizeof(int)*(2));
		break;
	}
}