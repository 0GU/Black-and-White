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
	//SE情報の登録
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);

	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	Audio::LoadAudio(3, L"Sound/くるみ割り人形ギャラリー.wav", SOUND_TYPE::BACK_MUSIC);


	Draw::LoadImage(L"まとめ画像/まとめ画像1.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"gallery仮枠.png",1,TEX_SIZE_512);

	CObjGallery* p = new CObjGallery();
	Objs::InsertObj(p, OBJ_GALLERY, 1);

	CObjMouse*m = new CObjMouse();
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮



	Audio::Start(3);

}

//ゲームタイトル実行メソッド
void CSceneGallery::Scene()
{

}