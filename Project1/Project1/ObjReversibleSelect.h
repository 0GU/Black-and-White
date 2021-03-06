#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


//マクロ
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//Stage1-----------------------------------------

//表示:RP1
#define HIT_TOP_RP1 (160.0f)
#define HIT_LEFT_RP (120.0f)
#define HIT_RIGHT_RP (680.0f)
#define HIT_BOTTOM_RP1 (250.0f)

//切り取り:RP1
#define CUT_PIC_TOP_RP1 (0.0f)
#define CUT_PIC_LEFT_RP (0.0f)
#define CUT_PIC_RIGHT_RP (561.0f)
#define CUT_PIC_BOTTOM_RP1 (90.0f)


//Stage2---------------------------

//表示:RP2
#define HIT_TOP_RP2 (290.0f)


#define HIT_BOTTOM_RP2 (380.0f)

//切り取り:RP2
#define CUT_PIC_TOP_RP2 (90.0f)


#define CUT_PIC_BOTTOM_RP2 (180.0f)

//Stage3---------------------------

//表示:RP3
#define HIT_TOP_RP3 (420.0f)


#define HIT_BOTTOM_RP3 (510.0f)

//切り取り:RP3
#define CUT_PIC_TOP_RP3 (180.0f)


#define CUT_PIC_BOTTOM_RP3 (271.0f)


//Stage4--------------------------

//表示:RP4
#define HIT_TOP_RP4 (160.0f)
 
#define HIT_BOTTOM_RP4 (250.0f)

//切り取り:RP4
#define CUT_PIC_TOP_RP4 (545.0f)

#define CUT_PIC_BOTTOM_RP4 (635.0f)

//Stage5--------------------------

//表示:RP5
#define HIT_TOP_RP5 (290.0f)

#define HIT_BOTTOM_RP5 (380.0f)

//切り取り:RP5
#define CUT_PIC_TOP_RP5 (635.0f)

#define CUT_PIC_BOTTOM_RP5 (725.0f)

//Stage6--------------------------

//表示:RP6
#define HIT_TOP_RP6 (420.0f)

#define HIT_BOTTOM_RP6 (510.0f)

//切り取り:RP6
#define CUT_PIC_TOP_RP6 (725.0f)

#define CUT_PIC_BOTTOM_RP6 (816.0f)


//BackButton-------------------------------------

//表示:BackPic
#define HIT_TOP_SCENEBACK (35.0f)
#define HIT_LEFT_SCENEBACK (5.0f)
#define HIT_RIGHT_SCENEBACK (125.0f)
#define HIT_BOTTOM_SCENEBACK (135.0f)

//切り取り:BackPic
#define CUT_PIC_TOP_SCENEBACK (0.0f)
#define CUT_PIC_LEFT_SCENEBACK (727.0f)
#define CUT_PIC_RIGHT_SCENEBACK (849.0f)
#define CUT_PIC_BOTTOM_SCENEBACK (102.0f)

//BlackStar1-------------------------------------

//表示:BlackStar1
#define HIT_LEFT_BLACKSTAR (278.0f)
#define HIT_RIGHT_BLACKSTAR (317.0f)

#define HIT_TOP_BLACKSTAR1 (184.0f)
#define HIT_BOTTOM_BLACKSTAR1 (225.0f)
//切り取り:BlackStar
#define CUT_PIC_TOP_BLACKSTAR (0.0f)
#define CUT_PIC_LEFT_BLACKSTAR (840.0f)
#define CUT_PIC_RIGHT_BLACKSTAR (880.0f)
#define CUT_PIC_BOTTOM_BLACKSTAR (40.0f)


//BlackStar2-----------------------

//表示:BlackStar2
#define HIT_TOP_BLACKSTAR2 (314.0f)


#define HIT_BOTTOM_BLACKSTAR2 (353.0f)

//切り取り:BlackStar



//BlackStar3-----------------------

//表示:BlackStar3
#define HIT_TOP_BLACKSTAR3 (445.0f)


#define HIT_BOTTOM_BLACKSTAR3 (483.0f)

//切り取り:BlackStar

//WhiteStar1-----------------------------------------

//表示:WhiteStar1
#define HIT_LEFT_WHITESTAR (278.0f)
#define HIT_RIGHT_WHITESTAR (317.0f)

#define HIT_TOP_WHITESTAR1 (184.0f)
#define HIT_BOTTOM_WHITESTAR1 (225.0f)
//切り取り:WhiteStar
#define CUT_PIC_TOP_WHITESTAR (0.0f)
#define CUT_PIC_LEFT_WHITESTAR (800.0f)
#define CUT_PIC_RIGHT_WHITESTAR (840.0f)
#define CUT_PIC_BOTTOM_WHITESTAR (40.0f)

//WhiteStar2------------------------

//表示:WhiteStar2
#define HIT_TOP_WHITESTAR2 (314.0f)
#define HIT_BOTTOM_WHITESTAR2 (353.0f)

//切り取り:WhiteStar

//White3----------------------------

//表示:WhiteStar3
#define HIT_TOP_WHITESTAR3 (445.0f)
#define HIT_BOTTOM_WHITESTAR3 (483.0f)

//切り取り:WhiteStar

//切り取り&表示 : 背景
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)

//切り取り&表示 : 矢印
#define RIGHT_ARROW_T (140.0f)
#define RIGHT_ARROW_L (679.0f)
#define RIGHT_ARROW_R (759.0f)
#define RIGHT_ARROW_B (280.0f)

#define LEFT_ARROW_R (838.0f)
#define LEFT_ARROW_L (758.0f)


//オブジェクト：ステージセレクト
class CObjReversibleSelect : public CObj
{
public:
	CObjReversibleSelect() {};
	~CObjReversibleSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	float x, y;
private:
	bool Pflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3	3:STAGE4	4:STAGE5	5:STAGE6	
	bool Cflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3	3:STAGE4	4:STAGE5	5:STAGE6
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
