#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージセレクト
class CSceneStageSelect :public CScene
{
	public:
		CSceneStageSelect();
		~CSceneStageSelect();
		void InitScene();//ステージセレクトの初期化メソッド
		void Scene();	 //ステージセレクトの実行中メソッド
	private:
};