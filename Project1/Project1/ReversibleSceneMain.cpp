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
#include "ReversibleSceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSReversibleSceneMain::CSReversibleSceneMain()
{

}

//デストラクタ
CSReversibleSceneMain::~CSReversibleSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSReversibleSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"パズルパネル黒5×5用.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"パネル白(96x96).png", 1, TEX_SIZE_512);


	//CObjMain* p = new CObjMain();
	//Objs::InsertObj(p, OBJ_MAIN, 1);

	//CObjChar* c = new CObjChar();
	//Objs::InsertObj(c, OBJ_CHAR, 1);
}

//ゲームメイン実行メソッド
void CSReversibleSceneMain::Scene()
{

}