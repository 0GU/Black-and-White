#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SELECT_WAIT		   (100)
#define HIT_LEFT		   (118.0f)
#define HIT_RIGHT		   (670.0f)
#define HIT_TOP_SELECT	   (128.0f)
#define HIT_BOTTOM_SELECT  (260.0f)
#define HIT_TOP_GALLERY	   (323.0f)
#define HIT_BOTTOM_GALLERY (455.0f)
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
	float m_x1;	//背景の位置X1
	float m_x2;	//背景の位置X2
	float m_y1;	//背景の位置Y1
	float m_y2;	//背景の位置Y2

	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす
};
