#include "Fish.h"
#include "../Scene/Scene.h"

#include "DxLib.h"

Fish::Fish()
{
	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ハンドル
		handle[FishIndex] = 0;

		// 現在の座標
		_X[FishIndex] = 0.0f;
		_Y[FishIndex] = 0.0f;
		// 直前の座標
		_SaveX[FishIndex] = 0.0f;
		_SaveY[FishIndex] = 0.0f;

		//魚が出てくるまでの時間
		Poptime[FishIndex] = 0;
		
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
		_X[FishIndex] = 500.0f;
		_Y[FishIndex] = 500.0f;

		// 直前の座標
		_SaveX[FishIndex] = _X[FishIndex];
		_SaveY[FishIndex] = _Y[FishIndex];

		//魚が出てくるまでの時間
		Poptime[FishIndex] = 0;

		//左を向いているかどうか
		isLeft[FishIndex] = true;
	}
}

// 画像ロード
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// 魚の画像ロード
		handle[FishIndex] = LoadGraph(FISH_PATH);
	}
}

// 通常処理
void Fish::Step()
{
	//移動処理
	Move();

	//座標更新処理
	UpdatePos();
}

// 画像描画
void Fish::Draw()
{
	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		if (isActive[FishIndex]) {
			DrawRotaGraph((int)_X[FishIndex], (int)_Y[FishIndex], 1.0f, 0.0f, handle[FishIndex], true, isLeft[FishIndex]);
		}
	}
}

// 終了処理
void Fish::Fin()
{
	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// 魚の画像削除
		DeleteGraph(handle[FishIndex]);
	}
}

//移動処理
void Fish::Move()
{
	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// 魚の移動処理
		if (isLeft[FishIndex]) {
			_SaveX[FishIndex] -= FISH_SPEED; // 左を向いているとき左に動く
		}
		else {
			_SaveX[FishIndex] += FISH_SPEED; // 右を向いているときに右に動く
		}

		// 魚が画面外に行ったとき
		// 後で調整
		//if (_SaveX[FishIndex] > SCREEN_SIZE_X + FISH_X_SIZE / 2 ||
		//	_SaveX[FishIndex] < -FISH_X_SIZE / 2) {
		//	isActive[FishIndex] = false; // 魚を殺す
		//}
	}
}

//出現時間管理処理
void Fish::SetPopTime()
{
	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++)
	{
	
	}
}
