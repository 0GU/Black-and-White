#pragma once

//Reversible Panelクリアチェック用関数
bool ReversibleClearCheck(int rcc[5][5]);
//Reversible Panel Stage読み込み用関数
void LoadRPStage(int StaNum, int *Stage, int *Count);
//Switch Panelクリアチェック用関数
bool SwitchClearCheck(int scc[5][5]);
//Switch Panel Stage	読み込み用関数
void LoadSPStage(int StaNum, int *Stage,int *Count);

