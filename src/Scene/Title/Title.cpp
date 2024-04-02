#include"DxLib.h"
#include"../Title/Title.h"
#include"../../Scene/Scene.h"
#include"../../Input/Input.h"

int titleImageHandle;	//タイトル画像パス
SCENE_ID g_CurrentSceneID;	//シーン変数

//初期化
void TitleInit()
{
	//画像読み込み
	titleImageHandle = LoadGraph("data/title/kariTitle.png");
	//通常処理に移行
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//通常処理
void TitleStep()
{
	//左クリックで以下
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		//終了処理へ
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//描画
void TitleDraw()
{
	//拝啓描画
	DrawGraph(0, 0, titleImageHandle, true);
}

//終了処理
void TitleFin()
{
	//プレイ画面へ移行
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}