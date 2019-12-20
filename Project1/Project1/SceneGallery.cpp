//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"
#include "GameL/UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneGallery.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGallery::CSceneGallery()
{

}

//�f�X�g���N�^
CSceneGallery::~CSceneGallery()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneGallery::InitScene()
{
	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);

	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Audio::LoadAudio(3, L"Sound/����݊���l�`�M�������[.wav", SOUND_TYPE::BACK_MUSIC);


	Draw::LoadImage(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"gallery���g.png", 1, TEX_SIZE_512);
	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->SPerfectFlag[i] == false)
		{
			break;
		}
		if (i == 2)
		{
			Draw::LoadImage(L"�܂Ƃ߉摜/�X�C�b�`�N���A.png", 3, TEX_SIZE_4096);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (((UserData*)Save::GetData())->RPerfectFlag[i] == false)
		{
			break;
		}
		if (i == 5)
		{
			Draw::LoadImage(L"�܂Ƃ߉摜/���o�[�V�u���N���A�摜.png", 4, TEX_SIZE_512);
		}
	}

	Draw::LoadImage(L"�܂Ƃ߉摜/���w�i.png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"�܂Ƃ߉摜/�}�E�X�A�V�[���A�N���A�i���߁j.png", 10, TEX_SIZE_1024);

	CObjGallery* p = new CObjGallery();
	Objs::InsertObj(p, OBJ_GALLERY, 1);
	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��
	*/


	Audio::Start(3);

}

//�Q�[���^�C�g�����s���\�b�h
void CSceneGallery::Scene()
{

}