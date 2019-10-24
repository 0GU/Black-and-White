#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ギャラリー
class CSceneGallery :public CScene
{
public:
	CSceneGallery();
	~CSceneGallery();
	void InitScene();//ギャラリーの初期化メソッド
	void Scene();	 //ギャラリーの実行中メソッド
private:
};