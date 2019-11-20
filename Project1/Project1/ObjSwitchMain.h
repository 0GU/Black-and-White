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
	static bool Gflag[3]; //[0]…Stage1、[1]…Stage2　[2]…Stage3	のPerfectフラグ
	static void GetFlag(bool flag[3]);
private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	int count[2];  //[0]…PerfectClearcount [1]…Clearcount
	int StageSlect;


	int sx, sy;		//マウスを押した位置を保存
	
	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	float r;		//アニメーションの角度変更用

	bool flag[6];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [6]…Perfectフラグ
};