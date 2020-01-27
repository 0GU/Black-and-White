#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

#define RESOURCE_SCENE_TEXT_T (138.0f)
#define RESOURCE_SCENE_TEXT_L (3.0f)
#define RESOURCE_SCENE_TEXT_R (554.0f)
#define RESOURCE_SCENE_TEXT_B (262.0f)
#define RESOURCE_SELECT_L (0.0f)
#define RESOURCE_SELECT_R (600.0f)
#define RESOURCE_SW_SELECT_T (658.0f)
#define RESOURCE_SW_SELECT_B (748.0f)
#define RESOURCE_RP_SELECT_T (747.0f)
#define RESOURCE_RP_SELECT_B (838.0f)
#define RESOURCE_BACK_T (139.0f)
#define RESOURCE_BACK_L (559.0f)
#define RESOURCE_BACK_R (679.0f)
#define RESOURCE_BACK_B (239.0f)

#define SCENE_TEXT_POS_T (20.0f)
#define SCENE_TEXT_POS_L (130.0f)
#define SCENE_TEXT_POS_R (690.0f)
#define SCENE_TEXT_POS_B (155.0f)
#define SELECT_POS_L (100.0f)
#define SELECT_POS_R (700.0f)
#define SW_SELECT_POS_T (200.0f)
#define SW_SELECT_POS_B (290.0f)
#define RP_SELECT_POS_T (400.0f)
#define RP_SELECT_POS_B (485.0f)
#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

//切り取り&表示 : 背景
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)

//Helpボタン
#define CUT_HELPBUTTON_T (100.0f)
#define CUT_HELPBUTTON_L (924.0f)
#define CUT_HELPBUTTON_R (1024.0f)
#define CUT_HELPBUTTON_B (200.0f)
#define POS_HELPBUTTON_T (40.0f)
#define POS_HELPBUTTON_L (680.0f)
#define POS_HELPBUTTON_R (780.0f)
#define POS_HELPBUTTON_B (140.0f)

//ヘルプ表示
#define CUT_HELP_T (0.0f)
#define CUT_HELP_L (0.0f)
#define CUT_HELP_R (1280.0f)
#define CUT_HELP_B (720.0f)
#define POS_HELP_T (0.0f)
#define POS_HELP_L (0.0f)
#define POS_HELP_R (800.0f)
#define POS_HELP_B (600.0f)

//オブジェクト：ゲームセレクト
class CObjGameSelect : public CObj
{
public:
	CObjGameSelect() {};
	~CObjGameSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float x, y;
private:
	float m_y1;
	float m_y2;
	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす
	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	bool f;
	char but;
	bool help_flag;//help表示用

};
