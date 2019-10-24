#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームセレクト
class CSceneGameSelect :public CScene
{
public:
	CSceneGameSelect();
	~CSceneGameSelect();
	void InitScene();//ゲームセレクトの初期化メソッド
	void Scene();	 //ゲームセレクトの実行中メソッド
private:
};