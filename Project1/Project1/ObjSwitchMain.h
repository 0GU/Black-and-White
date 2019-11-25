#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ

/*
resource
	//StageSelectボタン-----------------------------------------------
	//切り取り
	src.m_top = 820.0f;
	src.m_left = 478.0f;
	src.m_right = 600.0f;
	src.m_bottom = 920.0f;
*/

#define RESOURCE_SELE_BUTTON_T (820.0f)
#define RESOURCE_SELE_BUTTON_L (478.0f)
#define RESOURCE_SELE_BUTTON_R (600.0f)
#define RESOURCE_SELE_BUTTON_B (920.0f)
#define RESOURCE_PERFECT_T (370.0f)
#define RESOURCE_PERFECT_L (0.0f)
#define RESOURCE_PERFECT_R (560.0f)
#define RESOURCE_PERFECT_B (491.0f)
#define RESOURCE_GAMECLEAR_T (249.0f)
#define RESOURCE_GAMECLEAR_L (0.0f)
#define RESOURCE_GAMECLEAR_R (560.0f)
#define RESOURCE_GAMECLEAR_B (372.0f)
#define RESOURCE_CLEARBACK_T (490.0f)
#define RESOURCE_CLEARBACK_L (0.0f)
#define RESOURCE_CLEARBACK_R (560.0f)
#define RESOURCE_CLEARBACK_B (610.0f)
#define RESOURCE_GAMEOVER_T (0.0f)
#define RESOURCE_GAMEOVER_L (0.0f)
#define RESOURCE_GAMEOVER_R (580.0f)
#define RESOURCE_GAMEOVER_B (250.0f)
#define RESOURCE_YESNO_BUTTON_T (820.0f)
#define RESOURCE_YESNO_BUTTON_B (940.0f)
#define RESOURCE_YES_BUTTON_L (0.0f)
#define RESOURCE_YES_BUTTON_R (240.0f)
#define RESOURCE_NO_BUTTON_L (239.0f)
#define RESOURCE_NO_BUTTON_R (479.0f)
#define RESOURCE_BACKSELECT_T (0.0f)
#define RESOURCE_BACKSELECT_L (0.0f)
#define RESOURCE_BACKSELECT_R (520.0f)
#define RESOURCE_BACKSELECT_B (91.0f)

/*
	//表示
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = 60.0f;
	dst.m_left = 30.0f;
	dst.m_right = 130.0;
	dst.m_bottom = 160.0f;
*/
#define STAGESELE_BUTTON_POS_T (60.0f)
#define STAGESELE_BUTTON_POS_L (30.0f)
#define STAGESELE_BUTTON_POS_R (130.0f)
#define STAGESELE_BUTTON_POS_B (160.0f)
#define PERFECT_TEXT_POS_T (150.0f)
#define PERFECT_TEXT_POS_L (100.0f)
#define PERFECT_TEXT_POS_R (690.0f)
#define PERFECT_TEXT_POS_B (300.0f)
#define GAMECLEAR_TEXT_POS_T (150.0f)
#define GAMECLEAR_TEXT_POS_L (130.0f)
#define GAMECLEAR_TEXT_POS_R (690.0f)
#define GAMECLEAR_TEXT_POS_B (270.0f)
#define CLEARBACK_POS_T (370.0f)
#define CLEARBACK_POS_L (130.0f)
#define CLEARBACK_POS_R (690.0f)
#define CLEARBACK_POS_B (490.0f)
#define GAMEOVER_TEXT_POS_T (70.0f)
#define GAMEOVER_TEXT_POS_L (110.0f)
#define GAMEOVER_TEXT_POS_R (690.0f)
#define GAMEOVER_TEXT_POS_B (320.0f)
#define YESNO_BUTTON_POS_T (370.0f)
#define YESNO_BUTTON_POS_B (490.0f)
#define YES_BUTTON_POS_L (130.0f)
#define YES_BUTTON_POS_R (370.0f)
#define NO_BUTTON_POS_L (410.0f)
#define NO_BUTTON_POS_R (649.0f)
#define BACKSELECT_TEXT_POS_T (150.0f)
#define BACKSELECT_TEXT_POS_L (130.0f)
#define BACKSELECT_TEXT_POS_R (650.0f)
#define BACKSELECT_TEXT_POS_B (270.0f)


//オブジェクト：Reversibleメイン
class CObjSwitchMain : public CObj
{
public:
	CObjSwitchMain(int stage);
	~CObjSwitchMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	float x, y;
private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	int count[3];  //[0]…PerfectClearcount [1]…Clearcount [2]…Countreset
	int StageSlect;

	int sx, sy;		//マウスを押した位置を保存
	
	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	float r;		//アニメーションの角度変更用

	bool flag[7];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [6]…Perfectフラグ
};