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
#include "SceneSwitchSelect.h"
#include "GameHead.h"

//コンストラクタ
CSceneSwitchSelect::CSceneSwitchSelect()
{

}

//デストラクタ
CSceneSwitchSelect::~CSceneSwitchSelect()
{

}

//ゲームタイトル初期化メソッド
void CSceneSwitchSelect::InitScene()
{
	//SE情報の登録
	Audio::LoadAudio(0, L"Sound/スイッチセレクト.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Draw::LoadImageW(L"まとめ画像/まとめ画像1.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/リバステージまとめ.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/kuroen(test).png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/help3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"まとめ画像/まとめ画像3.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/help8.png", 5, TEX_SIZE_1024);
	Draw::LoadImage(L"まとめ画像/help9.png", 6, TEX_SIZE_1024);
	Draw::LoadImage(L"まとめ画像/マウス、シーン、クリア（透過）.png", 10, TEX_SIZE_1024);

	CObjSwitchSelect* p = new CObjSwitchSelect();
	Objs::InsertObj(p, OBJ_SWITCHSELECT, 1);
	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
	*/
	Audio::Start(0);
}

//ゲームタイトル実行メソッド
void CSceneSwitchSelect::Scene()
{

}