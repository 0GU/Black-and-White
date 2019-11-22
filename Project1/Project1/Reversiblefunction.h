#pragma once
//Reversible Panelクリアチェック用関数
bool ReversibleClearCheck(int rcc[5][5]);
//Reversible Panel Stage読み込み用関数
void LoadRPStage(int StaNum, int *Stage, int *Count);
//Reversible Panel 反転処理用関数
void ReversibleProcess(int bx, int by, int *ax, int *ay, int loop, int stage[][5]);