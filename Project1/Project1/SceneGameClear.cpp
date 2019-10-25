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
#include "SceneGameClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameClear::CSceneGameClear()
{

}

//デストラクタ
CSceneGameClear::~CSceneGameClear()
{

}

//ゲームタイトル初期化メソッド
void CSceneGameClear::InitScene()
{
	Draw::LoadImage(L"Game Clear!!.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"ステージ選択へ戻る.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"白背景.png", 2, TEX_SIZE_512);


	CObjGameClear* p = new CObjGameClear();
	Objs::InsertObj(p, OBJ_GAMECLEAR, 1);
}

//ゲームタイトル実行メソッド
void CSceneGameClear::Scene()
{

}