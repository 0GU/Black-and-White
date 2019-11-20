#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_REVERSIBLEMAIN,
	OBJ_MOUSE,
	OBJ_MODESELECT,
	OBJ_GAMESELECT,
	OBJ_GALLERY,
	OBJ_STAGESELECT,
	OBJ_GAMECLEAR,
	OBJ_SWITCHMAIN,
	OBJ_SWITCHSELECT,

};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------h

//------------------------------------------------h
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	bool RPStageSelect[3];
	bool SPStageSelect[3];
	bool PerfectFlag[3];

};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------




//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjTitle.h"
#include "ObjReversibleMain.h"
#include "ObjMouse.h"
#include "ObjModeSelect.h"
#include "ObjGameSelect.h"
#include "ObjGallery.h"
#include "ObjStageSelect.h"
#include"ObjGameClear.h"
#include"ObjSwitchMain.h"
#include "ObjSwitchSelect.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneTitle.h"
#include "SceneReversibleMain.h"
#include "SceneModeSelect.h"
#include "SceneGameSelect.h"
#include "SceneGallery.h"
#include "SceneStageSelect.h"
#include"SceneGameClear.h"
#include"SceneSwitchMain.h"
#include "SceneSwitchSelect.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle


//-----------------------------------------------

//�e�X�g����`�`