#pragma once
#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���FReversible���C��
class CSceneSwitchMain :public CScene
{
public:
	CSceneSwitchMain() ;
	~CSceneSwitchMain() ;
	void InitScene();//Switch���C���̏��������\�b�h
	void Scene();	 //Switch���C���̎��s�����\�b�h
private:
};