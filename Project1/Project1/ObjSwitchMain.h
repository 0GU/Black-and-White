#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��

/*
resource
	//StageSelect�{�^��-----------------------------------------------
	//�؂���
	src.m_top = 820.0f;
	src.m_left = 478.0f;
	src.m_right = 600.0f;
	src.m_bottom = 920.0f;
*/

#define RESOURCE_SELE_BUTTON_T (820.0f)
#define RESOURCE_SELE_BUTTON_L (478.0f)
#define RESOURCE_SELE_BUTTON_R (600.0f)
#define RESOURCE_SELE_BUTTON_B (920.0f)
#define RESOURCE_PERFECT_T (370.0f)
#define RESOURCE_PERFECT_L (0.0f)
#define RESOURCE_PERFECT_R (560.0f)
#define RESOURCE_PERFECT_B (491.0f)
#define RESOURCE_GAMECLEAR_T (249.0f)
#define RESOURCE_GAMECLEAR_L (0.0f)
#define RESOURCE_GAMECLEAR_R (560.0f)
#define RESOURCE_GAMECLEAR_B (372.0f)
#define RESOURCE_CLEARBACK_T (490.0f)
#define RESOURCE_CLEARBACK_L (0.0f)
#define RESOURCE_CLEARBACK_R (560.0f)
#define RESOURCE_CLEARBACK_B (610.0f)
#define RESOURCE_GAMEOVER_T (0.0f)
#define RESOURCE_GAMEOVER_L (0.0f)
#define RESOURCE_GAMEOVER_R (580.0f)
#define RESOURCE_GAMEOVER_B (250.0f)
#define RESOURCE_YESNO_BUTTON_T (820.0f)
#define RESOURCE_YESNO_BUTTON_B (940.0f)
#define RESOURCE_YES_BUTTON_L (0.0f)
#define RESOURCE_YES_BUTTON_R (240.0f)
#define RESOURCE_NO_BUTTON_L (239.0f)
#define RESOURCE_NO_BUTTON_R (479.0f)
#define RESOURCE_BACKSELECT_T (0.0f)
#define RESOURCE_BACKSELECT_L (0.0f)
#define RESOURCE_BACKSELECT_R (520.0f)
#define RESOURCE_BACKSELECT_B (91.0f)

/*
	//�\��
	//�v���O�����̖���x�l��10f���炵�Ă܂�
	dst.m_top = 60.0f;
	dst.m_left = 30.0f;
	dst.m_right = 130.0;
	dst.m_bottom = 160.0f;
*/
#define STAGESELE_BUTTON_POS_T (60.0f)
#define STAGESELE_BUTTON_POS_L (30.0f)
#define STAGESELE_BUTTON_POS_R (130.0f)
#define STAGESELE_BUTTON_POS_B (160.0f)
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
#define YES_BUTTON_POS_L (130.0f)
#define YES_BUTTON_POS_R (370.0f)
#define NO_BUTTON_POS_L (410.0f)
#define NO_BUTTON_POS_R (649.0f)
#define BACKSELECT_TEXT_POS_T (150.0f)
#define BACKSELECT_TEXT_POS_L (130.0f)
#define BACKSELECT_TEXT_POS_R (650.0f)
#define BACKSELECT_TEXT_POS_B (270.0f)


//�I�u�W�F�N�g�FReversible���C��
class CObjSwitchMain : public CObj
{
public:
	CObjSwitchMain(int stage);
	~CObjSwitchMain() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	float x, y;
private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	int count[3];  //[0]�cPerfectClearcount [1]�cClearcount [2]�cCountreset
	int StageSlect;

	int sx, sy;		//�}�E�X���������ʒu��ۑ�
	
	//�A�j���[�V�����ύX�p
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	float r;		//�A�j���[�V�����̊p�x�ύX�p

	bool flag[7];  //[0]�chint�t���O�@[1]�cClear�t���O�@[2]�cGameOver�t���O [6]�cPerfect�t���O
};