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
#include "SceneGameClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameClear::CSceneGameClear()
{

}

//�f�X�g���N�^
CSceneGameClear::~CSceneGameClear()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneGameClear::InitScene()
{
	Draw::LoadImage(L"�M�������[���(�ڍs�p).png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�Q�[���Z���N�g���(�ڍs�p).png", 1, TEX_SIZE_512);


	CObjGameClear* p = new CObjGameClear();
	Objs::InsertObj(p, OBJ_GAMECLEAR, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneGameClear::Scene()
{

}