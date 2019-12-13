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
#include "SceneSwitchMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSwitchMain::CSceneSwitchMain(int stage)
{
	stagenum = stage;
}

//�f�X�g���N�^
CSceneSwitchMain::~CSceneSwitchMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSwitchMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"Main/�p�Y���p�l����5�~5�p.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�p�l����(96x96).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"Main/���w�i.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�q���g�{�^��.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Main/���Z�b�g�{�^��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�X�C�b�`�㉺.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Main/�X�C�b�`���E.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/SPG�A�j���[�V����.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"�܂Ƃ߉摜/�܂Ƃ߉摜3.png", 9, TEX_SIZE_1024);
	Draw::LoadImage(L"�܂Ƃ߉摜/�}�E�X�A�V�[���A�N���A�i���߁j.png", 10, TEX_SIZE_1024);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"Sound/SwitchBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//SE���̓o�^
	Audio::LoadAudio(1, L"Sound/SwitchButtonA.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/GameOverTin.wav", EFFECT);
	Audio::LoadAudio(3, L"Sound/ClearSE.wav", EFFECT);
	Audio::LoadAudio(4, L"Sound/PerfectSE.wav", EFFECT);
	Audio::LoadAudio(5, L"Sound/HintButton.wav", EFFECT);
	Audio::LoadAudio(6, L"Sound/ResetButton.wav", EFFECT);
	Audio::LoadAudio(7, L"Sound/SwitchHard.wav", SOUND_TYPE::BACK_MUSIC);

	//BGM�Đ�---------------------
	//�X�e�[�W3����BGM�ύX
	if (stagenum == 3)
		Audio::Start(7);
	else
		Audio::Start(0);

	CObjSwitchMain* p = new CObjSwitchMain(stagenum);
	Objs::InsertObj(p, OBJ_SWITCHMAIN, 1);
	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//��
	*/
}

//�Q�[�����C�����s���\�b�h
void CSceneSwitchMain::Scene()
{

}