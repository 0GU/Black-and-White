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
CSceneReversibleMain::CSceneReversibleMain(int stage)
{
	stagenum = stage;
}

//�f�X�g���N�^
CSceneReversibleMain::~CSceneReversibleMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneReversibleMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"Main/�p�Y���p�l����5�~5�p.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�p�l����(96x96).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"Main/���w�i.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�q���g�{�^��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Main/���Z�b�g�{�^��.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�܂Ƃ߉摜/���A�j���[�V�����܂Ƃ�.png", 6, TEX_SIZE_1024);
	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜2.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/RSG�p�l���܂Ƃ߁i���ߍρj.png", 6, TEX_SIZE_1024);
	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜3.png", 7, TEX_SIZE_1024);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"Sound/�Q�[�����C��BGM.wav", SOUND_TYPE::BACK_MUSIC);

	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/�N���b�NSE.wav", EFFECT);
	Audio::LoadAudio(2, L"sound/GameOverTin.wav", EFFECT);
	Audio::LoadAudio(3, L"sound/ClearSE.wav", EFFECT);
	Audio::LoadAudio(4, L"sound/PerfectSE.wav", EFFECT);

	//BGM�Đ�
	//float Volume = Audio::VolumeMaster(0.7f);
	Audio::Start(0);

	CObjReversibleMain* p = new CObjReversibleMain(stagenum);
	Objs::InsertObj(p, OBJ_REVERSIBLEMAIN, 1);


	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��

}

//�Q�[�����C�����s���\�b�h
void CSceneReversibleMain::Scene()
{

}