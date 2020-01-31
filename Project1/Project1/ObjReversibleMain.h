#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//マクロ
//初期化
#define INITIALIZE (0)
//パネルの当たり判定
#define HIT_PANEL_TOP (60.0f)
#define HIT_PANEL_LEFT (160.0f)
#define HIT_PANEL_RIGHT (640.0f)
#define HIT_PANEL_BOTTOM (540.0f)
//パネル1つ当たりの大きさ
#define PANEL_SIZE_X (96.0f)
#define PANEL_SIZE_Y (96.0f)
#define ANIMATIONPANEL_SIZE_X (96)
#define ANIMATIONPANEL_SIZE_Y (120)
#define POSITION_WHITE (120.0)
//画像と判定枠の位置ずれ補正
#define PANEL_POSITION_CORRECTION (12.0f)
#define POSITION_CORRECTION_WIDTH (10.0f)
#define POSITION_CORRECTION_HEIGHT (5.0f)
//パネルの切り取り位置(始点)
#define PANEL_TOP (0.0f)
#define PANEL_LEFT (0.0f)
//ステージ配列の大きさ
#define ARRAY_SIZE_TOP (0)
#define ARRAY_SIZE_LEFT (0)
#define ARRAY_SIZE_RIGHT (4)
#define ARRAY_SIZE_BOTTOM (4)
//反転処理用
#define WHITE_PANEL (0)
#define BLACK_PANEL (1)
#define WHITE_PANEL_REVERSAL (2)
#define BLACK_PANEL_REVERSAL (3)
//クリア時のステージセレクト用判定枠
#define STAGE_SELECT_TOP (370.0f)
#define STAGE_SELECT_LEFT (130.0f)
#define STAGE_SELECT_RIGHT (690.0f)
#define STAGE_SELECT_BOTTOM (490.0f)
//YESボタン用判定枠
#define YES_BUTTON_TOP (370.0f)
#define YES_BUTTON_LEFT (130.0f)
#define YES_BUTTON_RIGHT (370.0f)
#define YES_BUTTON_BOTTOM (490.0f)
//NOボタン用判定枠
#define NO_BUTTON_TOP (370.0f)
#define NO_BUTTON_LEFT (410.0f)
#define NO_BUTTON_RIGHT (650.0f)
#define NO_BUTTON_BOTTOM (490.0f)
//リセットボタン用判定枠
#define RESET_BUTTON_TOP (430.0f)
#define RESET_BUTTON_LEFT (650.0f)
#define RESET_BUTTON_RIGHT (770.0f)
#define RESET_BUTTON_BOTTOM (530.0f)
//ヒントボタン用判定枠
#define HINT_BUTTON_TOP (250.0f)
#define HINT_BUTTON_LEFT (650.0f)
#define HINT_BUTTON_RIGHT (770.0f)
#define HINT_BUTTON_BOTTOM (350.0f)
//ステージセレクト用判定枠
#define SELECT_BUTTON_TOP (60.0f)
#define SELECT_BUTTON_LEFT (30.0f)
#define SELECT_BUTTON_RIGHT (130.0f)
#define SELECT_BUTTON_BOTTOM (160.0f)
//背景画像表示用
#define SRC_BACKGROUND_TOP  (0.0f)
#define SRC_BACKGROUND_LEFT  (0.0f)
#define SRC_BACKGROUND_RIGHT (800.0f)
#define SRC_BACKGROUND_BOTTOM  (600.0f)
#define DST_BACKGROUND_TOP  (0.0f)
#define DST_BACKGROUND_LEFT  (0.0f)
#define DST_BACKGROUND_RIGHT  (800.0f)
#define DST_BACKGROUND_BOTTOM  (600.0f)
//ヒント画像表示用
#define SRC_HINT_TOP  (0.0f)
#define SRC_HINT_LEFT  (0.0f)
#define SRC_HINT_RIGHT (120.0f)
#define SRC_HINT_BOTTOM  (100.0f)
//リセット画像表示用
#define SRC_RESET_TOP  (0.0f)
#define SRC_RESET_LEFT  (0.0f)
#define SRC_RESET_RIGHT (120.0f)
#define SRC_RESET_BOTTOM  (100.0f)
//ステージセレクト画像表示用
#define SRC_SELECT_TOP  (820.0f)
#define SRC_SELECT_LEFT  (478.0f)
#define SRC_SELECT_RIGHT (598.0f)
#define SRC_SELECT_BOTTOM  (920.0f)
//Perfect画像表示用
#define SRC_PERFECT_TOP  (370.0f)
#define SRC_PERFECT_LEFT  (0.0f)
#define SRC_PERFECT_RIGHT (560.0f)
#define SRC_PERFECT_BOTTOM  (491.0f)
#define DST_PERFECT_TOP  (150.0f)
#define DST_PERFECT_LEFT  (100.0f)
#define DST_PERFECT_RIGHT  (690.0f)
#define DST_PERFECT_BOTTOM  (300.0f)
//クリア時のステージセレクト画像表示用
#define SRC_STAGE_SELECT_TOP (490.0f)
#define SRC_STAGE_SELECT_LEFT (0.0f)
#define SRC_STAGE_SELECT_RIGHT (560.0f)
#define SRC_STAGE_SELECT_BOTTOM (610.0f)
//クリア画像表示用
#define SRC_CLERE_TOP  (249.0f)
#define SRC_CLERE_LEFT  (0.0f)
#define SRC_CLERE_RIGHT (560.0f)
#define SRC_CLERE_BOTTOM  (372.0f)
#define DST_CLERE_TOP  (150.0f)
#define DST_CLERE_LEFT  (130.0f)
#define DST_CLERE_RIGHT  (690.0f)
#define DST_CLERE_BOTTOM  (270.0f)
//ゲームオーバー画像表示用
#define SRC_GAMEOVER_TOP  (0.0f)
#define SRC_GAMEOVER_LEFT  (0.0f)
#define SRC_GAMEOVER_RIGHT (580.0f)
#define SRC_GAMEOVER_BOTTOM  (250.0f)
#define DST_GAMEOVER_TOP  (70.0f)
#define DST_GAMEOVER_LEFT  (110.0f)
#define DST_GAMEOVER_RIGHT  (690.0f)
#define DST_GAMEOVER_BOTTOM  (320.0f)
//YES画像表示用
#define SRC_YES_TOP  (820.0f)
#define SRC_YES_LEFT  (0.0f)
#define SRC_YES_RIGHT (240.0f)
#define SRC_YES_BOTTOM  (940.0f)
//NO画像表示用
#define SRC_NO_TOP  (820.0f)
#define SRC_NO_LEFT  (239.0f)
#define SRC_NO_RIGHT (479.0f)
#define SRC_NO_BOTTOM  (940.0f)
//ステージセレクトへ戻る画像表示用
#define SRC_RETURNSELECT_TOP  (0.0f)
#define SRC_RETURNSELECT_LEFT  (0.0f)
#define SRC_RETURNSELECT_RIGHT (520.0f)
#define SRC_RETURNSELECT_BOTTOM  (90.0f)
#define DST_RETURNSELECT_TOP  (150.0f)
#define DST_RETURNSELECT_LEFT  (130.0f)
#define DST_RETURNSELECT_RIGHT  (650.0f)
#define DST_RETURNSELECT_BOTTOM  (270.0f)


