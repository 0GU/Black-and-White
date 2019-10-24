#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：モードセレクト
class CSceneModeSelect :public CScene
{
public:
	CSceneModeSelect();
	~CSceneModeSelect();
	void InitScene();//モードセレクトの初期化メソッド
	void Scene();	 //モードセレクトの実行中メソッド
private:
};