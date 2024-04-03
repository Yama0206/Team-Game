#include "Play.h"


//プレイシーンの初期化
void Play::Init()
{
	//プレイヤーの初期化
	player.Init();

	//画像読み込み
	backgroundHandle = LoadGraph("data/play/backGround.png");	//背景
	jettyHandle = LoadGraph("data/play/jetty.png");	//桟橋

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイヤーシーンの通常処理
void Play::Step()
{
	player.Step();
}

//プレイヤーシーンの描画処理
void Play::Draw()
{
	//背景描画
	DrawGraph(0, 0, backgroundHandle, true);	//背景
	DrawGraph(0, 0, jettyHandle, true);	//桟橋

	player.Draw();
}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	player.Fin();
}
