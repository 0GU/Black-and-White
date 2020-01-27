#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define WINDOW_SIZE_TOP_LEFT (0.0f)
#define WINDOW_SIZE_X (800.0f)
#define WINDOW_SIZE_Y (600.0f)
#define CLICK_WAIT (300)


//オブジェクト：タイトル
class CObjGalleryadd : public CObj
{
public:
	CObjGalleryadd() {};
	~CObjGalleryadd() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float x, y;
private:
	int m_time;
	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす


};
