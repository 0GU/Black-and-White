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
#include "ReversibleSceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSReversibleSceneMain::CSReversibleSceneMain()
{

}

//�f�X�g���N�^
CSReversibleSceneMain::~CSReversibleSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSReversibleSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�p�Y���p�l����5�~5�p.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�p�l����(96x96).png", 1, TEX_SIZE_512);


	//CObjMain* p = new CObjMain();
	//Objs::InsertObj(p, OBJ_MAIN, 1);

	//CObjChar* c = new CObjChar();
	//Objs::InsertObj(c, OBJ_CHAR, 1);
}

//�Q�[�����C�����s���\�b�h
void CSReversibleSceneMain::Scene()
{

}