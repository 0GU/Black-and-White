#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームセレクト
class CObjGameSelect : public CObj
{
	public:
		CObjGameSelect() {};
		~CObjGameSelect() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
		float x, y;
	private:


};
