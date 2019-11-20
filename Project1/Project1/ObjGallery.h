#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

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
	bool Flag[3];	

};
