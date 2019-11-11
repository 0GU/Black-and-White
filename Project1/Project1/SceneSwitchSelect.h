#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージセレクト
class CSceneSwitchSelect :public CScene
{
public:
	CSceneSwitchSelect();
	~CSceneSwitchSelect();
	void InitScene();//ステージセレクトの初期化メソッド
	void Scene();	 //ステージセレクトの実行中メソッド
private:
};