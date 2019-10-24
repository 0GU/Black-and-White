#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：モードセレクト
class CObjModeSelect : public CObj
{
public:
	CObjModeSelect() {};
	~CObjModeSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:


};
