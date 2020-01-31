#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
//������
#define INITIALIZE (0)
//�p�l���̓����蔻��
#define HIT_PANEL_TOP (60.0f)
#define HIT_PANEL_LEFT (160.0f)
#define HIT_PANEL_RIGHT (640.0f)
#define HIT_PANEL_BOTTOM (540.0f)
//�p�l��1������̑傫��
#define PANEL_SIZE_X (96.0f)
#define PANEL_SIZE_Y (96.0f)
#define ANIMATIONPANEL_SIZE_X (96)
#define ANIMATIONPANEL_SIZE_Y (120)
#define POSITION_WHITE (120.0)
//�摜�Ɣ���g�̈ʒu����␳
#define PANEL_POSITION_CORRECTION (12.0f)
#define POSITION_CORRECTION_WIDTH (10.0f)
#define POSITION_CORRECTION_HEIGHT (5.0f)
//�p�l���̐؂���ʒu(�n�_)
#define PANEL_TOP (0.0f)
#define PANEL_LEFT (0.0f)
//�X�e�[�W�z��̑傫��
#define ARRAY_SIZE_TOP (0)
#define ARRAY_SIZE_LEFT (0)
#define ARRAY_SIZE_RIGHT (4)
#define ARRAY_SIZE_BOTTOM (4)
//���]�����p
#define WHITE_PANEL (0)
#define BLACK_PANEL (1)
#define WHITE_PANEL_REVERSAL (2)
#define BLACK_PANEL_REVERSAL (3)
//�N���A���̃X�e�[�W�Z���N�g�p����g
#define STAGE_SELECT_TOP (370.0f)
#define STAGE_SELECT_LEFT (130.0f)
#define STAGE_SELECT_RIGHT (690.0f)
#define STAGE_SELECT_BOTTOM (490.0f)
//YES�{�^���p����g
#define YES_BUTTON_TOP (370.0f)
#define YES_BUTTON_LEFT (130.0f)
#define YES_BUTTON_RIGHT (370.0f)
#define YES_BUTTON_BOTTOM (490.0f)
//NO�{�^���p����g
#define NO_BUTTON_TOP (370.0f)
#define NO_BUTTON_LEFT (410.0f)
#define NO_BUTTON_RIGHT (650.0f)
#define NO_BUTTON_BOTTOM (490.0f)
//���Z�b�g�{�^���p����g
#define RESET_BUTTON_TOP (430.0f)
#define RESET_BUTTON_LEFT (650.0f)
#define RESET_BUTTON_RIGHT (770.0f)
#define RESET_BUTTON_BOTTOM (530.0f)
//�q���g�{�^���p����g
#define HINT_BUTTON_TOP (250.0f)
#define HINT_BUTTON_LEFT (650.0f)
#define HINT_BUTTON_RIGHT (770.0f)
#define HINT_BUTTON_BOTTOM (350.0f)
//�X�e�[�W�Z���N�g�p����g
#define SELECT_BUTTON_TOP (60.0f)
#define SELECT_BUTTON_LEFT (30.0f)
#define SELECT_BUTTON_RIGHT (130.0f)
#define SELECT_BUTTON_BOTTOM (160.0f)
//�w�i�摜�\���p
#define SRC_BACKGROUND_TOP  (0.0f)
#define SRC_BACKGROUND_LEFT  (0.0f)
#define SRC_BACKGROUND_RIGHT (800.0f)
#define SRC_BACKGROUND_BOTTOM  (600.0f)
#define DST_BACKGROUND_TOP  (0.0f)
#define DST_BACKGROUND_LEFT  (0.0f)
#define DST_BACKGROUND_RIGHT  (800.0f)
#define DST_BACKGROUND_BOTTOM  (600.0f)
//�q���g�摜�\���p
#define SRC_HINT_TOP  (0.0f)
#define SRC_HINT_LEFT  (0.0f)
#define SRC_HINT_RIGHT (120.0f)
#define SRC_HINT_BOTTOM  (100.0f)
//���Z�b�g�摜�\���p
#define SRC_RESET_TOP  (0.0f)
#define SRC_RESET_LEFT  (0.0f)
#define SRC_RESET_RIGHT (120.0f)
#define SRC_RESET_BOTTOM  (100.0f)
//�X�e�[�W�Z���N�g�摜�\���p
#define SRC_SELECT_TOP  (820.0f)
#define SRC_SELECT_LEFT  (478.0f)
#define SRC_SELECT_RIGHT (598.0f)
#define SRC_SELECT_BOTTOM  (920.0f)
//Perfect�摜�\���p
#define SRC_PERFECT_TOP  (370.0f)
#define SRC_PERFECT_LEFT  (0.0f)
#define SRC_PERFECT_RIGHT (560.0f)
#define SRC_PERFECT_BOTTOM  (491.0f)
#define DST_PERFECT_TOP  (150.0f)
#define DST_PERFECT_LEFT  (100.0f)
#define DST_PERFECT_RIGHT  (690.0f)
#define DST_PERFECT_BOTTOM  (300.0f)
//�N���A���̃X�e�[�W�Z���N�g�摜�\���p
#define SRC_STAGE_SELECT_TOP (490.0f)
#define SRC_STAGE_SELECT_LEFT (0.0f)
#define SRC_STAGE_SELECT_RIGHT (560.0f)
#define SRC_STAGE_SELECT_BOTTOM (610.0f)
//�N���A�摜�\���p
#define SRC_CLERE_TOP  (249.0f)
#define SRC_CLERE_LEFT  (0.0f)
#define SRC_CLERE_RIGHT (560.0f)
#define SRC_CLERE_BOTTOM  (372.0f)
#define DST_CLERE_TOP  (150.0f)
#define DST_CLERE_LEFT  (130.0f)
#define DST_CLERE_RIGHT  (690.0f)
#define DST_CLERE_BOTTOM  (270.0f)
//�Q�[���I�[�o�[�摜�\���p
#define SRC_GAMEOVER_TOP  (0.0f)
#define SRC_GAMEOVER_LEFT  (0.0f)
#define SRC_GAMEOVER_RIGHT (580.0f)
#define SRC_GAMEOVER_BOTTOM  (250.0f)
#define DST_GAMEOVER_TOP  (70.0f)
#define DST_GAMEOVER_LEFT  (110.0f)
#define DST_GAMEOVER_RIGHT  (690.0f)
#define DST_GAMEOVER_BOTTOM  (320.0f)
//YES�摜�\���p
#define SRC_YES_TOP  (820.0f)
#define SRC_YES_LEFT  (0.0f)
#define SRC_YES_RIGHT (240.0f)
#define SRC_YES_BOTTOM  (940.0f)
//NO�摜�\���p
#define SRC_NO_TOP  (820.0f)
#define SRC_NO_LEFT  (239.0f)
#define SRC_NO_RIGHT (479.0f)
#define SRC_NO_BOTTOM  (940.0f)
//�X�e�[�W�Z���N�g�֖߂�摜�\���p
#define SRC_RETURNSELECT_TOP  (0.0f)
#define SRC_RETURNSELECT_LEFT  (0.0f)
#define SRC_RETURNSELECT_RIGHT (520.0f)
#define SRC_RETURNSELECT_BOTTOM  (90.0f)
#define DST_RETURNSELECT_TOP  (150.0f)
#define DST_RETURNSELECT_LEFT  (130.0f)
#define DST_RETURNSELECT_RIGHT  (650.0f)
#define DST_RETURNSELECT_BOTTOM  (270.0f)


