#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjSwitchMain.h"
#include "GameL\Audio.h"
#include "UtilityModule.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSwitchMain::Init()
{


	StageSlect = -1;
	for (int i = 0; i < 3; i++)
	{
		((UserData*)Save::GetData())->SPStageSelect[i] = false;
	}

	Save::Open();

	for (int i = 0; i < 3; i++)
	{
		if (((UserData*)Save::GetData())->SPStageSelect[i] == true)
		{
			StageSlect = i;
		}
	}


	int stage_data[5][5] = {};

	LoadSPStage(StageSlect, *stage_data);
	LoadSPCount(StageSlect, count);
	count[0] = count[1] - count[0];
	//マップデータをコピー
	memcpy(stage, stage_data, sizeof(int)*(5 * 5));
	memcpy(stage_reset, stage_data, sizeof(int)*(5 * 5));

	bool flag_set[6] =
	{ false,false,false,false,false,false};
	memcpy(flag, flag_set, sizeof(bool)*(5));
	
	m_ani_flame = 0;
	m_time = 0;
	m_change = true;
	sx = 0;
	sy = 0;
	r = 0.0f;
}

//アクション
void CObjSwitchMain::Action()
{
	int lx = 0;
	int ly = 0;
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();


	//当たり判定
	if (160 <= x && 640 >= x && 60 <= y && 540 >= y && ((((int)(y - 60) / 96) % 2 == 0 && ((int)(x - 160) / 96) % 2 == 1) || (((int)(y - 60) / 96) % 2 == 1 && ((int)(x - 160) / 96) % 2 == 0)) && flag[1] == false && flag[2] == false&& flag[3] == false)
	{
		if (m_change == true)
		{

			if (Input::GetMouButtonL() == true)    //左クリック時パネルを反転させる
			{
				m_change = false;	//反転中はほかのパネルを反転できないようにする

				//SEを鳴らす
				Audio::Start(1);

				//Countを減らす
				count[1]--;

				sy = (int)(y - 60) / 96;   //クリック時のy座標を配列で使えるように直す
				sx = (int)(x - 160) / 96;  //クリック時のx座標を配列で使えるように直す
				for (int m = 0; m < 2; m++)
				{
					switch (stage[sy][sx])
					{
					case 2:
						switch (m)
						{
						case 0://左
							ly = sy;
							lx = sx - 1;
							break;
						case 1://右
							ly = sy;
							lx = sx + 1;
							break;
						}
						break;
					case 3:
						switch (m)
						{
							/*case 0://左
								ly = sy;
								lx = sx - 1;
								break;*/
						case 0://上
							ly = sy - 1;
							lx = sx;
							break;

						case 1://下
							ly = sy + 1;
							lx = sx;
							break;
							/*case 4://右
								ly = sy;
								lx = sx + 1;
								break;*/
						}
						break;
					}
					if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)//判定の正常化
					{
						if (stage[ly][lx] == 0)
						{
							stage[ly][lx] = 4;
						}
						else if (stage[ly][lx] == 1)
						{
							stage[ly][lx] = 5;
						}
					}

				}
				while (Input::GetMouButtonL() == true)
				{

				}


			}
		}
	}

	time_flag = true;

	for (int m = 0; m < 2; m++)
	{
		switch (stage[sy][sx])
		{
		case 2:
			switch (m)
			{
			case 0://左
				ly = sy;
				lx = sx - 1;
				break;
			case 1://右
				ly = sy;
				lx = sx + 1;
				break;
			}
			break;
		case 3:
			switch (m)
			{
				/*case 0://左
					ly = sy;
					lx = sx - 1;
					break;*/
			case 0://上
				ly = sy - 1;
				lx = sx;
				break;

			case 1://下
				ly = sy + 1;
				lx = sx;
				break;
				/*case 4://右
					ly = sy;
					lx = sx + 1;
					break;*/
			}
			break;
		}
		if (lx >= 0 && ly >= 0 && lx <= 4 && ly <= 4)
		{
			if (stage[ly][lx] == 4)
			{
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				if (m_time == 3) {
					m_ani_flame++;
					m_time = 0;
				}

				if (m_ani_flame == 3)
				{
					stage[ly][lx] = 1;
				}

			}
			if (stage[ly][lx] == 5)
			{
				if (time_flag == true)
				{
					m_time++;
					time_flag = false;
				}
				if (m_time == 3) {
					m_ani_flame++;
					m_time = 0;
				}if (m_ani_flame == 3)
				{
					stage[ly][lx] = 0;
				}

			}

		}

	}
	if (m_ani_flame == 3)
	{
		m_ani_flame = 0;
		m_change = true;

			if (SwitchClearCheck(stage) == true)
			{
				//パーフェクト条件を満たしている
				if (count[2] - count[0] == count[1])
				{
					flag[4] = true;
					Audio::Start(4);
				}
				flag[1] = true;
				Audio::Start(3);
			}
			else if (SwitchClearCheck(stage) == false && count[1] == 0)
			{
				flag[2] = true;
				Audio::Start(2);
			}
			

	}

	//GameClear時の判定
	if (flag[1] == true)
	{
		//BGM停止
		Audio::Stop(0);

		//StageSELECTへ戻るボタン判定
		if (x >= 130 && x <= 690 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{

				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());

			}
		}
	}
	//GameOver時の判定
	if (flag[2] == true)
	{

		
		//BGM停止
		Audio::Stop(0);



		//Yesボタン判定
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				count[1] = 12;
				memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
				//BGM停止
				Audio::Start(0);
				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{
					
				}
				flag[2] = false;
				Audio::Start(0);
			}
			
		}
		//Noボタン判定
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{

				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
				flag[2] = false;
			}
		}
	}

	//リセットボタン当たり判定
	if (650 <= x && 770 >= x && 430 <= y && 530 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			count[1] = 12;
			memcpy(stage, stage_reset, sizeof(int)*(5 * 5));
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}

		}
	}

	//ヒントボタン当たり判定
	if (650 <= x && 770 >= x && 250 <= y && 350 >= y && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{

			flag[0] = true;
			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
	//StageSelectへ戻るボタン判定------------------------------------------------------------
	if (x >= 30 && x <= 130 && y >= 60 && y <= 160 && flag[1] == false && flag[2] == false)
	{
		if (Input::GetMouButtonL() == true)
		{
			flag[3] = true;

			//SEを鳴らす
			Audio::Start(1);
			while (Input::GetMouButtonL() == true)
			{

			}
		}
	}
	if (flag[3] == true)
	{
		//Yesボタン判定
		if (x >= 130 && x <= 370 && y >= 370 && y <= 490)
		{
			if (Input::GetMouButtonL() == true)
			{
				//SEを鳴らす
				Audio::Stop(1);
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}
				Scene::SetScene(new CSceneSwitchSelect());
			}
		}
		//Noボタン判定
		if (x >= 410 && x <= 650 && y >= 370 && y <= 490)
		{

			if (Input::GetMouButtonL() == true)
			{

				//SEを鳴らす
				Audio::Start(1);
				while (Input::GetMouButtonL() == true)
				{

				}

				flag[3] = false;
			}
		}
	}

}

