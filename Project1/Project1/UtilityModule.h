#pragma once

//Reversible Panelクリアチェック用関数
int ReversibleClearCheck(int rcc[5][5]);

//Switch Panelクリアチェック用関数
int SwitchClearCheck(int rcc[5][5]);
int ReversibleClearCheck(int rcc[5][5]);

//Reversible Panel Stage	読み込み用関数
void LoadRPStage(int StaNum, int *Stage);

//Switch Panel Stage	読み込み用関数
void LoadSPStage(int StaNum, int *Stage);