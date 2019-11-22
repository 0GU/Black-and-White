#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

#define RESOURCE_SCENE_TEXT_T (135.0f)
#define RESOURCE_SCENE_TEXT_L (1.0f)
#define RESOURCE_SCENE_TEXT_R (558.0f)
#define RESOURCE_SCENE_TEXT_B (265.0f)
#define RESOURCE_SELECT_L (0.0f)
#define RESOURCE_SELECT_R (600.0f)
#define RESOURCE_SW_SELECT_T (658.0f)
#define RESOURCE_SW_SELECT_B (748.0f)
#define RESOURCE_RP_SELECT_T (747.0f)
#define RESOURCE_RP_SELECT_B (838.0f)
#define RESOURCE_BACK_T (139.0f)
#define RESOURCE_BACK_L (559.0f)
#define RESOURCE_BACK_R (679.0f)
#define RESOURCE_BACK_B (239.0f)

#define SCENE_TEXT_POS_T (20.0f)
#define SCENE_TEXT_POS_L (120.0f)
#define SCENE_TEXT_POS_R (680.0f)
#define SCENE_TEXT_POS_B (155.0f)
#define SELECT_POS_L (100.0f)
#define SELECT_POS_R (700.0f)
#define SW_SELECT_POS_T (200.0f)
#define SW_SELECT_POS_B (290.0f)
#define RP_SELECT_POS_T (400.0f)
#define RP_SELECT_POS_B (485.0f)
#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

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
