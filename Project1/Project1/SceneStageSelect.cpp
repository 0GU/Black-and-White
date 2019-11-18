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
#include "SceneStageSelect.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneStageSelect::CSceneStageSelect()
{

}

//�f�X�g���N�^
CSceneStageSelect::~CSceneStageSelect()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneStageSelect::InitScene()
{
	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/���o�X�e�[�W�܂Ƃ�.png", 0, TEX_SIZE_512);
	CObjStageSelect* p = new CObjStageSelect();
	Objs::InsertObj(p, OBJ_STAGESELECT, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneStageSelect::Scene()
{

}