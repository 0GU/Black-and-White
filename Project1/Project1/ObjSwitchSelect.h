#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��

//�؂�ւ����X�g�b�v
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)

//�\��:�X�e�[�W
#define STAGE_SW_SELECT_L (120.0f)
#define STAGE_SW_SELECT_R (670.0f)
#define STAGE_SW_SELECT_R_DRAW (680.0f)
#define STAGE_SW_SELECT_ONE_T (180.0f)
#define STAGE_SW_SELECT_ONE_B (270.0f)
#define STAGE_SW_SELECT_TWO_T (300.0f)
#define STAGE_SW_SELECT_TWO_B (390.0f)
#define STAGE_SW_SELECT_THREE_T (420.0f)
#define STAGE_SW_SELECT_THREE_B (510.0f)

//�؂���:�X�e�[�W
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


//�\��:�N���A,�p�[�t�F�N�g���̐�
#define STAGE_SW_STAR_14_T (206.0f)
#define STAGE_SW_STAR_14_B (245.0f)
#define STAGE_SW_STAR_25_T (327.0f)
#define STAGE_SW_STAR_25_B (366.0f)
#define STAGE_SW_STAR_36_T (446.0f)
#define STAGE_SW_STAR_36_B (485.0f)
#define STAGE_SW_STAR_R (329.0f)
#define STAGE_SW_STAR_L (290.0f)

//�؂���:����
#define RESOURCE_STAR_T (0.0f)
#define RESOURCE_STAR_L (840.0f)
#define RESOURCE_STAR_R (880.0f)
#define RESOURCE_STAR_B (40.0f)
////�؂���:����(�p�[�t�F�N�g)
#define RESOURCE_PSTAR_T (0.0f)
#define RESOURCE_PSTAR_L (800.0f)
#define RESOURCE_PSTAR_R (840.0f)
#define RESOURCE_PSTAR_B (40.0f)
//�؂���:�߂�{�^��
#define RESOURCE_BACKBUTTON_T (0.0f)
#define RESOURCE_BACKBUTTON_L (727.0f)
#define RESOURCE_BACKBUTTON_R (849.0f)
#define RESOURCE_BACKBUTTON_B (102.0f)
//�\��:�߂�{�^��
#define BACKBUTTON_POS_T (35.0f)
#define BACKBUTTON_POS_L (5.0f)
#define BACKBUTTON_POS_R (125.0f)
#define BACKBUTTON_POS_B (135.0f)

//�؂���&�\�� : �����w�i
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)
#define BACKGROUND_B_GAP (599.0f)

//�؂���:�X�e�[�W��I�����Ă�������
#define CUT_STAGE_T (362.0f)
#define CUT_STAGE_L (2.0f)
#define CUT_STAGE_R (537.0f)
#define CUT_STAGE_B (430.0f)//542x95
//�\��:�X�e�[�W��I�����Ă�������
#define POS_STAGE_T (15.0f)
#define POS_STAGE_L (140.0f)
#define POS_STAGE_R (690.0f)
#define POS_STAGE_B (135.0f)

//�I�u�W�F�N�g�F�X�e�[�W�Z���N�g
class CObjSwitchSelect : public CObj
{
public:
	CObjSwitchSelect() {};
	~CObjSwitchSelect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	bool Pflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Cflag[6];		//0:STAGE1  1:STAGE2  2:STAGE3
	bool Rflag;			//STAGE1�`3��STAGE4�`6�̔���𕪂��邽��
	float m_y1;
	float m_y2;

	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����

	float m_scroll;//�X�N���[����
	bool scroll_flag;
	float speed;

	int Rright;//�X�N���[���E
	int Rleft;//�X�N���[����

	bool col_flag[2]; //�J���[�t���O�@[0]=���邭�@[1]=�Â�
	char buttom_name;//�{�^���̖��O�L���p�A�J���[�ύX�Ɏg�p
	bool help_flag;//help�\���p
	bool help_flag2;//help2�y�[�W�ڕ\���p
	bool help_flag3;//help3�y�[�W�ڕ\���p
};
