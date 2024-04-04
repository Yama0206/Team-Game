#include "Play.h"

//画像パス
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//プレイシーンの背景画像のパス
const char JETTY_PATH[] = { "data/play/jetty.png" };					//プレイシーンの桟橋画像のパス

TimeLimit timeLimit;	//時間制限

//プレイシーンの初期化
void Play::Init()
{
	player.Init();		//プレイヤーの初期化
	fish.Init();		//フィッシュの初期化

	lure.Init();

	//制限時間の初期化
	timeLimit.Init();

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
	
	//プレイヤー関連
	player.Load();									//プレイヤー画像の読み込み
	fish.Load();									//フィッシュの画像の読み込み
	lure.Load();
}

//プレイヤーシーンの通常処理
void Play::Step()
{
	player.Step();			//プレイヤーの通常処理
	fish.Step();			//フィッシュの通常処理

	//制限時間の通常処理
	timeLimit.Step();
	lure.Step();
}

//プレイヤーシーンの描画処理
void Play::Draw()
{
	//背景描画
	DrawGraph(0, 0, backgroundHandle, true);	//背景
	DrawGraph(0, 0, jettyHandle, true);	//桟橋

	//制限時間の描画
	timeLimit.Draw();

	fish.Draw();		//フィッシュ画像の描画

	lure.Draw();

	
	player.Draw();		//プレイヤー画像の描画
}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	lure.Fin();

	player.Fin();		//プレイヤーの終了処理
	fish.Fin();			//フィッシュの終了処理

	//制限時間の終了処理
	timeLimit.Fin();

	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
