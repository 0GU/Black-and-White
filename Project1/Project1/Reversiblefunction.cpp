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

	//�w�肳�ꂽ�X�e�[�W�f�[�^�̃R�s�[
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

//ReversibleProcess�֐�---------------------------------------------------------------------
//����1�@int bx			�F�N���b�N�����X�e�[�W�z���X���W
//����2�@int by			�F�N���b�N�����X�e�[�W�z���Y���W
//����3  int loop		�F�X�C�b�`�Ɏg�p����ϐ�
//����4�@int *stage[][5]�F�X�e�[�W�z��̃|�C���^
//����5�@bool flag		�Ffalse�c�^�C���𑝂₷���Ȃ��@true�c�^�C���𑝂₷
//����6  int *aniflame	�F�A�j���[�V�����𓮂������߂̃|�C���^�ϐ�
//����7�@bool aniflag	�Ffalse�c�z��̐��l�ύX�@true�c���]�A�j���[�V�����@(�f�t�H���g�cfalse)
//�߂�l�@����
//���e�F���]����
/*void ReversibleProcess(int bx, int by, int loop,int stage[5][5],  bool flag,int *aniflame,bool aniflag)
{
	int ax, ay;
	int m_time = 0;
	switch (loop)
	{
	case 0://��
		ax = bx;
		ay = by - 1;
		break;
	case 1://��
		ax = bx - 1;
		ay = by;
		break;
	case 2://�N���b�N�����ꏊ
		ax = bx;
		ay = by;
		break;
	case 3://�E
		ax = bx + 1;
		ay = by;
		break;
	case 4://��
		ax = bx;
		ay = by + 1;
		break;
	}
	if (aniflag == false)
	{
		//���]�����̏���
		if (ax >= 0 && ay >= 0 && ax <= 4 && ay <= 4)
		{
			//���]���������l�ɕύX����
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
			if (stage[ax][ay] == 2)//���]���p�l��
			{
				//�^�C���𑝂₷�i���[�v���P��̂݁j
				if (flag == true)
				{
					m_time++;
					flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == 3) {
					*aniflame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������獕�p�l���ɕύX
				if (*aniflame == 8)
				{
					stage[ay][ax] = 1;
				}

			}
			if (stage[ay][ax] == 3)//���]���p�l��
			{
				//�^�C���𑝂₷�i���[�v���P��̂݁j
				if (flag == true)
				{
					m_time++;
					flag = false;
				}
				//�A�j���[�V�����𓮂���
				if (m_time == 3) {
					*aniflame++;
					m_time = 0;
				}
				//�A�j���[�V�������I�������甒�p�l���ɕύX
				if (*aniflame == 8)
				{
					stage[ay][ax] = 0;
				}

			}

		}
	}
}*/
