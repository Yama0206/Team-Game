#include "Fish.h"
#include "../Scene/Scene.h"
#include "../FrameRate/FrameRate.h"

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
		
		isLeft[FishIndex] = true; // 左を向いているかどうか
		isActive[FishIndex] = false; // 生きているかどうか
	}

	//魚が出てくるまでの時間
	Poptime = 0;
	countTime = 0;
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

		//左を向いているかどうか
		if (GetRand(1) == 0)
		{
			isLeft[FishIndex] = true;
		}
		else
		{
			isLeft[FishIndex] = false;
		}
		
	}

	//魚が出てくるまでの時間
	Poptime = 0;
	countTime = 0;
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

	//出現処理
	Pop();

	//座標更新処理
	//UpdatePos();
}

// 画像描画
void Fish::Draw()
{
	//60%で描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)255 * 0.6);

	//魚の最大数までfor分を回す
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) 
	{
		//魚が使用中なら描画
		if (isActive[FishIndex])
		{
			DrawRotaGraph((int)_X[FishIndex], (int)_Y[FishIndex],
						1.0f, 0.0f, handle[FishIndex], true, isLeft[FishIndex]);
		}

		//DrawFormatString(30, 30, GetColor(255, 0, 0), "%d", Poptime);
	}

	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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

		if (isActive[FishIndex])
		{
			// 魚の移動処理
			if (isLeft[FishIndex]) {
				_X[FishIndex] -= fishSpeed[FishIndex]; // 左を向いているとき左に動く
			}
			else {
				_X[FishIndex] += fishSpeed[FishIndex]; // 右を向いているときに右に動く
			}
		}

		// 魚が画面外に行ったとき
		//→
		if (isLeft[FishIndex])
		{
			if (_X[FishIndex] > SCREEN_SIZE_X + FISH_X_SIZE / 2)
			{
				isActive[FishIndex] = false; // 魚を殺す
			}
		}
		//←
		else
		{
			if (_X[FishIndex] < -FISH_X_SIZE / 2)
			{
				isActive[FishIndex] = false; // 魚を殺す
			}
		}
		
	}
}

//出現時間管理処理
void Fish::SetPopTime()
{
	//魚の最大数までfor分を回す
	/*for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++)
	{
		if (FishIndex <= 4) {
			Poptime[FishIndex] = GetRand(10);
		}
	}*/

	countTime += 1.0f / FRAME_RATE;	//時間をカウント
}

//魚出現
void Fish::Pop()
{
	//出現時間管理処理
	SetPopTime();

	//カウントが出現時間を越えたら
	if (countTime > Poptime)
	{
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++)
		{
			//使用されてなかったら以下実行
			if (!isActive[FishIndex])
			{
				//左を向いているかどうか　ランダムで決定
				//←
				if (GetRand(1) == 0)
				{
					isLeft[FishIndex] = true;
				}
				//→
				else
				{
					isLeft[FishIndex] = false;
				}

				//左右から位置を設定
				if (isLeft[FishIndex])
				{
					//右端に設定
					_X[FishIndex] = SCREEN_SIZE_X+ FISH_X_SIZE/2;
					_Y[FishIndex] = GetRand(SCREEN_SIZE_Y - 145 - 30) + 30;
				}
				else
				{
					//左端に設定
					_X[FishIndex] = 0 - FISH_X_SIZE / 2;
					_Y[FishIndex] = GetRand(SCREEN_SIZE_Y - 145 - 30) + 30;
				}

				//魚を使用中にする
				isActive[FishIndex] = true;

				//魚のスピードを設定
				fishSpeed[FishIndex] = GetRand(FISH_SPEED - 1) + 1;

				//次の出現時間を設定
				Poptime = GetRand(FISH_POP_TIME) + 1;
				//カウントをリセット
				countTime = 0;

				break;
			}
		}
	}
}