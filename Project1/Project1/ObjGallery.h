#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�N��
#define SCENEBACK_WAIT (200)
#define SELECT_WAIT (100)


//�I�u�W�F�N�g�F�M�������[
class CObjGallery : public CObj
{
public:
	CObjGallery() {};
	~CObjGallery() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:
	float x, y;
	int Gright;
	int Gleft;
	bool SFlag[3]; //Switch�̃t���O
	bool RFlag[3]; //Reversible�̃t���O

};
