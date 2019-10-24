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
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	//Draw::LoadImage(L" ", 0, TEX_SIZE_512);
	

	//CObjMain* p = new CObjMain();
	//Objs::InsertObj(p, OBJ_MAIN, 1);

	//CObjChar* c = new CObjChar();
	//Objs::InsertObj(c, OBJ_CHAR, 1);
}

//ゲームメイン実行メソッド
void CSceneMain::Scene()
{

}