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
CSceneGalleryadd::CSceneGalleryadd()
{

}

//デストラクタ
CSceneGalleryadd::~CSceneGalleryadd()
{

}

//ゲームタイトル初期化メソッド
void CSceneGalleryadd::InitScene()
{
	CObjGalleryadd* p = new CObjGalleryadd();
	Objs::InsertObj(p, OBJ_GALLAERYADD, 1);


	Draw::LoadImage(L"まとめ画像/P素材2.png", 0, TEX_SIZE_512);

	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/クリックSE.wav", EFFECT);
}

//ゲームタイトル実行メソッド
void CSceneGalleryadd::Scene()
{

}