#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：マウス
class CObjMouse :public CObj
{
public:
	CObjMouse() {};
	~CObjMouse() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロ
private:
	float m_mou_x;//マウスの位置ｘ
	float m_mou_y;//マウスの位置Y
	bool m_mou_l;//マウス左ボタン
};