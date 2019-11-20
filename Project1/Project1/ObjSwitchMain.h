#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FReversible���C��
class CObjSwitchMain : public CObj
{
public:
	CObjSwitchMain() {};
	~CObjSwitchMain() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	float x, y;
	static bool Gflag[3]; //[0]�cStage1�A[1]�cStage2�@[2]�cStage3	��Perfect�t���O
	static void GetFlag(bool flag[3]);
private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	int count[2];  //[0]�cPerfectClearcount [1]�cClearcount
	int StageSlect;


	int sx, sy;		//�}�E�X���������ʒu��ۑ�
	
	//�A�j���[�V�����ύX�p
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	float r;		//�A�j���[�V�����̊p�x�ύX�p

	bool flag[6];  //[0]�chint�t���O�@[1]�cClear�t���O�@[2]�cGameOver�t���O [6]�cPerfect�t���O
};