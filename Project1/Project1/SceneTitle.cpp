//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームタイトル初期化メソッド
void CSceneTitle::InitScene()
{
	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);

	Draw::LoadImage(L"まとめ画像/タイトル.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/マウス、シーン、クリア（透過）.png", 10, TEX_SIZE_1024);

	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/クリックSE.wav", EFFECT);

	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
	*/
}

//ゲームタイトル実行メソッド
void CSceneTitle::Scene()
{

}