#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

#define STAGE_SW_SELECT_L (120.0f)
#define STAGE_SW_SELECT_R (670.0f)
#define STAGE_SW_SELECT_R_DRAW (680.0f)
#define STAGE_SW_SELECT_ONE_T (180.0f)
#define STAGE_SW_SELECT_ONE_B (270.0f)
#define STAGE_SW_SELECT_TWO_T (300.0f)
#define STAGE_SW_SELECT_TWO_B (390.0f)
#define STAGE_SW_SELECT_THREE_T (420.0f)
#define STAGE_SW_SELECT_THREE_B (510.0f)

#define RESOURCE_STAGE_L (0.0f)
#define RESOURCE_STAGE_R (561.0f)
#define RESOURCE_STAGE1_T (268.0f)
#define RESOURCE_STAGE1_B (359.0f)
#define RESOURCE_STAGE2_T (358.0f)
#define RESOURCE_STAGE2_B (449.0f)
#define RESOURCE_STAGE3_T (448.0f)
#define RESOURCE_STAGE3_B (540.0f)

#define STAGE_SW_STAR_ONE_T (206.0f)
#define STAGE_SW_STAR_ONE_B (245.0f)
#define STAGE_SW_STAR_TWO_T (324.0f)
#define STAGE_SW_STAR_TWO_B (363.0f)
#define STAGE_SW_STAR_THREE_T (442.0f)
#define STAGE_SW_STAR_THREE_B (481.0f)
#define STAGE_SW_STAR_R (320.0f)
#define STAGE_SW_STAR_L (281.0f)

#define RESOURCE_STAR_T (1.5f)
#define RESOURCE_STAR_L (562.0f)
#define RESOURCE_STAR_R (600.0f)
#define RESOURCE_STAR_B (40.0f)
#define RESOURCE_PSTAR_T (43.0f)
#define RESOURCE_PSTAR_L (562.0f)
#define RESOURCE_PSTAR_R (600.0f)
#define RESOURCE_PSTAR_B (82.0f)

#define RESOURCE_BACKBUTTON_T (139.0f)
#define RESOURCE_BACKBUTTON_L (559.0f)
#define RESOURCE_BACKBUTTON_R (679.0f)
#define RESOURCE_BACKBUTTON_B (239.0f)

#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

//オブジェクト：ステージセレクト
class CObjSwitchSelect : public CObj
{
public:
	CObjSwitchSelect() {};
	~CObjSwitchSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float x, y;
private:
	bool Pflag[3];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Cflag[3];		//0:STAGE1  1:STAGE2  2:STAGE3
};
