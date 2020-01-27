#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCROLL_SPEED (1.0f)
#define SCROLL_DISTANCE (800.0f)

#define HIT_BACK_TOP (34.0f)
#define HIT_BACK_LEFT (5.0f)
#define HIT_BACK_RIGHT (122.0f)
#define HIT_BACK_BOTTOM (132.0f)

#define HIT_RIGHTARROW_TOP (235.0f)
#define HIT_RIGHTARROW_LEFT (691.0f)
#define HIT_RIGHTARROW_RIGHT (764.0f)
#define HIT_RIGHTARROW_BOTTOM (353.0f)

#define HIT_LEFTARROW_TOP (240.0f)
#define HIT_LEFTARROW_LEFT (26.0f)
#define HIT_LEFTARROW_RIGHT (99.0f)
#define HIT_LEFTARROW_BOTTOM (357.0f)

#define GRAPHIC_TOP (50.0f)
#define GRAPHIC_LEFT (145.0f)
#define GRAPHIC_RIGHT (657.0f)
#define GRAPHIC_BOTTOM (560.0f)

#define CUT_GRAPHIC_TOP (0.0f)
#define CUT_GRAPHIC_LEFT (0.0f)
#define CUT_GRAPHIC_RIGHT (512.0f)
#define CUT_GRAPHIC_BOTTOM (512.0f)

//画像切り取り用
#define RESOURCE_GRAPHIC_RIGHT (800.0f)
#define RESOURCE_GRAPHIC_BOTTOM (600.0f)
#define RESOURCE_GRAPHIC_RIGHT2 (1024.0f)
#define RESOURCE_GRAPHIC_BOTTOM2 (1024.0f)



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

#define EX_GRAPHIC_TOP (0.0f)
#define EX_GRAPHIC_LEFT (100.0f)
#define EX_GRAPHIC_RIGHT (700.0f)
#define EX_GRAPHIC_BOTTOM (600.0f)

//オブジェクト：ギャラリー
class CObjGallery : public CObj
{
public:
	CObjGallery() {};
	~CObjGallery() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	bool FlagCheck(bool flag[],int num);

private:
	float x, y;
	int Gright;
	int Gleft;
	bool SFlag[3]; //Switchのフラグ
	bool RFlag[6]; //Reversibleのフラグ
	bool GFlag[2]; //Galleryのフラグ

	float m_scroll;//スクロール仮
	bool scroll_flag;
	float speed;

	bool time_flag;
	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす
	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	char buttom_name;//ボタンの名前記憶用、カラー変更に使用


};
