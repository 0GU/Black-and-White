#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define SELECT_WAIT		   (100)
#define HIT_LEFT		   (120.0f)
#define HIT_RIGHT		   (680.0f)
#define HIT_TOP_SELECT	   (130.0f)
#define HIT_BOTTOM_SELECT  (265.0f)
#define HIT_TOP_GALLERY	   (330.0f)
#define HIT_BOTTOM_GALLERY (465.0f)
#define CUT_PICTURE_TOP	   (0.0f)
#define CUT_PICTURE_LEFT   (0.0f)
#define CUT_PICTURE_RIGHT  (561.0f)
#define CUT_PICTURE_BOTTOM (135.0f)

//�؂���&�\�� : �w�i
#define BACKGROUND_TL (0.0f)
#define BACKGROUND_T_GAP (1.0f)
#define BACKGROUND_R (800.0f)
#define BACKGROUND_B (600.0f)
#define BACKGROUND_B_GAP (599.0f)

//�܂Ƃߕ\��
#define CUT_CONCLUSION_T (456.0f)
#define CUT_CONCLUSION_L (1.0f)
#define CUT_CONCLUSION_R (658.0f)
#define CUT_CONCLUSION_B (543.0f)
#define POS_CONCLUSION_T (20.0f)
#define POS_CONCLUSION_L (80.0f)
#define POS_CONCLUSION_R (740.0f)
#define POS_CONCLUSION_B (110.0f)

//�N���W�b�g�{�^��
#define CUT_CREDITBUTTON_T (927.0f)
#define CUT_CREDITBUTTON_L (0.0f)
#define CUT_CREDITBUTTON_R (150.0f)
#define CUT_CREDITBUTTON_B (998.0f)
#define POS_CREDITBUTTON_T (480.0f)
#define POS_CREDITBUTTON_L (460.0f)
#define POS_CREDITBUTTON_R (680.0f)
#define POS_CREDITBUTTON_B (580.0f)

//�N���W�b�g�\��
#define CUT_CREDIT_T (0.0f)
#define CUT_CREDIT_L (0.0f)
#define CUT_CREDIT_R (620.0f)
#define CUT_CREDIT_B (450.0f)
#define POS_CREDIT_T (0.0f)
#define POS_CREDIT_L (0.0f)
#define POS_CREDIT_R (800.0f)
#define POS_CREDIT_B (600.0f)

//�N���W�b�g�X�N���[���p
#define RESET_POS_CREDIT (0.0f)
#define CIRCLE (360.0f)
#define CREDIT_MOVE_SPEED (30.0f)

//�I�u�W�F�N�g�F���[�h�Z���N�g
class CObjModeSelect : public CObj
{
public:
	CObjModeSelect() {};
	~CObjModeSelect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	float m_y1;	//�w�i�̈ʒuY1
	float m_y2;	//�w�i�̈ʒuY2

	float C_m_y1; //�N���W�b�g�̈ʒuY1
	float C_m_y2; //�N���W�b�g�̈ʒuY2
	float m_r1; //�N���W�b�g�̍����̏㉺�^���p
	float m_r2;	//�N���W�b�g�̉E���̏㉺�^���p

	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����
	bool credit_flag;//�N���W�b�g�\���p
	bool col_flag[2]; //�J���[�t���O�@[0]=���邭�@[1]=�Â�
	char buttom_name;//�{�^���̖��O�L���p�A�J���[�ύX�Ɏg�p

	bool help_flag;//help�\���p
};
