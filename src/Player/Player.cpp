#include "Player.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

//プレイヤーの初期化
void Player::InitPlayer()
{
	//プレイヤーの座標の初期化
	posX = 10;
	posY = 10;

	//プレイヤーの画像ハンドルの初期化
	ImageHundle = -1;
}

//プレイヤーの通常処理
void Player::StepPlayer()
{

}

//プレイヤーの描画処理
void Player::DrawPlayer()
{
	DrawFormatString(40, 40, GetColor(255, 0, 0), "%d, %d", posX, posY);
}

//プレイヤーの終了処理
void Player::FinPlayer()
{

}

//プレイヤーの操作処理
void Player::PlayerOperation()
{

}
