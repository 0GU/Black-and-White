#pragma once
//Reversible Panel�N���A�`�F�b�N�p�֐�
bool ReversibleClearCheck(int rcc[5][5]);
//Reversible Panel Stage�ǂݍ��ݗp�֐�
void LoadRPStage(int StaNum, int *Stage, int *Count);
//Reversible Panel ���]�����p�֐�
void ReversibleProcess(int bx, int by, int *ax, int *ay, int loop, int stage[][5]);