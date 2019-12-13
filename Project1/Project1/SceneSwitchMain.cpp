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
#include "SceneSwitchMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneSwitchMain::CSceneSwitchMain(int stage)
{
	stagenum = stage;
}

//デストラクタ
CSceneSwitchMain::~CSceneSwitchMain()
{

}

//ゲームメイン初期化メソッド
void CSceneSwitchMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"Main/パズルパネル黒5×5用.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"Main/パネル白(96x96).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"Main/白背景.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"Main/ヒントボタン.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Main/リセットボタン.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/まとめ画像2.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"Main/スイッチ上下.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Main/スイッチ左右.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/SPGアニメーション.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"まとめ画像/まとめ画像3.png", 9, TEX_SIZE_1024);
	Draw::LoadImage(L"まとめ画像/マウス、シーン、クリア（透過）.png", 10, TEX_SIZE_1024);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"Sound/SwitchBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/SwitchButtonA.wav", EFFECT);
	Audio::LoadAudio(2, L"Sound/GameOverTin.wav", EFFECT);
	Audio::LoadAudio(3, L"Sound/ClearSE.wav", EFFECT);
	Audio::LoadAudio(4, L"Sound/PerfectSE.wav", EFFECT);
	Audio::LoadAudio(5, L"Sound/HintButton.wav", EFFECT);
	Audio::LoadAudio(6, L"Sound/ResetButton.wav", EFFECT);
	Audio::LoadAudio(7, L"Sound/SwitchHard.wav", SOUND_TYPE::BACK_MUSIC);

	//BGM再生---------------------
	//ステージ3だとBGM変更
	if (stagenum == 3)
		Audio::Start(7);
	else
		Audio::Start(0);

	CObjSwitchMain* p = new CObjSwitchMain(stagenum);
	Objs::InsertObj(p, OBJ_SWITCHMAIN, 1);
	/*
	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
	*/
}

//ゲームメイン実行メソッド
void CSceneSwitchMain::Scene()
{

}