#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：マウス
class CObjMouse :public CObj
{
public:
	CObjMouse(bool back);
	~CObjMouse() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロ

private:
	float m_mou_x;//マウスの位置ｘ
	float m_mou_y;//マウスの位置Y
	bool m_mou_l;//マウス左ボタン

	int m_time;
	int m_ani_flame;
	//bool m_ani_flag;
	bool mouse_flag;
	bool back_col;
};

//ボタン色変更用関数
void ButtomCol(bool click[2], bool* color);
