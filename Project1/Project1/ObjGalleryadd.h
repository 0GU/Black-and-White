#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define WINDOW_SIZE_TOP_LEFT (0.0f)
#define WINDOW_SIZE_X (800.0f)
#define WINDOW_SIZE_Y (600.0f)
#define CLICK_WAIT (300)


//�I�u�W�F�N�g�F�^�C�g��
class CObjGalleryadd : public CObj
{
public:
	CObjGalleryadd() {};
	~CObjGalleryadd() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float x, y;
private:
	int m_time;
	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����


};
