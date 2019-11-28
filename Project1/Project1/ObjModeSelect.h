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
};
