#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_REVERSIBLEMAIN,
	OBJ_MODESELECT,
	OBJ_GAMESELECT,
	OBJ_GALLERY,
	OBJ_REVERSIBLESELECT,
	OBJ_GAMECLEAR,
	OBJ_SWITCHMAIN,
	OBJ_SWITCHSELECT,
	OBJ_MOUSE,//仮
	OBJ_GALLAERYADD,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ

	bool SPerfectFlag[6];
	bool RPerfectFlag[6];
	bool SClearFlag[6];
	bool RClearFlag[6];

};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------




//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjTitle.h"
#include "ObjReversibleMain.h"
#include "ObjModeSelect.h"
#include "ObjGameSelect.h"
#include "ObjGallery.h"
#include "ObjReversibleSelect.h"
#include "ObjGameClear.h"
#include "ObjSwitchMain.h"
#include "ObjSwitchSelect.h"
#include "ObjMouse.h"//仮
#include "ObjGalleryadd.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneReversibleMain.h"
#include "SceneModeSelect.h"
#include "SceneGameSelect.h"
#include "SceneGallery.h"
#include "SceneReversibleSelect.h"
#include "SceneGameClear.h"
#include "SceneSwitchMain.h"
#include "SceneSwitchSelect.h"
#include "SceneGalleryadd.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle


//-----------------------------------------------
