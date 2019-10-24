#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Reversibleメイン
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain(int map[5][5]);
	~CObjReversibleMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

private:
	int stage[5][5];

};