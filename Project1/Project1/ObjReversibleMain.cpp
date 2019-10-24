#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjReversibleMain.h"
#include "ObjMouse.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjReversibleMain::Init()
{
	int stage_data[5][5] =
	{
		{0,1,1,0,1},
		{1,0,1,1,0},
		{1,1,0,1,0},
		{1,0,0,0,1},
		{0,1,1,1,1},
	};
	//マップデータをコピー
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
}

//アクション
void CObjReversibleMain::Action()
{
	//x = MousePosX;
	//y = MousePosY;
	if (160<=x&&640>=x&&60<=y&&540>=y)
	{
		
	}
}

//ドロー
void CObjReversibleMain::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置の設定
	RECT_F dst; //描画先表示位置

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 96.0f;
	src.m_bottom = 96.0f;


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
				//表示位置の設定
				dst.m_top = i * 96.0f+60.0f;
				dst.m_left = j * 96.0f+160.0f;
				dst.m_right = dst.m_left + 96.0;
				dst.m_bottom = dst.m_top + 96.0;
				if (stage[i][j] == 0)
				{
					//白パネル
					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				else if (stage[i][j] == 1)
				{
					//黒パネル
					Draw::Draw(0, &src, &dst, c, 0.0f);
				}
			
		}
	}
}