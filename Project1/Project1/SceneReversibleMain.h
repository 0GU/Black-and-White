#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FReversible���C��
class CSceneReversibleMain :public CScene
{
public:
	CSceneReversibleMain(int stage);
	~CSceneReversibleMain();
	 int SetStage();
	void InitScene();//Reversible���C���̏��������\�b�h
	void Scene();	 //Reversible���C���̎��s�����\�b�h
private:
	 int stagenum;
	
};