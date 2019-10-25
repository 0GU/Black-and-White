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
#include "SceneReversibleMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneReversibleMain::CSceneReversibleMain()
{

}

//�f�X�g���N�^
CSceneReversibleMain::~CSceneReversibleMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneReversibleMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�p�Y���p�l����5�~5�p.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�p�l����(96x96).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"���w�i.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�q���g�{�^��.png", 3, TEX_SIZE_512);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�Q�[�����C��BGM.wav", SOUND_TYPE::BACK_MUSIC);

	//BGM�Đ�
	float Volume = Audio::VolumeMaster(-0.3f);
	Audio::Start(0);

	CObjReversibleMain* p = new CObjReversibleMain();
	Objs::InsertObj(p, OBJ_REVERSIBLEMAIN, 1);

	CObjMouse* c = new CObjMouse();
	Objs::InsertObj(c, OBJ_MOUSE, 1);


}

//�Q�[�����C�����s���\�b�h
void CSceneReversibleMain::Scene()
{

}