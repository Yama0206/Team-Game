#pragma once
#include "../../Scene/Scene.h"
#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Mouse/Mouse.h"

class Play
{
private:
	Player player;
public:
	//プレイシーンの初期化
	void Init();

	//プレイシーンの通常処理
	void Step();

	//プレイシーンの描画処理
	void Draw();

	//プレイシーンの終了処理
	void Fin();
};
