#include "Fish.h"
#include "../Scene/Scene.h"

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
		
		isLeft[FishIndex] = true; // 左を向いているかどうか
		isActive[FishIndex] = true; // 生きているかどうか
	}
}

// 座標更新用
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
		// 魚の移動処理
		if (isLeft[FishIndex]) {
			_SaveX[FishIndex] -= FISH_SPEED; // 左を向いているとき左に動く
		}
		else {
			_SaveX[FishIndex] += FISH_SPEED; // 右を向いているときに右に動く
		}

		// 魚が画面外に行ったとき
		if (_SaveX[FishIndex] > SCREEN_SIZE_X + FISH_X_SIZE / 2 ||
			_SaveX[FishIndex] < -FISH_X_SIZE / 2) {
			isActive[FishIndex] = false; // 魚を殺す
		}
	}
}

// 画像描画
void Fish::Draw()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		DrawRotaGraph(_X[FishIndex], _Y[FishIndex], 0.0f, handle[FishIndex], true, isLeft[FishIndex]);
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