//STAGE(����)�̉摜
#define SRC_STAGE_TOP (820.0f)
#define SRC_STAGE_LEFT (180.0f)
#define SRC_STAGE_RIGHT (280.0f)
#define SRC_STAGE_BOTTOM (865.0f)
#define DST_STAGE_TOP (450.0f)
#define DST_STAGE_LEFT (10.0f)
#define DST_STAGE_RIGHT (110.0f)
#define DST_STAGE_BOTTOM (495.0f)


//�X�e�[�W�i���o�[(����)�̉摜�؂���:1�`4 
#define SRC_STAGECOUNT_TOP_1234 (0.0f)
#define SRC_STAGECOUNT_BOTTOM_1234 (119.0f)

//�X�e�[�W�i���o�[�̉摜�؂���:5,6
#define SRC_STAGECOUNT_TOP_56 (120.0f)
#define SRC_STAGECOUNT_BOTTOM_56 (240.0f)

//�X�e�[�W1
#define SRC_STAGECOUNT_LEFT_1 (1.0f)
#define SRC_STAGECOUNT_RIGHT_1 (119.0f)
//�X�e�[�W2
#define SRC_STAGECOUNT_LEFT_2 (120.0f)
#define SRC_STAGECOUNT_RIGHT_2 (120.0f)
//�X�e�[�W3
#define SRC_STAGECOUNT_LEFT_3 (120.0f)
#define SRC_STAGECOUNT_RIGHT_3 (120.0f)
//�X�e�[�W4
#define SRC_STAGECOUNT_LEFT_4 (120.0f)
#define SRC_STAGECOUNT_RIGHT_4 (120.0f)
//�X�e�[�W5
#define SRC_STAGECOUNT_LEFT_5 (0.0f)
#define SRC_STAGECOUNT_RIGHT_5 (120.0f)
//�X�e�[�W6
#define SRC_STAGECOUNT_LEFT_6 (120.0f)
#define SRC_STAGECOUNT_RIGHT_6 (120.0f)

