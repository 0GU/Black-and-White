#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define SELECT_WAIT		   (100)
#define HIT_LEFT		   (118.0f)
#define HIT_RIGHT		   (670.0f)
#define HIT_TOP_SELECT	   (128.0f)
#define HIT_BOTTOM_SELECT  (260.0f)
#define HIT_TOP_GALLERY	   (323.0f)
#define HIT_BOTTOM_GALLERY (455.0f)
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
	float m_x1;	//�w�i�̈ʒuX1
	float m_x2;	//�w�i�̈ʒuX2
	float m_y1;	//�w�i�̈ʒuY1
	float m_y2;	//�w�i�̈ʒuY2

	bool c_flag[2];	//�N���b�N�t���O	[0]=�����Ă��� [1]=�����Ă��Ȃ�
	bool back;		//�w�i�F���ʗp		true=�� , false=��
	bool mou_call;	//�}�E�X�Ăяo���p�A1��̂ݓ�����
};
