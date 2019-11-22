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
#include "SceneReversibleSelect.h"
#include "GameHead.h"

//コンストラクタ
CSceneReversibleSelect::CSceneReversibleSelect()
{

}

//デストラクタ
CSceneReversibleSelect::~CSceneReversibleSelect()
{

}

//ゲームタイトル初期化メソッド
void CSceneReversibleSelect::InitScene()
{
	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Draw::LoadImageW(L"まとめ画像/まとめ画像1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/リバステージまとめ.png", 0, TEX_SIZE_512);
	CObjReversibleSelect* p = new CObjReversibleSelect();
	Objs::InsertObj(p, OBJ_REVERSIBLESELECT, 1);

	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮

}

//ゲームタイトル実行メソッド
void CSceneReversibleSelect::Scene()
{

}