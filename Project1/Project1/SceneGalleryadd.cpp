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
CSceneGalleryadd::CSceneGalleryadd()
{

}

//�f�X�g���N�^
CSceneGalleryadd::~CSceneGalleryadd()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneGalleryadd::InitScene()
{
	CObjGalleryadd* p = new CObjGalleryadd();
	Objs::InsertObj(p, OBJ_GALLAERYADD, 1);


	Draw::LoadImage(L"�܂Ƃ߉摜/P�f��2.png", 0, TEX_SIZE_512);

	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/�N���b�NSE.wav", EFFECT);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneGalleryadd::Scene()
{

}