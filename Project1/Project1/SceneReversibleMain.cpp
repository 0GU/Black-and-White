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
#include "SceneReversibleMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneReversibleMain::CSceneReversibleMain()
{

}

//デストラクタ
CSceneReversibleMain::~CSceneReversibleMain()
{

}

//ゲームメイン初期化メソッド
void CSceneReversibleMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"パズルパネル黒5×5用.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"パネル白(96x96).png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"白背景.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"ヒントボタン.png", 3, TEX_SIZE_512);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"ゲームメインBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//BGM再生
	float Volume = Audio::VolumeMaster(-0.3f);
	Audio::Start(0);

	CObjReversibleMain* p = new CObjReversibleMain();
	Objs::InsertObj(p, OBJ_REVERSIBLEMAIN, 1);

	CObjMouse* c = new CObjMouse();
	Objs::InsertObj(c, OBJ_MOUSE, 1);


}

//ゲームメイン実行メソッド
void CSceneReversibleMain::Scene()
{

}