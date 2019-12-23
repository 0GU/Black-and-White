#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Reversiblefunction.h"
#include"GameL/WinInputs.h"
#include "ObjReversibleMain.h"

//ReversibleClearCheck�֐�------------------------------------------------------------------
//����1	 int�@rcc[5][5]	:ReversiblePanel�̃X�e�[�W�z��
//�߂�l bool			:true�c�N���A�@false�c�N���A�ł͂Ȃ�
//���e	�FReversiblePanel�̃N���A�`�F�b�N	
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

	//�S��1(���F)�ɂȂ��Ă��邩�`�F�b�N
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

//LoadRPStage�֐�---------------------------------------------------------------------------
//����1�@int StaNum�F�R�s�[����X�e�[�W�f�[�^�̎w��
//����2�@int *Stage�F�R�s�[��̃X�e�[�W�z��̃|�C���^
//����3�@int *Count�F�R�s�[��̃J�E���g�z��̃|�C���^
//�߂�l�@����
//���e�F�w�肳�ꂽ�X�e�[�W�f�[�^���R�s�[����
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

	//�w�肳�ꂽ�X�e�[�W�f�[�^�̃R�s�[
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

//ReversibleProcess�֐�---------------------------------------------------------------------
//����1�@int bx			�F�N���b�N�����X�e�[�W�z���X���W
//����2�@int by			�F�N���b�N�����X�e�[�W�z���Y���W
//����3�@int *ax		�F�ύX����x�̒l��ۑ�����|�C���^�ϐ�
//����4�@int *ay		�F�ύX����y�̒l��ۑ�����|�C���^�ϐ�
//����5  int loop		�F�X�C�b�`�Ɏg�p����ϐ�
//����6�@int *stage[][5]�F�X�e�[�W�z��̃|�C���^
//�߂�l�@����
//���e�F�N���b�N�����z��Ƃ��̏㉺���E�̒l���|�C���^�œn��
void ReversibleProcess(int bx, int by, int *ax,int *ay,int loop,int stage[][5])
{
	switch (loop)
	{
	case 0://��
		*ax = bx;
		*ay = by - 1;
		break;
	case 1://��
		*ax = bx - 1;
		*ay = by;
		break;
	case 2://�N���b�N�����ꏊ
		*ax = bx;
		*ay = by;
		break;
	case 3://�E
		*ax = bx + 1;
		*ay = by;
		break;
	case 4://��
		*ax = bx;
		*ay = by + 1;
		break;
	}
}
