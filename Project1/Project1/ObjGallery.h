#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)


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

};
