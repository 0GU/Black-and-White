#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Switchfunction.h"
#include"GameL/WinInputs.h"

//SwitchClearCheck�֐�---------------------------------------------------------------------
//����1	 int scc[5][5]	:SwitchPanel�̃X�e�[�W�z��
//�߂�l bool			:true�c�N���A�@false�c�N���A�ł͂Ȃ�
//���e	�FSwitchPanel�̃N���A�`�F�b�N	
bool SwitchClearCheck(int scc[5][5])
{
	int Check[5][5] =
	{
		{1,99,1,99,1},
		{99,1,99,1,99},
		{1,99,1,99,1},	//1�c���p�l���@99�c�{�^��
		{99,1,99,1,99},
		{1,99,1,99,1},
	};

	//�{�^���ȊO���S��1(���F)�ɂȂ��Ă��邩�`�F�b�N
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Check[i][j] == 99)
				;
			else if (scc[i][j] != Check[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

//LoadSPStage�֐�---------------------------------------------------------------------------
//����1�@int StaNum�F�R�s�[����X�e�[�W�f�[�^�̎w��
//����2�@int *Stage�F�R�s�[��̃X�e�[�W�z��̃|�C���^
//����3�@int *Count�F�R�s�[��̃J�E���g�z��̃|�C���^
//�߂�l�@����
//���e�F�w�肳�ꂽ�X�e�[�W�f�[�^���R�s�[����
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

	int SPStage4[5][5] =
	{
		{0,4,1,6,0},
		{3,0,5,1,6},
		{0,3,1,7,0},
		{3,1,4,1,3},
		{0,7,1,2,1},
	};
	int Count4[2] = { 10,25 };

	int SPStage5[5][5] =
	{
		{0,2,1,5,0},
		{7,0,5,1,3},
		{1,7,0,4,1},
		{7,1,3,1,3},
		{0,7,0,7,0},
	};
	int Count5[2] = { 9,24 };

	int SPStage6[5][5] =
	{
		{0,4,1,6,0},
		{4,1,5,1,7},
		{0,7,1,7,0},
		{4,0,8,1,5},
		{0,4,1,4,0},
	};
	int Count6[2] = { 11,26 };

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
	case 4:
		memcpy(Stage, SPStage4, sizeof(int)*(5 * 5));
		memcpy(Count, Count4, sizeof(int) * 2);
		break;
	case 5:
		memcpy(Stage, SPStage5, sizeof(int)*(5 * 5));
		memcpy(Count, Count5, sizeof(int) * 2);
		break;
	case 6:
		memcpy(Stage, SPStage6, sizeof(int)*(5 * 5));
		memcpy(Count, Count6, sizeof(int) * 2);
		break;
	}
}