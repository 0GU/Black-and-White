//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

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
	//CObjModeSelect* p = new CObjModeSelect();
	//Objs::InsertObj(p, OBJ_MODESELECT, 1);
}

//ゲームタイトル実行メソッド
void CSceneModeSelect::Scene()
{

}