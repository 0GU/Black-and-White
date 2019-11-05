//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include"GameL/DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneStageSelect.h"
#include "GameHead.h"

//コンストラクタ
CSceneStageSelect::CSceneStageSelect()
{

}

//デストラクタ
CSceneStageSelect::~CSceneStageSelect()
{

}

//ゲームタイトル初期化メソッド
void CSceneStageSelect::InitScene()
{

	Draw::LoadImageW(L"まとめ画像/まとめ画像1.png", 0, TEX_SIZE_512);
	CObjStageSelect* p = new CObjStageSelect();
	Objs::InsertObj(p, OBJ_STAGESELECT, 1);
}

//ゲームタイトル実行メソッド
void CSceneStageSelect::Scene()
{

}