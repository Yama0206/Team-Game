#include "Play.h"


//プレイシーンの初期化
void Play::Init()
{
	//プレイヤーの初期化
	player.Init();

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
	player.Draw();
}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	player.Fin();
}
