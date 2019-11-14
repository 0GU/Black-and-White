#pragma once

//Reversible Panelクリアチェック用関数
int ReversibleClearCheck(int rcc[5][5]);

//Switch Panelクリアチェック用関数
int SwitchClearCheck(int rcc[5][5]);
//Switch Panel Stage	読み込み用関数
void LoadSPStage(int StaNum, int *Stage);
//Reversible Panel Stage読み込み用関数
void LoadRPStage(int StaNum, int *Stage);

//Reversible Panel Count読み込み用関数
void LoadRPCount(int StaNum, int *Count);

//Switch Panel Count読み込み用変数
void LoadSPCount(int StaNum, int *Count);