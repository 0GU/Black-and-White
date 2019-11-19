#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：Reversibleメイン
class CSceneReversibleMain :public CScene
{
public:
	CSceneReversibleMain(int stage);
	~CSceneReversibleMain();
	 int SetStage();
	void InitScene();//Reversibleメインの初期化メソッド
	void Scene();	 //Reversibleメインの実行中メソッド
private:
	 int stagenum;
	
};