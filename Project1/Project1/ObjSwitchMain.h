#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ

/*
resource
				//変化中黒パネル
				src.m_top = 96.0f;
				src.m_left = 0.0f + (m_ani_flame * 96.0f);
	bool flag[7];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [6]…Perfectフラグ

0 hint
1 clear
2 gameover
3 back select
4 perfect
6

*/

#define M_TIME_MAX (3)
#define M_ANI_FRAME_MAX (3)
#define COUNT (12)
#define WHITE_PANEL_ID (0)
#define BLACK_PANEL_ID (1)
#define LEF_RIG_SWIT_ID (2)
#define UP_DOWN_SWIT_ID (3)
#define CH_WHITE_PANEL_ID (9)
#define CH_BLACK_PANEL_ID (10)

#define HINT_FLAG (0)
#define CLEAR_FLAG (1)
#define GAMEOVER_FLAG (2)
#define BACK_SELECT_FLAG (3)
#define PERFECT_FLAG (4)
#define PERFECT_CNT_ARRAY_NUM (0)
#define REMAINING_CNT_ARRAY_NUM (1)
#define INITIAL_CNT_ARRAY_NUM (2)


#define CUT_BACKGROUND_T (0.0f)
#define CUT_BACKGROUND_L (0.0f)
#define CUT_BACKGROUND_R (800.0f)
#define CUT_BACKGROUND_B (600.0f)
#define BUTTON_SIZE_X (120.0f)
#define BUTTON_SIZE_Y (100.0f)
#define CUT_BL_WH_PANEL_T (0.0f)
#define CUT_BL_WH_PANEL_L (0.0f)
#define CUT_CHANGE_PANEL_T (96.0f)
#define CUT_HIN_RESE_BUTTON_T (0.0f)
#define CUT_HIN_RESE_BUTTON_L (0.0f)
#define CUT_SELE_BUTTON_T (820.0f)
#define CUT_SELE_BUTTON_L (478.0f)
#define CUT_PERFECT_T (370.0f)
#define CUT_PERFECT_L (0.0f)
#define CUT_PERFECT_R (560.0f)
#define CUT_PERFECT_B (491.0f)
#define CUT_GAMECLEAR_T (249.0f)
#define CUT_GAMECLEAR_L (0.0f)
#define CUT_GAMECLEAR_R (560.0f)
#define CUT_GAMECLEAR_B (372.0f)
#define CUT_CLEARBACK_T (490.0f)
#define CUT_CLEARBACK_L (0.0f)
#define CUT_CLEARBACK_R (560.0f)
#define CUT_CLEARBACK_B (610.0f)
#define CUT_GAMEOVER_T (0.0f)
#define CUT_GAMEOVER_L (0.0f)
#define CUT_GAMEOVER_R (580.0f)
#define CUT_GAMEOVER_B (250.0f)
#define CUT_YESNO_BUTTON_T (820.0f)
#define CUT_YESNO_BUTTON_B (940.0f)
#define CUT_YES_BUTTON_L (0.0f)
#define CUT_YES_BUTTON_R (240.0f)
#define CUT_NO_BUTTON_L (239.0f)
#define CUT_NO_BUTTON_R (479.0f)
#define CUT_BACKSELECT_T (0.0f)
#define CUT_BACKSELECT_L (0.0f)
#define CUT_BACKSELECT_R (520.0f)
#define CUT_BACKSELECT_B (91.0f)


#define WINDOW_SIZE_X (800.0f)
#define WINDOW_SIZE_Y (600.0f)

#define PUZZLE_POS_T (60)
#define PUZZLE_POS_L (160)
#define PUZZLE_SIZE  (480)

#define NOW_STAGE_POS_X (30)
#define NOW_STAGE_POS_Y (470)
#define NOW_STAGE_SIZE (36)
#define HIN_TEXT_POS_X_1 (20)
#define HIN_TEXT_POS_Y_1 (260)
#define HIN_TEXT_POS_X_2 (40)
#define HIN_TEXT_POS_Y_2 (320)
#define HIN_TEXT_SIZE (32)
#define CNT_TEXT_POS_X (675)
#define CNT_TEXT_POS_Y (45)
#define CNT_NUM_FEW_POS_X (710)
#define CNT_NUM_MANY_POS_X (700)
#define CNT_NUM_POS_Y (80)
#define CNT_SIZE (32)

#define CHANGE_ANI_R_T (90.0f)
#define CHANGE_ANI_R_L (180.0f)
#define CHANGE_ANI_R_R (0.0f)
#define CHANGE_ANI_R_B (270.0f)
#define PANEL_SIZE (96)
#define HIN_RESE_BUTTON_POS_L (660.0f)
#define HINT_BUTTON_POS_T (250.0f)
#define RESET_BUTTON_POS_T (440.0f)
#define STAGESELE_BUTTON_POS_T (60.0f)
#define STAGESELE_BUTTON_POS_L (20.0f)
#define PERFECT_TEXT_POS_T (150.0f)
#define PERFECT_TEXT_POS_L (100.0f)
#define PERFECT_TEXT_POS_R (690.0f)
#define PERFECT_TEXT_POS_B (300.0f)
#define GAMECLEAR_TEXT_POS_T (150.0f)
#define GAMECLEAR_TEXT_POS_L (130.0f)
#define GAMECLEAR_TEXT_POS_R (690.0f)
#define GAMECLEAR_TEXT_POS_B (270.0f)
#define CLEARBACK_POS_T (370.0f)
#define CLEARBACK_POS_L (130.0f)
#define CLEARBACK_POS_R (690.0f)
#define CLEARBACK_POS_B (490.0f)
#define GAMEOVER_TEXT_POS_T (70.0f)
#define GAMEOVER_TEXT_POS_L (110.0f)
#define GAMEOVER_TEXT_POS_R (690.0f)
#define GAMEOVER_TEXT_POS_B (320.0f)
#define YESNO_BUTTON_POS_T (370.0f)
#define YESNO_BUTTON_POS_B (490.0f)
#define YES_BUTTON_POS_L (140.0f)
#define YES_BUTTON_POS_R (380.0f)
#define NO_BUTTON_POS_L (420.0f)
#define NO_BUTTON_POS_R (660.0f)
#define BACKSELE_TEXT_POS_T (150.0f)
#define BACKSELE_TEXT_POS_L (140.0f)
#define BACKSELE_TEXT_POS_R (660.0f)
#define BACKSELE_TEXT_POS_B (270.0f)

#define CUT_COUNT_T (820.0f)
#define CUT_COUNT_L (20.0f)
#define CUT_COUNT_R (130.0f)
#define CUT_COUNT_B (860.0f)
#define POS_COUNT_T (40.0f)
#define POS_COUNT_L (660.0f)
#define POS_COUNT_R (770.0f)
#define POS_COUNT_B (80.0f)

//オブジェクト：Reversibleメイン
class CObjSwitchMain : public CObj
{
public:
	CObjSwitchMain(int stage);
	~CObjSwitchMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	float x, y;
	int i, j;
private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	int count[3];  //[0]…PerfectClearcount [1]…残りcount [2]…start時のcount
	int StageSlect;

	int sx, sy;		//マウスを押した位置を保存
	

	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	float r;		//アニメーションの角度変更用

	bool flag[8];  //[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [3]stageselectに戻るフラグ [4]…Perfectフラグ

	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす

//	bool Debugflag;

	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	char buttom_name;//ボタンの名前記憶用、カラー変更に使用
	bool help_flag;//help表示用
	bool help_flag2;//help2ページ目表示用
};