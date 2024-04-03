#pragma once
#include "DxLib.h"

const char PLAYER_PATH[] = {"a"};		//プレイヤーの画像パス

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

	//プレイヤーの初期値設定
	void SetDefaultValue();

	//プレイヤーの読み込み処理
	void Load();

	//プレイヤーの通常処理
	void Step();

	//プレイヤー関連の描画処理
	void Draw();

	//プレイヤーの終了処理
	void Fin();

	//プレイヤー操作処理
	void Operation();
};
