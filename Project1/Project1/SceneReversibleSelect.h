#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�X�e�[�W�Z���N�g
class CSceneReversibleSelect :public CScene
{
	public:
		CSceneReversibleSelect();
		~CSceneReversibleSelect();
		void InitScene();//�X�e�[�W�Z���N�g�̏��������\�b�h
		void Scene();	 //�X�e�[�W�Z���N�g�̎��s�����\�b�h
	private:
};