#include "Play.h"
#include"../../TimeLimit/TimeLimit.h"

//画像パス
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//プレイシーンの背景画像のパス
const char JETTY_PATH[] = { "data/play/jetty.png" };					//プレイシーンの桟橋画像のパス

TimeLimit timeLimit;	//制限時間

//プレイシーンの初期化
void Play::Init()
{
	//プレイヤーの初期化
	player.Init();

	//制限時間の初期化
	timeLimit.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーンの初期値設定
void Play::SetDefaultValue()
{
	player.SetDefaultValue();
}

//プレイシーンの読み込み
void Play::Load()
{
	//画像読み込み
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//背景
	jettyHandle = LoadGraph(JETTY_PATH);	//桟橋

	player.Load();

}

//プレイヤーシーンの通常処理
void Play::Step()
{
	player.Step();

	//制限時間の通常処理
	timeLimit.Step();
}

//プレイヤーシーンの描画処理
void Play::Draw()
{
	//背景描画
	DrawGraph(0, 0, backgroundHandle, true);	//背景
	DrawGraph(0, 0, jettyHandle, true);	//桟橋

	//制限時間の描画
	timeLimit.Draw();

	player.Draw();
}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	player.Fin();

	//制限時間の終了処理
	timeLimit.Fin();
}
