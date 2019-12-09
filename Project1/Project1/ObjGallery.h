#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCROLL_SPEED (1.0f)
#define SCROLL_DISTANCE (800.0f)

#define HIT_BACK_TOP (35.0f)
#define HIT_BACK_LEFT (5.0f)
#define HIT_BACK_RIGHT (125.0f)
#define HIT_BACK_BOTTOM (135.0f)

#define HIT_RIGHTARROW_TOP (240.0f)
#define HIT_RIGHTARROW_LEFT (700.0f)
#define HIT_RIGHTARROW_RIGHT (775.0f)
#define HIT_RIGHTARROW_BOTTOM (360.0f)

#define HIT_LEFTARROW_TOP (245.0f)
#define HIT_LEFTARROW_LEFT (26.0f)
#define HIT_LEFTARROW_RIGHT (101.0f)
#define HIT_LEFTARROW_BOTTOM (365.0f)

#define GRAPHIC_TOP (50.0f)
#define GRAPHIC_LEFT (145.0f)
#define GRAPHIC_RIGHT (657.0f)
#define GRAPHIC_BOTTOM (560.0f)

#define CUT_GRAPHIC_TOP (0.0f)
#define CUT_GRAPHIC_LEFT (0.0f)
#define CUT_GRAPHIC_RIGHT (512.0f)
#define CUT_GRAPHIC_BOTTOM (512.0f)

#define CUT_BACK_TOP (139.0f)
#define CUT_BACK_LEFT (559.0f)
#define CUT_BACK_RIGHT (679.0f)
#define CUT_BACK_BOTTOM (239.0f)

#define CUT_RIGHTARROW_TOP (0.0f)
#define CUT_RIGHTARROW_LEFT (559.0f)
#define CUT_RIGHTARROW_RIGHT (639.0f)
#define CUT_RIGHTARROW_BOTTOM (140.0f)

#define CUT_LEFTARROW_TOP (0.0f)
#define CUT_LEFTARROW_LEFT (638.0f)
#define CUT_LEFTARROW_RIGHT (718.0f)
#define CUT_LEFTARROW_BOTTOM (140.0f)


//オブジェクト：ギャラリー
class CObjGallery : public CObj
{
public:
	CObjGallery() {};
	~CObjGallery() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:
	float x, y;
	int Gright;
	int Gleft;
	bool SFlag[3]; //Switchのフラグ
	bool RFlag[3]; //Reversibleのフラグ

	float m_scroll;//スクロール仮
	bool scroll_flag;
	float speed;

	bool time_flag;
	int m_time;
	int m_ani_flame;
	bool m_ani_flag;
	bool mouse_flag;
};
