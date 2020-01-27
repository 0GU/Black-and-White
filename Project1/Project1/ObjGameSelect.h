#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
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

//�؂���&�\�� : �w�i
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)

//Help�{�^��
#define CUT_HELPBUTTON_T (100.0f)
#define CUT_HELPBUTTON_L (924.0f)
#define CUT_HELPBUTTON_R (1024.0f)
#define CUT_HELPBUTTON_B (200.0f)
#define POS_HELPBUTTON_T (40.0f)
#define POS_HELPBUTTON_L (680.0f)
#define POS_HELPBUTTON_R (780.0f)
#define POS_HELPBUTTON_B (140.0f)

//�w���v�\��
#define CUT_HELP_T (0.0f)
#define CUT_HELP_L (0.0f)
#define CUT_HELP_R (1280.0f)
#define CUT_HELP_B (720.0f)
#define POS_HELP_T (0.0f)
#define POS_HELP_L (0.0f)
#define POS_HELP_R (800.0f)
#define POS_HELP_B (600.0f)

//�I�u�W�F�N�g�F�Q�[���Z���N�g
class CObjGameSelect : public CObj
{
public:
	CObjGameSelect() {};
	~CObjGameSelect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	float m_y1;
	float m_y2;
	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����
	bool col_flag[2]; //�J���[�t���O�@[0]=���邭�@[1]=�Â�
	bool f;
	char but;
	bool help_flag;//help�\���p

};
