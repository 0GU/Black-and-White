//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{

}

//アクション
void CObjTitle::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();
	if (0 <= x && 800 >= x && 0 <= y && 600 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneModeSelect());
			}
		}
		
	}
}

//ドロー
void CObjTitle::Draw()
{
	
}