#include"DxLib.h"
#include"../Title/Title.h"
#include"../../Scene/Scene.h"
#include"../../Input/Input.h"

int resultImageHandle=0;	//リザルト画像パス

//初期化
void ResultInit()
{
	//画像読み込み
	resultImageHandle = LoadGraph("data/result/result.png");
	//通常処理に移行
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}

//通常処理
void ResultStep()
{
	//左クリックで以下
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		//終了処理へ
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

//描画
void ResultDraw()
{
	//背景描画
	DrawGraph(0, 0, resultImageHandle, true);
}

//終了処理
void ResultFin()
{
	//プレイ画面へ移行
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}