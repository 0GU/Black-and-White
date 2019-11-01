//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL\DrawTexture.h"

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
	Draw::LoadImage(L"まとめ画像/まとめ画像1.png", 0, TEX_SIZE_512);

	CObjGameSelect* p = new CObjGameSelect();
	Objs::InsertObj(p, OBJ_GAMESELECT, 1);

	/*Draw::LoadImage(L"", 0, TEX_SIZE_512);
	
	CObjGameSelect* p = new CObjGameSelect();
	Objs::InsertObj(p, OBJ_GAMESELECT, 1);*/
	

	
	
}

//ゲームタイトル実行メソッド
void CSceneGameSelect::Scene()
{

}