#pragma once

//Reversible Panel�N���A�`�F�b�N�p�֐�
int ReversibleClearCheck(int rcc[5][5]);

//Switch Panel�N���A�`�F�b�N�p�֐�
int SwitchClearCheck(int rcc[5][5]);
//Switch Panel Stage	�ǂݍ��ݗp�֐�
void LoadSPStage(int StaNum, int *Stage);
//Reversible Panel Stage�ǂݍ��ݗp�֐�
void LoadRPStage(int StaNum, int *Stage);

//Reversible Panel Count�ǂݍ��ݗp�֐�
void LoadRPCount(int StaNum, int *Count);

//Switch Panel Count�ǂݍ��ݗp�ϐ�
void LoadSPCount(int StaNum, int *Count);