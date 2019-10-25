#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームクリア
class CSceneGameClear :public CScene
{
public:
	CSceneGameClear();
	~CSceneGameClear();
	void InitScene();//モードセレクトの初期化メソッド
	void Scene();	 //モードセレクトの実行中メソッド
private:
};