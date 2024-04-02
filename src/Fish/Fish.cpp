#include "Fish.h"

Fish::Fish()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;

		// 現在の座標
		_x[FishIndex] = 0.0f;
		_y[FishIndex] = 0.0f;

		// 直前の座標
		_savex[FishIndex] = 0.0f;
		_savey[FishIndex] = 0.0f;
		
		// 右を向いているかどうか
		isLeft[FishIndex] = true;
	}
}

// 初期化
void Fish::Init()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;

		// 現在の座標
		_x[FishIndex] = 0.0f;
		_y[FishIndex] = 0.0f;

		// 直前の座標
		_savex[FishIndex] = 0.0f;
		_savey[FishIndex] = 0.0f;

		// 右を向いているかどうか
		isLeft[FishIndex] = true;
	}
}

// 画像ロード
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;
	}
}

// 通常処理
void Fish::Step()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		if (isLeft[FishIndex]) {

		}
	}
}

// 終了処理
void Fish::Fin()
{
}
