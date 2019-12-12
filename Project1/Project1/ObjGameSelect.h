#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

#define RESOURCE_SCENE_TEXT_T (138.0f)
#define RESOURCE_SCENE_TEXT_L (3.0f)
#define RESOURCE_SCENE_TEXT_R (554.0f)
#define RESOURCE_SCENE_TEXT_B (262.0f)
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
#define SCENE_TEXT_POS_L (130.0f)
#define SCENE_TEXT_POS_R (690.0f)
#define SCENE_TEXT_POS_B (155.0f)
#define SELECT_POS_L (99.0f)
#define SELECT_POS_R (690.0f)
#define SW_SELECT_POS_T (197.0f)
#define SW_SELECT_POS_B (284.0f)
#define RP_SELECT_POS_T (393.0f)
#define RP_SELECT_POS_B (476.0f)
#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

//切り取り&表示 : 背景
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)

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
		float m_y1;
		float m_y2;

};
