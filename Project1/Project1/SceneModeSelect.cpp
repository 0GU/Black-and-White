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
#include "SceneModeSelect.h"
#include "GameHead.h"

//コンストラクタ
CSceneModeSelect::CSceneModeSelect()
{

}

//デストラクタ
CSceneModeSelect::~CSceneModeSelect()
{

}

//ゲームタイトル初期化メソッド
void CSceneModeSelect::InitScene()
{
	Draw::LoadImage(L"ギャラリー画面(移行用).png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"ゲームセレクト画面(移行用).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/haikei3.png", 2, TEX_SIZE_512);


	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);

	CObjModeSelect* p = new CObjModeSelect();
	Objs::InsertObj(p, OBJ_MODESELECT, 1);

	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮

}

//ゲームタイトル実行メソッド
void CSceneModeSelect::Scene()
{

}