#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：Reversibleメイン
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain(int stage);
	~CObjReversibleMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	float x, y;
	

private:
	int stage[5][5];
	int stage_reset[5][5];
	//count管理用
	int count[3];  //[0]…最短手数判定用 [1]…手数表示用 [2]…手数リセット用
	//ステージ読み込み用
	int StageSlect;
	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;

	int sx, sy;
	//フラグ管理用
	bool flag[6];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [3]…Yes・Noフラグ [6]…Perfectフラグ
};