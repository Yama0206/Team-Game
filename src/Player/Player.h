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
	void InitPlayer();

	//プレイヤーの通常処理
	void StepPlayer();

	//プレイヤー関連の描画処理
	void DrawPlayer();

	//プレイヤーの終了処理
	void FinPlayer();

	//プレイヤー操作処理
	void PlayerOperation();
};
