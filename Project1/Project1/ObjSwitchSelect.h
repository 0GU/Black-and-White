#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ

//切り替え時ストップ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//表示:ステージ
#define STAGE_SW_SELECT_L (120.0f)
#define STAGE_SW_SELECT_R (670.0f)
#define STAGE_SW_SELECT_R_DRAW (680.0f)
#define STAGE_SW_SELECT_ONE_T (180.0f)
#define STAGE_SW_SELECT_ONE_B (270.0f)
#define STAGE_SW_SELECT_TWO_T (300.0f)
#define STAGE_SW_SELECT_TWO_B (390.0f)
#define STAGE_SW_SELECT_THREE_T (420.0f)
#define STAGE_SW_SELECT_THREE_B (510.0f)

//切り取り:ステージ
#define RESOURCE_STAGE_L (0.0f)
#define RESOURCE_STAGE_R (560.0f)
#define RESOURCE_STAGE1_T (268.0f)
#define RESOURCE_STAGE1_B (359.0f)
#define RESOURCE_STAGE2_T (358.0f)
#define RESOURCE_STAGE2_B (449.0f)
#define RESOURCE_STAGE3_T (448.0f)
#define RESOURCE_STAGE3_B (540.0f)
#define RESOURCE_STAGE4_T (90.0f)
#define RESOURCE_STAGE4_B (181.0f)
#define RESOURCE_STAGE5_T (180.0f)
#define RESOURCE_STAGE5_B (271.0f)
#define RESOURCE_STAGE6_T (270.0f)
#define RESOURCE_STAGE6_B (361.0f)


//表示:クリア,パーフェクト時の星
#define STAGE_SW_STAR_14_T (206.0f)
#define STAGE_SW_STAR_14_B (245.0f)
#define STAGE_SW_STAR_25_T (327.0f)
#define STAGE_SW_STAR_25_B (366.0f)
#define STAGE_SW_STAR_36_T (446.0f)
#define STAGE_SW_STAR_36_B (485.0f)
#define STAGE_SW_STAR_R (334.0f)
#define STAGE_SW_STAR_L (295.0f)

//切り取り:白星
#define RESOURCE_STAR_T (0.0f)
#define RESOURCE_STAR_L (840.0f)
#define RESOURCE_STAR_R (880.0f)
#define RESOURCE_STAR_B (40.0f)
////切り取り:黒星(パーフェクト)
#define RESOURCE_PSTAR_T (0.0f)
#define RESOURCE_PSTAR_L (800.0f)
#define RESOURCE_PSTAR_R (840.0f)
#define RESOURCE_PSTAR_B (40.0f)
//切り取り:戻るボタン
#define RESOURCE_BACKBUTTON_T (0.0f)
#define RESOURCE_BACKBUTTON_L (727.0f)
#define RESOURCE_BACKBUTTON_R (849.0f)
#define RESOURCE_BACKBUTTON_B (102.0f)
//表示:戻るボタン
#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

//切り取り&表示 : 動く背景
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)
#define BACKGROUND_B_GAP (599.0f)

//切り取り:ステージを選択してください
#define CUT_STAGE_T (362.0f)
#define CUT_STAGE_L (2.0f)
#define CUT_STAGE_R (537.0f)
#define CUT_STAGE_B (430.0f)//542x95
//表示:ステージを選択してください
#define POS_STAGE_T (15.0f)
#define POS_STAGE_L (140.0f)
#define POS_STAGE_R (690.0f)
#define POS_STAGE_B (135.0f)

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
	bool Pflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Cflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Rflag;			//STAGE1〜3とSTAGE4〜6の判定を分けるため
	float m_y1;
	float m_y2;

	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす

	float m_scroll;//スクロール仮
	bool scroll_flag;
	float speed;

	int Rright;//スクロール右
	int Rleft;//スクロール左

	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	char buttom_name;//ボタンの名前記憶用、カラー変更に使用
	bool help_flag;//help表示用
	bool help_flag2;//help2ページ目表示用
	bool help_flag3;//help3ページ目表示用
};
