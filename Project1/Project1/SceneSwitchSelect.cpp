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
	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/���o�X�e�[�W�܂Ƃ�.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/kuroen(test).png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/�}�E�X�A�V�[���A�N���A�i���߁j.png", 3, TEX_SIZE_1024);

	CObjSwitchSelect* p = new CObjSwitchSelect();
	Objs::InsertObj(p, OBJ_SWITCHSELECT, 1);
	
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��

}

//�Q�[���^�C�g�����s���\�b�h
void CSceneSwitchSelect::Scene()
{

}