#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

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
	bool Flag[3];	

};
