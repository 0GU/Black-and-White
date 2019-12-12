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
	int i, j;

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
};