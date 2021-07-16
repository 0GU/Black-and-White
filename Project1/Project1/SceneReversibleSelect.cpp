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
#include "SceneReversibleSelect.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneReversibleSelect::CSceneReversibleSelect()
{

}

//�f�X�g���N�^
CSceneReversibleSelect::~CSceneReversibleSelect()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneReversibleSelect::InitScene()
{
	//SE���̓o�^
	Audio::LoadAudio(0, L"Sound/ReversibleBackBGM.wav", SOUND_TYPE::BACK_MUSIC);


	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Draw::LoadImage(L"�܂Ƃ߉摜/haikei4.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/���o�X�e�[�W�܂Ƃ�.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/�}�E�X�A�V�[���A�N���A�i���߁j.png", 10, TEX_SIZE_1024);
	Draw::LoadImage(L"�܂Ƃ߉摜/help3.png", 4, TEX_SIZE_1024);
	Draw::LoadImage(L"�܂Ƃ߉摜/help8.png", 5, TEX_SIZE_1024);
	Draw::LoadImage(L"�܂Ƃ߉摜/help9.png", 6, TEX_SIZE_1024);

	CObjReversibleSelect* p = new CObjReversibleSelect();
	Objs::InsertObj(p, OBJ_REVERSIBLESELECT, 1);
	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��
	*/
	Audio::Start(0);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneReversibleSelect::Scene()
{

}