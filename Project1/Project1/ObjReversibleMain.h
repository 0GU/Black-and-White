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
	

private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	bool flag[4];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [3]…	Yes・Noフラグ

	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
};