#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle : public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����
};
