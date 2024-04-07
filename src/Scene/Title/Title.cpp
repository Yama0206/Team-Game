#include"DxLib.h"
#include"../Title/Title.h"
#include"../../Scene/Scene.h"
#include"../../Input/Input.h"
#include"../../FrameRate/FrameRate.h"

SCENE_ID g_CurrentSceneID;	//シーン変数

//初期化
void Title::Init()
{
	//画像読み込み
	for (int i = 0; i < TITLE_IMAGE_MAX_NUM; i++)
	{
		imageHandle[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
	}

	seaY = 200;
	jettyY = 200;

	titleY =  - 100;

	for (int i = 0; i < 4; i++)
	{
		cloudX[i][0] = 0;
		cloudX[i][1] = SCREEN_SIZE_X;
	}
	cloudY = -20;

	fade[0] = 0;
	fade[1] = 0;
	lighting = true;
	progress = 0;
	countTime = 0;

	//通常処理に移行
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//通常処理
void Title::Step()
{
	switch (progress)
	{
	case 0:
		countTime += 1.0f / FRAME_RATE;

			countTime = 0;
			progress++;

		break;

	case 1:
		if (seaY <= 0)
		{
			seaY = 0;
		}
		else
		{
			seaY -= 1.4f;
		}

		if (jettyY <= 0)
		{
			jettyY = 0;
		}
		else
		{
			jettyY -= 1.2f;
		}

		if (fade[0] >= 255)
		{
			fade[0] = 255;
		}
		else
		{
			fade[0] += 1;
		}

		if (titleY >= 0)
		{
			titleY = 0;
		}
		else
		{
			titleY += 0.5f;
		}

		if (seaY == 0 && jettyY == 0 && titleY == 0 && fade[0])
		{
			progress++;
		}

		break;

	case 2:

		if (lighting)
		{
			fade[1] += 5;

			if (fade[1] >= 255)
			{
				lighting = false;
			}
		}
		else
		{
			fade[1] -= 5;

			if (fade[1] <= 0)
			{
				lighting = true;
			}
		}

		//左クリックで以下
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
		{
			//終了処理へ
			g_CurrentSceneID = SCENE_ID_FIN_TITLE;
		}

		break;


	default:
		break;
	}

	for (int i = 0; i < 2; i++)
	{
		cloudX[0][i] -= 0.3;
		cloudX[1][i] -= 0.5;
		cloudX[2][i] -= 0.4;
		cloudX[3][i] -= 0.1;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; i < 2; i++)
		{
			if (cloudX[i][n] <= -SCREEN_SIZE_X)
			{
				cloudX[i][n] = SCREEN_SIZE_X;
			}
		}
	}
	
}

//描画
void Title::Draw()
{
	DrawGraphF(0, 0, imageHandle[TITLE_SKY], true);
	DrawGraphF(0, seaY, imageHandle[TITLE_SEA], true);
	DrawGraphF(0, jettyY, imageHandle[TITLE_JETTY], true);

	for (int i = 0; i < 4; i++)
	{
		DrawGraphF(cloudX[i][0], cloudY, imageHandle[TITLE_CLOUD1 + i], true);
		DrawGraphF(cloudX[i][1], cloudY, imageHandle[TITLE_CLOUD1 + i], true);
	}

	//
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade[0]);
	DrawGraphF(0, titleY, imageHandle[TITLE_TITLE], true);
	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade[1]);
	DrawGraphF(0, 0, imageHandle[TITLE_START], true);
	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//終了処理
void Title::Fin()
{
	//プレイ画面へ移行
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}