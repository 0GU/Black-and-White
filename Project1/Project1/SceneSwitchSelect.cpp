//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL/DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneSwitchSelect.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSwitchSelect::CSceneSwitchSelect()
{

}

//�f�X�g���N�^
CSceneSwitchSelect::~CSceneSwitchSelect()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneSwitchSelect::InitScene()
{
	
	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 0, TEX_SIZE_512);
	CObjSwitchSelect* p = new CObjSwitchSelect();
	Objs::InsertObj(p, OBJ_SWITCHSELECT, 1);
	
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneSwitchSelect::Scene()
{

}