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
#include "SceneGameSelect.h"
#include "ObjGameSelect.h"

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
	Draw::LoadImage(L"まとめ画像/haikei3.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/help1.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"まとめ画像/マウス、シーン、クリア（透過）.png", 10, TEX_SIZE_1024);

	//SE情報の登録
	Audio::LoadAudio(0, L"Sound/タイトル.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"Sound/SelectButton.wav", EFFECT);

	Audio::LoadAudio(2, L"Sound/BackButton.wav", EFFECT);

	CObjGameSelect* p = new CObjGameSelect();
	Objs::InsertObj(p, OBJ_GAMESELECT, 1);

	/*Draw::LoadImage(L"", 0, TEX_SIZE_512);

	CObjGameSelect* p = new CObjGameSelect();
	Objs::InsertObj(p, OBJ_GAMESELECT, 1);

	CObjMouse*m = new CObjMouse(back);
	Objs::InsertObj(m, OBJ_MOUSE, 2);//仮
	
	*/
	Audio::Start(0);
}

//ゲームタイトル実行メソッド
void CSceneGameSelect::Scene()
{

}