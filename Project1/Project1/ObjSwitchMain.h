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


private:
	int stage[5][5];
	int stage_reset[5][5];
	int Clear_count;
	bool flag[3];  //[0]�chint�t���O�@[1]�cClear�t���O�@[2]�cGameOver�t���O
};