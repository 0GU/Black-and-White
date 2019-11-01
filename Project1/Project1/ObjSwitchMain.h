#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Reversibleメイン
class CObjSwitchMain : public CObj
{
public:
	CObjSwitchMain() {};
	~CObjSwitchMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	float x, y;


private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	bool flag[3];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ
};