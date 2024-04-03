#include "Play.h"

const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//プレイシーンの背景画像のパス
const char JETTY_PATH[] = { "data/play/jetty.png" };					//プレイシーンの桟橋画像のパス


//プレイシーンの初期化
void Play::Init()
{
	//プレイヤーの初期化
	player.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーンの読み込み
void Play::Load()
{
	//画像読み込み
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//背景
	jettyHandle = LoadGraph(JETTY_PATH);	//桟橋

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
