#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FReversible���C��
class CObjReversibleMain : public CObj
{
public:
	CObjReversibleMain() {};
	~CObjReversibleMain() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	float x, y;
	

private:
	int stage[5][5];
	int stage_reset[5][5];
	//count�Ǘ��p
	int count[2];  //[0]�cPerfectClearcount [1]�cClearcount
	//�X�e�[�W�ǂݍ��ݗp
	int StageSlect;
	//�A�j���[�V�����ύX�p
	int m_ani_flame;
	int change_panel[5][5];
	bool m_change;
	bool time_flag;
	int m_time;
	//�t���O�Ǘ��p
	bool flag[5];  //[0]�chint�t���O�@[1]�cClear�t���O�@[2]�cGameOver�t���O [3]�c	Yes�ENo�t���O
};