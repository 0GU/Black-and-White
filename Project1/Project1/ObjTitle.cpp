//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{

}

//�A�N�V����
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
				//SE��炷
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneModeSelect());
			}
		}
		
	}
}

//�h���[
void CObjTitle::Draw()
{
	
}