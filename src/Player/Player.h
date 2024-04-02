#pragma once
#include "DxLib.h"

class Player
{
private:
	//プレイヤーの座標
	float posX, posY;
	//プレイヤー画像ハンドル
	int ImageHundle;
	
public:
	//X座標、Y座標を取得
	float GetPlayerPosX() { return posX; }
	float GetPlayerPosY() { return posY; }

	//プレイヤーの初期化
	void Init();

	//プレイヤーの通常処理
	void Step();

	//プレイヤー関連の描画処理
	void Draw();

	//プレイヤーの終了処理
	void Fin();

	//プレイヤー操作処理
	void Operation();
};
