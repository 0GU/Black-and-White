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
	Draw::LoadImage(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 0, TEX_SIZE_512);

	CObjGallery* p = new CObjGallery();
	Objs::InsertObj(p, OBJ_GALLERY, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneGallery::Scene()
{

}