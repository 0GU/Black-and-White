#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SELECT_WAIT		   (100)
#define HIT_LEFT		   (120.0f)
#define HIT_RIGHT		   (680.0f)
#define HIT_TOP_SELECT	   (130.0f)
#define HIT_BOTTOM_SELECT  (265.0f)
#define HIT_TOP_GALLERY	   (330.0f)
#define HIT_BOTTOM_GALLERY (465.0f)
#define CUT_PICTURE_TOP	   (0.0f)
#define CUT_PICTURE_LEFT   (0.0f)
#define CUT_PICTURE_RIGHT  (561.0f)
#define CUT_PICTURE_BOTTOM (135.0f)

//切り取り&表示 : 背景
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)
#define BACKGROUND_B_GAP (599.0f)

//まとめ表示
#define CUT_CONCLUSION_T (456.0f)
#define CUT_CONCLUSION_L (1.0f)
#define CUT_CONCLUSION_R (658.0f)
#define CUT_CONCLUSION_B (543.0f)
#define POS_CONCLUSION_T (20.0f)
#define POS_CONCLUSION_L (80.0f)
#define POS_CONCLUSION_R (740.0f)
#define POS_CONCLUSION_B (110.0f)

//クレジットボタン
#define CUT_CREDITBUTTON_T (927.0f)
#define CUT_CREDITBUTTON_L (0.0f)
#define CUT_CREDITBUTTON_R (150.0f)
#define CUT_CREDITBUTTON_B (998.0f)
#define POS_CREDITBUTTON_T (480.0f)
#define POS_CREDITBUTTON_L (460.0f)
#define POS_CREDITBUTTON_R (680.0f)
#define POS_CREDITBUTTON_B (580.0f)

//クレジット表示
#define CUT_CREDIT_T (0.0f)
#define CUT_CREDIT_L (0.0f)
#define CUT_CREDIT_R (620.0f)
#define CUT_CREDIT_B (450.0f)
#define POS_CREDIT_T (0.0f)
#define POS_CREDIT_L (0.0f)
#define POS_CREDIT_R (800.0f)
#define POS_CREDIT_B (600.0f)

//クレジットスクロール用
#define RESET_POS_CREDIT (0.0f)
#define CIRCLE (360.0f)
#define CREDIT_MOVE_SPEED (30.0f)

//オブジェクト：モードセレクト
class CObjModeSelect : public CObj
{
public:
	CObjModeSelect() {};
	~CObjModeSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float x, y;
private:
	float m_y1;	//背景の位置Y1
	float m_y2;	//背景の位置Y2

	float C_m_y1; //クレジットの位置Y1
	float C_m_y2; //クレジットの位置Y2
	float m_r1; //クレジットの左側の上下運動用
	float m_r2;	//クレジットの右側の上下運動用

	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす
	bool credit_flag;//クレジット表示用
	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	char buttom_name;//ボタンの名前記憶用、カラー変更に使用

	bool help_flag;//help表示用
};
