#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�}�N��
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//Stage1-----------------------------------------

//�\��:RP1
#define HIT_TOP_RP1 (160.0f)
#define HIT_LEFT_RP (120.0f)
#define HIT_RIGHT_RP (680.0f)
#define HIT_BOTTOM_RP1 (250.0f)

//�؂���:RP1
#define CUT_PIC_TOP_RP1 (0.0f)
#define CUT_PIC_LEFT_RP (0.0f)
#define CUT_PIC_RIGHT_RP (561.0f)
#define CUT_PIC_BOTTOM_RP1 (90.0f)


//Stage2---------------------------

//�\��:RP2
#define HIT_TOP_RP2 (290.0f)


#define HIT_BOTTOM_RP2 (380.0f)

//�؂���:RP2
#define CUT_PIC_TOP_RP2 (90.0f)


#define CUT_PIC_BOTTOM_RP2 (180.0f)

//Stage3---------------------------

//�\��:RP3
#define HIT_TOP_RP3 (420.0f)


#define HIT_BOTTOM_RP3 (510.0f)

//�؂���:RP3
#define CUT_PIC_TOP_RP3 (180.0f)


#define CUT_PIC_BOTTOM_RP3 (271.0f)

//BackButton-------------------------------------

//�\��:BackPic
#define HIT_TOP_SCENEBACK (35.0f)
#define HIT_LEFT_SCENEBACK (5.0f)
#define HIT_RIGHT_SCENEBACK (125.0f)
#define HIT_BOTTOM_SCENEBACK (135.0f)

//�؂���:BackPic
#define CUT_PIC_TOP_SCENEBACK (0.0f)
#define CUT_PIC_LEFT_SCENEBACK (727.0f)
#define CUT_PIC_RIGHT_SCENEBACK (849.0f)
#define CUT_PIC_BOTTOM_SCENEBACK (102.0f)

//BlackStar1-------------------------------------

//�\��:BlackStar1
#define HIT_LEFT_BLACKSTAR (288.0f)
#define HIT_RIGHT_BLACKSTAR (327.0f)

#define HIT_TOP_BLACKSTAR1 (184.0f)
#define HIT_BOTTOM_BLACKSTAR1 (225.0f)
//�؂���:BlackStar
#define CUT_PIC_TOP_BLACKSTAR (0.0f)
#define CUT_PIC_LEFT_BLACKSTAR (840.0f)
#define CUT_PIC_RIGHT_BLACKSTAR (880.0f)
#define CUT_PIC_BOTTOM_BLACKSTAR (40.0f)


//BlackStar2-----------------------

//�\��:BlackStar2
#define HIT_TOP_BLACKSTAR2 (314.0f)


#define HIT_BOTTOM_BLACKSTAR2 (353.0f)

//�؂���:BlackStar



//BlackStar3-----------------------

//�\��:BlackStar3
#define HIT_TOP_BLACKSTAR3 (445.0f)


#define HIT_BOTTOM_BLACKSTAR3 (483.0f)

//�؂���:BlackStar

//WhiteStar1-----------------------------------------

//�\��:WhiteStar1
#define HIT_LEFT_WHITESTAR (288.0f)
#define HIT_RIGHT_WHITESTAR (327.0f)

#define HIT_TOP_WHITESTAR1 (184.0f)
#define HIT_BOTTOM_WHITESTAR1 (225.0f)
//�؂���:WhiteStar
#define CUT_PIC_TOP_WHITESTAR (0.0f)
#define CUT_PIC_LEFT_WHITESTAR (800.0f)
#define CUT_PIC_RIGHT_WHITESTAR (840.0f)
#define CUT_PIC_BOTTOM_WHITESTAR (40.0f)

//WhiteStar2------------------------

//�\��:WhiteStar2
#define HIT_TOP_WHITESTAR2 (314.0f)
#define HIT_BOTTOM_WHITESTAR2 (353.0f)

//�؂���:WhiteStar

//White3----------------------------

//�\��:WhiteStar3
#define HIT_TOP_WHITESTAR3 (445.0f)
#define HIT_BOTTOM_WHITESTAR3 (483.0f)

//�؂���:WhiteStar

//�؂���&�\�� : �w�i
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)


//�I�u�W�F�N�g�F�X�e�[�W�Z���N�g
class CObjReversibleSelect : public CObj
{
public:
	CObjReversibleSelect() {};
	~CObjReversibleSelect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	bool Pflag[3];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Cflag[3];		//0:STAGE1  1:STAGE2  2:STAGE3
	float m_y1;
	float m_y2;

};
