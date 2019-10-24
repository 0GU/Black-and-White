//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneGameSelect.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameSelect::CSceneGameSelect()
{

}

//デストラクタ
CSceneGameSelect::~CSceneGameSelect()
{

}

//ゲームタイトル初期化メソッド
void CSceneGameSelect::InitScene()
{
	//CObjGameSelect* p = new CObjGameSelect();
	//Objs::InsertObj(p, OBJ_GAMESELECT, 1);
}

//ゲームタイトル実行メソッド
void CSceneGameSelect::Scene()
{

}