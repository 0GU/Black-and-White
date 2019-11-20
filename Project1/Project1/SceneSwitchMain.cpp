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

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"Sound/ゲームメインBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/クリックSE.wav",  EFFECT);
	Audio::LoadAudio(2, L"Sound/GameOverTin.wav", EFFECT);
	Audio::LoadAudio(3, L"Sound/ClearSE.wav", EFFECT);
	Audio::LoadAudio(4, L"Sound/PerfectSE.wav", EFFECT);

	//BGM再生
	Audio::Start(0);

	CObjSwitchMain* p = new CObjSwitchMain(stagenum);
	Objs::InsertObj(p, OBJ_SWITCHMAIN, 1);


}

//ゲームメイン実行メソッド
void CSceneSwitchMain::Scene()
{

}