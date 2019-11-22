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
	Draw::LoadImage(L"�܂Ƃ߉摜/haikei3.png", 2, TEX_SIZE_512);


	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);

	CObjModeSelect* p = new CObjModeSelect();
	Objs::InsertObj(p, OBJ_MODESELECT, 1);

	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��

}

//�Q�[���^�C�g�����s���\�b�h
void CSceneModeSelect::Scene()
{

}