//STAGE(左下)の画像
#define SRC_STAGE_TOP (820.0f)
#define SRC_STAGE_LEFT (180.0f)
#define SRC_STAGE_RIGHT (280.0f)
#define SRC_STAGE_BOTTOM (865.0f)
#define DST_STAGE_TOP (450.0f)
#define DST_STAGE_LEFT (10.0f)
#define DST_STAGE_RIGHT (110.0f)
#define DST_STAGE_BOTTOM (495.0f)


//ステージナンバー(左下)の画像切り取り:1～4 
#define SRC_STAGECOUNT_TOP_1234 (0.0f)
#define SRC_STAGECOUNT_BOTTOM_1234 (119.0f)

//ステージナンバーの画像切り取り:5,6
#define SRC_STAGECOUNT_TOP_56 (120.0f)
#define SRC_STAGECOUNT_BOTTOM_56 (240.0f)

//ステージ1
#define SRC_STAGECOUNT_LEFT_1 (1.0f)
#define SRC_STAGECOUNT_RIGHT_1 (119.0f)
//ステージ2
#define SRC_STAGECOUNT_LEFT_2 (120.0f)
#define SRC_STAGECOUNT_RIGHT_2 (120.0f)
//ステージ3
#define SRC_STAGECOUNT_LEFT_3 (120.0f)
#define SRC_STAGECOUNT_RIGHT_3 (120.0f)
//ステージ4
#define SRC_STAGECOUNT_LEFT_4 (120.0f)
#define SRC_STAGECOUNT_RIGHT_4 (120.0f)
//ステージ5
#define SRC_STAGECOUNT_LEFT_5 (0.0f)
#define SRC_STAGECOUNT_RIGHT_5 (120.0f)
//ステージ6
#define SRC_STAGECOUNT_LEFT_6 (120.0f)
#define SRC_STAGECOUNT_RIGHT_6 (120.0f)

