#pragma once
#include "DxLib.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = {"data/play/player.png"};		//プレイヤーの画像パス

const int PLAYER_WIDE = 47;									//プレイヤー画像の横幅
const int PLAYER_HIGHT = 122;								//プレイヤー画像の縦幅
const float PLAYER_RAD = 23.5;								//プレイヤー画像の半径

class Player
{
private:
	
	float posX, posY;		//プレイヤーの座標
	int ImageHundle;		//プレイヤー画像ハンドル

	
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
