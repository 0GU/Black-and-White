#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�E�X
class CObjMouse :public CObj
{
public:
	CObjMouse() {};
	~CObjMouse() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h��
private:
	float m_mou_x;//�}�E�X�̈ʒu��
	float m_mou_y;//�}�E�X�̈ʒuY
	bool m_mou_l;//�}�E�X���{�^��
};