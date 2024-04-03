#include "Player.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

//プレイヤーの初期化
void Player::Init()
{
	//プレイヤーの座標の初期化
	posX = 0;		//X座標
	posY = 0;		//Y座標

	//プレイヤーの画像ハンドルの初期化
	ImageHundle = -1;
}

//プレイヤーの読み込み処理
void Player::Load()
{
	ImageHundle = LoadGraph(PLAYER_PATH);
}

void Player::SetDefaultValue()
{
	//プレイヤーの座標の初期化
	posX = 0;		//X座標
	posY = 0;		//Y座標
}

//プレイヤーの通常処理
void Player::Step()
{

}

//プレイヤーの描画処理
void Player::Draw()
{
	DrawFormatString(40, 40, GetColor(255, 0, 0), "%d, %d", posX, posY);
}

//プレイヤーの終了処理
void Player::Fin()
{

}

//プレイヤーの操作処理
void Player::Operation()
{

}
