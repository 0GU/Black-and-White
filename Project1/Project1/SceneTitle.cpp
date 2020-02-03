//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneTitle::InitScene()
{
	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);

	Draw::LoadImage(L"�܂Ƃ߉摜/�^�C�g��.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/�}�E�X�A�V�[���A�N���A�i���߁j.png", 10, TEX_SIZE_1024);

	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/�N���b�NSE.wav", EFFECT);

	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��
	*/
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneTitle::Scene()
{

}