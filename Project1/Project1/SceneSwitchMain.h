#pragma once
#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：Reversibleメイン
class CSceneSwitchMain :public CScene
{
public:
	CSceneSwitchMain() ;
	~CSceneSwitchMain() ;
	void InitScene();//Switchメインの初期化メソッド
	void Scene();	 //Switchメインの実行中メソッド
private:
};