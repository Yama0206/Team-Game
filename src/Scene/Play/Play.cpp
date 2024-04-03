#include "Play.h"

//画像パス
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//プレイシーンの背景画像のパス
const char JETTY_PATH[] = { "data/play/jetty.png" };					//プレイシーンの桟橋画像のパス


//プレイシーンの初期化
void Play::Init()
{
	//プレイヤーの初期化
	player.Init();
	

	//プレイシーンの通常処理に遷移
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーンの初期値設定
void Play::SetDefaultValue()
{
	//プレイヤーの初期値設定
	player.SetDefaultValue();
}

//プレイシーンの読み込み
void Play::Load()
{
	//画像読み込み
	//背景関連
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//背景
	jettyHandle = LoadGraph(JETTY_PATH);			//桟橋
	
	//プレイヤー画像の読み込み
	player.Load();									

}

//プレイヤーシーンの通常処理
void Play::Step()
{
	//プレイヤーの通常処理
	player.Step();
}

//プレイヤーシーンの描画処理
void Play::Draw()
{
	//背景描画
	DrawGraph(0, 0, backgroundHandle, true);	//背景
	DrawGraph(0, 0, jettyHandle, true);	//桟橋

	//プレイヤー画像の描画
	player.Draw();
}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	//プレイヤーの終了処理
	player.Fin();

	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