//�X�e�[�W�i���o�[�\��
#define DST_STAGECOUNT_TOP (450.0f)
#define DST_STAGECOUNT_LEFT (105.0f)
#define DST_STAGECOUNT_RIGHT (155.0f)
#define DST_STAGECOUNT_BOTTOM (500.0f)


//Count(�E��)�摜
#define SRC_COUNT_TOP (820.0f)
#define SRC_COUNT_LEFT (20.0f)
#define SRC_COUNT_RIGHT (130.0f)
#define SRC_COUNT_BOTTOM (860.0f)
#define DST_COUNT_TOP (40.0f)
#define DST_COUNT_LEFT (660.0f)
#define DST_COUNT_RIGHT (770.0f)
#define DST_COUNT_BOTTOM (80.0f)

//Help�{�^��
#define CUT_HELPBUTTON_T2 (0.0f)
#define CUT_HELPBUTTON_L (924.0f)
#define CUT_HELPBUTTON_R (1024.0f)
#define CUT_HELPBUTTON_B2 (100.0f)
#define POS_HELPBUTTON_T_RB (120.0f)
#define POS_HELPBUTTON_L_RB (671.0f)
#define POS_HELPBUTTON_R_RB (771.0f)
#define POS_HELPBUTTON_B_RB (220.0f)

//�w���v�\��
#define CUT_HELP_T (0.0f)
#define CUT_HELP_L (0.0f)
#define CUT_HELP_R (1280.0f)
#define CUT_HELP_B (720.0f)
#define POS_HELP_T (0.0f)
#define POS_HELP_L (0.0f)
#define POS_HELP_R (800.0f)
#define POS_HELP_B (600.0f)


//�I�u�W�F�N�g�FReversible���C��
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain(int stage);
	~CObjReversibleMain() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	void Reverse();
	float x, y;


private:
	int stage[5][5];
	int stage_reset[5][5];
	//count�Ǘ��p
	int count[3];  //[0]�c�ŒZ�萔����p [1]�c�萔�\���p [2]�c�萔���Z�b�g�p
	//�X�e�[�W�ǂݍ��ݗp
	int StageSlect;
	//�A�j���[�V�����ύX�p
	int m_ani_flame;
	int change_panel[5][5];
	bool m_ani_flag;
	bool time_flag;
	int m_time;

	int sx, sy;
	int lx, ly;//���]�����p�ϐ�
	int i, j;


	//�N���b�N����p
	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�

	//�}�E�X�G�t�F�N�g�p
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����

	//�t���O�Ǘ��p
	bool flag[8];	//[0]�chint�t���O�@[1]�cClear�t���O�@[2]�cGameOver�t���O [3]�cYes�ENo�t���O 
					//[4]�cPerfect�t���O [5]�cPerfect���̉�]�t���O [6][7]�cGyallery�p�t���O


	float colorchange;
	bool colorflag;

	bool Debugflag;

	bool col_flag[2]; //�J���[�t���O�@[0]=���邭�@[1]=�Â�
	char buttom_name;//�{�^���̖��O�L���p�A�J���[�ύX�Ɏg�p

	bool help_flag;//help�\���p
	bool help_flag2;//help2�y�[�W�ڕ\���p
};