//ステージナンバー表示
#define DST_STAGECOUNT_TOP (450.0f)
#define DST_STAGECOUNT_LEFT (105.0f)
#define DST_STAGECOUNT_RIGHT (155.0f)
#define DST_STAGECOUNT_BOTTOM (500.0f)


//Count(右上)画像
#define SRC_COUNT_TOP (820.0f)
#define SRC_COUNT_LEFT (20.0f)
#define SRC_COUNT_RIGHT (130.0f)
#define SRC_COUNT_BOTTOM (860.0f)
#define DST_COUNT_TOP (40.0f)
#define DST_COUNT_LEFT (660.0f)
#define DST_COUNT_RIGHT (770.0f)
#define DST_COUNT_BOTTOM (80.0f)

//Helpボタン
#define CUT_HELPBUTTON_T2 (0.0f)
#define CUT_HELPBUTTON_L (924.0f)
#define CUT_HELPBUTTON_R (1024.0f)
#define CUT_HELPBUTTON_B2 (100.0f)
#define POS_HELPBUTTON_T_RB (120.0f)
#define POS_HELPBUTTON_L_RB (671.0f)
#define POS_HELPBUTTON_R_RB (771.0f)
#define POS_HELPBUTTON_B_RB (220.0f)

//ヘルプ表示
#define CUT_HELP_T (0.0f)
#define CUT_HELP_L (0.0f)
#define CUT_HELP_R (1280.0f)
#define CUT_HELP_B (720.0f)
#define POS_HELP_T (0.0f)
#define POS_HELP_L (0.0f)
#define POS_HELP_R (800.0f)
#define POS_HELP_B (600.0f)


//オブジェクト：Reversibleメイン
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain(int stage);
	~CObjReversibleMain() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
	void Reverse();
	float x, y;


private:
	int stage[5][5];
	int stage_reset[5][5];
	//count管理用
	int count[3];  //[0]…最短手数判定用 [1]…手数表示用 [2]…手数リセット用
	//ステージ読み込み用
	int StageSlect;
	//アニメーション変更用
	int m_ani_flame;
	int change_panel[5][5];
	bool m_ani_flag;
	bool time_flag;
	int m_time;

	int sx, sy;
	int lx, ly;//反転処理用変数
	int i, j;


	//クリック判定用
	bool c_flag[2];	//クリックフラグ	[0]=押している [1]=押していない

	//マウスエフェクト用
	bool back;		//背景色判別用		true=黒 , false=白
	bool mou_call;	//マウス呼び出し用、1回のみ動かす

	//フラグ管理用
	bool flag[8];	//[0]…hintフラグ　[1]…Clearフラグ　[2]…GameOverフラグ [3]…Yes・Noフラグ 
					//[4]…Perfectフラグ [5]…Perfect時の回転フラグ [6][7]…Gyallery用フラグ


	float colorchange;
	bool colorflag;

	bool Debugflag;

	bool col_flag[2]; //カラーフラグ　[0]=明るく　[1]=暗く
	char buttom_name;//ボタンの名前記憶用、カラー変更に使用

	bool help_flag;//help表示用
	bool help_flag2;//help2ページ目表示用
};