//ドロー
void CObjSwitchMain::Draw()
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


	//stageの描画
	float cc[4] = { 0.0f,0.0f,0.0f,1.0f };

	if (flag[1]==true&&count[1] == count[0])
	{
		flag[6] = true;
	}

	switch (StageSlect)
	{
		case 0:
			Font::StrDraw(L"STAGE1", 30, 470, 36, f);
			break;
		case 1:
			Font::StrDraw(L"STAGE2", 30, 470, 36, f);
			break;
		case 2:
			Font::StrDraw(L"STAGE3", 30, 470, 36, f);
			break;

	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//上下左右でアニメーションの角度を変えるやつ
			if (sy == i - 1 && sx == j)
			{
				r = 90.0f;
			}
			else if (sy == i && sx == j - 1)
			{
				r = 180.0f;
			}
			else if (sy == i + 1 && sx == j)
			{
				r = 270.0f;
			}
			else if (sy == i && sx == j + 1 )
			{
				r = 0.0f;
			}

			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 96.0f;
			src.m_bottom = 96.0f;

			//表示位置の設定
			dst.m_top = i * 96.0f + 60.0f;
			dst.m_left = j * 96.0f + 160.0f;
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
			else if (stage[i][j] == 3)
			{
				//縦スイッチ
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 2)
			{
				//横スイッチ
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			else if (stage[i][j] == 4)
			{
				//黒パネル
				src.m_top = 0.0f;
				src.m_left = 0.0f + (m_ani_flame * 96.0f);
				src.m_right = src.m_left + 96.0f;
				src.m_bottom = 96.0f;

				Draw::Draw(8, &src, &dst, c, r);
			}
			else if (stage[i][j] == 5)
			{
				//黒パネル
				src.m_top = 96.0f;
				src.m_left = 0.0f + (m_ani_flame * 96.0f);
				src.m_right = src.m_left + 96.0f;
				src.m_bottom = src.m_top + 96.0f;

				Draw::Draw(8, &src, &dst, c, r);
			}
		}
	}
	//ヒントボタン-----------------------------------------------
	//切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	//表示
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = 250.0f;
	dst.m_left = 660.0f;
	dst.m_right = 780.0;
	dst.m_bottom = 350.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//ヒントの表示
	if (flag[0] == true)
	{
		Font::StrDraw(L"最短手数", 20, 200, 32, f);
		Font::StrDraw(L"6手", 40, 260, 32, f);

	}

	//リセットボタン--------------------------------------------
	//切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 120.0f;
	src.m_bottom = 100.0f;
	//表示
	//プログラムの問題でx値y値10fずらしています
	dst.m_top = 440.0f;
	dst.m_left = 660.0f;
	dst.m_right = 780.0f;
	dst.m_bottom = 540.0f;
	Draw::Draw(4, &src, &dst, c, 0.0f);

	//StageSelectボタン-----------------------------------------------
	//切り取り
	src.m_top = 820.0f;
	src.m_left = 478.0f;
	src.m_right = 600.0f;
	src.m_bottom = 920.0f;
	//表示
	//プログラムの問題でx値を10fずらしてます
	dst.m_top = 60.0f;
	dst.m_left = 30.0f;
	dst.m_right = 130.0;
	dst.m_bottom = 160.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);


	Font::StrDraw(L"Count", 675, 45, 32, f);

	//Countの値を文字列化---------------------------------------
	wchar_t str[128];
	swprintf_s(str, L"%d", count[1]);

	if (count[1] >= 10)
		Font::StrDraw(str, 700, 80, 32, f);
	else if (count[1] <= 9)
		Font::StrDraw(str, 710, 80, 32, f);
	//シーン描画：PerFect!------------------------------------
	if (flag[6] == true)
	{
		//ステージ選択に戻る
		src.m_top = 490.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 610.0f;
		dst.m_top = 370.0f;
		dst.m_left = 130.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 490.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//PerFect!
		src.m_top = 370.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 491.0f;
		dst.m_top = 150.0f;
		dst.m_left = 100.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 300.0;
		Draw::Draw(5, &src, &dst, c, 30.0f);

	}
	//GameClear------------------------------------------
	else if (flag[1] == true)
	{
		//Game Clear!!
		src.m_top = 249.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 372.0f;
		dst.m_top = 150.0f;
		dst.m_left = 130.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 270.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);

		//ステージ選択に戻る
		src.m_top = 490.0f;
		src.m_left = 0.0f;
		src.m_right = 560.0f;
		src.m_bottom = 610.0f;
		dst.m_top = 370.0f;
		dst.m_left = 130.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 490.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}

	//GameOver------------------------------------
	if (flag[2] == true)
	{
		//GameOver表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 580.0f;
		src.m_bottom = 250.0f;
		dst.m_top = 70.0f;
		dst.m_left = 110.0f;
		dst.m_right = 690.0;
		dst.m_bottom = 320.0;
		Draw::Draw(5, &src, &dst, c, 0.0f);
	}
		//Yes・Noボタンの描画
		if (flag[2] == true || flag[3] == true)
		{
			src.m_top = 820.0f;
			src.m_left = 0.0f;
			src.m_right = 240.0f;
			src.m_bottom = 940.0f;
			dst.m_top = 370.0f;
			dst.m_left = 130.0f;
			dst.m_right = 370.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);

			src.m_top = 820.0f;
			src.m_left = 239.0f;
			src.m_right = 480.0f;
			src.m_bottom = 940.0f;
			dst.m_top = 370.0f;
			dst.m_left = 410.0f;
			dst.m_right = 650.0;
			dst.m_bottom = 490.0;
			Draw::Draw(5, &src, &dst, c, 0.0f);
		}

	

}