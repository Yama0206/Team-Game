#include "Fish.h"
#include "DxLib.h"

Fish::Fish()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;

		// 現在の座標
		_X[FishIndex] = 0.0f;
		_Y[FishIndex] = 0.0f;

		// 直前の座標
		_SaveX[FishIndex] = 0.0f;
		_SaveY[FishIndex] = 0.0f;
		
		// 右を向いているかどうか
		isLeft[FishIndex] = true;
	}
}

void Fish::UpdatePos()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) 
	{
		_X[FishIndex] = _SaveX[FishIndex];
		_Y[FishIndex] = _SaveY[FishIndex];
	}

}

// 初期化
void Fish::Init()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;

		// 現在の座標
		_X[FishIndex] = 0.0f;
		_Y[FishIndex] = 0.0f;

		// 直前の座標
		_SaveX[FishIndex] = 0.0f;
		_SaveY[FishIndex] = 0.0f;

		// 右を向いているかどうか
		isLeft[FishIndex] = true;
	}
}

// 画像ロード
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// 魚の画像ロード
		handle[FishIndex] = LoadGraph(FISH_PATH[FishIndex]);
	}
}

// 通常処理
void Fish::Step()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		if (isLeft[FishIndex]) {
			_SaveX[FishIndex] -= FISH_SPEED;
		}
		else {
			_SaveX[FishIndex] += FISH_SPEED;
		}
	}
}

// 終了処理
void Fish::Fin()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// 魚の画像削除
		DeleteGraph(handle[FishIndex]);
	}
}
