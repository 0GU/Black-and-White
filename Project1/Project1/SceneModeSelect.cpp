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
#include "SceneModeSelect.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneModeSelect::CSceneModeSelect()
{

}

//�f�X�g���N�^
CSceneModeSelect::~CSceneModeSelect()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneModeSelect::InitScene()
{
	Draw::LoadImage(L"�M�������[���(�ڍs�p).png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�Q�[���Z���N�g���(�ڍs�p).png", 1, TEX_SIZE_512);


	CObjModeSelect* p = new CObjModeSelect();
	Objs::InsertObj(p, OBJ_MODESELECT, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneModeSelect::Scene()
{

}