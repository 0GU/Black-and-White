#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjReversibleMain.h"
#include"GameL/Audio.h"


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
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));
	hint = false;

}

//アクション
void CObjReversibleMain::Action()
{
	int sx=0, sy=0;
	int lx, ly;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();



	//当たり判定
	if (160<=x&&640>=x&&60<=y&&540>=y)
	{
		if ( Input::GetMouButtonL()== true)    //左クリック時パネルを反転させる
		{
			//SEを鳴らす
			Audio::Start(1);

			sx = (y - 60) / 96;   //クリック時のy座標を配列で使えるように直す
			sy = (x - 160) / 96;  //クリック時のx座標を配列で使えるように直す
			for (int m = 0; m < 5; m++)
			{
				switch (m)
				{
				case 0:
					lx = sx;
					ly = sy-1;
					break;
				case 1:
					lx = sx-1;
					ly = sy;
					break;
				case 2:
					lx = sx;
					ly = sy;
					break;
				case 3:
					lx = sx+1;
					ly = sy;
					break;
				case 4:
					lx = sx;
					ly = sy+1;
					break;
				}
				if(lx>=0&&ly>=0&& lx <= 4 && ly <= 4)
				{
					if (stage[lx][ly] == 0)
					{
						stage[lx][ly] = 1;
					}
					else if (stage[lx][ly] == 1)
					{
						stage[lx][ly] = 0;
					}
				}
			}
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}

	//リセットボタン当たり判定
	if (660 <= x && 780 >= x && 440 <= y && 550 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{
	
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//ヒントボタン当たり判定
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y)
	{
		if (Input::GetMouButtonL() == true)
		{

			hint = true;
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
}

//ドロー
void CObjReversibleMain::Draw()
{
	//描画カラー情報
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//テキスト用

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

	//ヒントボタン表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	dst.m_top = 250.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 120.0f;
	dst.m_bottom = dst.m_top + 100.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);


	//ヒントテキスト表示
	Font::StrDraw(L"Hint", 50, 250, 30, f);

	if (hint == true)
		Font::StrDraw(L"AAA", 20,280,30, f);

	//リセットボタン表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	dst.m_top = 440.0f;
	dst.m_left = 660.0f;
	dst.m_right = dst.m_left + 120.0f;
	dst.m_bottom = dst.m_top + 100.0f;
	Draw::Draw(4, &src, &dst, c, 0.0f);

}