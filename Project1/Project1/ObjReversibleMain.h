#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Reversibleメイン
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain() {};
	~CObjReversibleMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	float x, y;
	bool hint;

private:
	int stage[5][5];
	int stage_reset[5][5];
	
};