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
#include "SceneGallery.h"
#include "GameHead.h"

//コンストラクタ
CSceneGallery::CSceneGallery()
{

}

//デストラクタ
CSceneGallery::~CSceneGallery()
{

}

//ゲームタイトル初期化メソッド
void CSceneGallery::InitScene()
{
	CObjGallery* p = new CObjGallery();
	Objs::InsertObj(p, OBJ_GALLERY, 1);
}

//ゲームタイトル実行メソッド
void CSceneGallery::Scene()
{

}