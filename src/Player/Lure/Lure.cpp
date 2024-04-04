#include "Lure.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/Scene.h"
#include "../../MathPlus/MathPlus.h"

// コンストラクタ
Lure::Lure()
{
	// ルアー画像ハンドル
	handle = -1;
	// 現在の座標
	_X = 0.0f;
	_Y = 0.0f;
	// 移動後の座標
	_SaveX = 0.0f;
	_SaveY = 0.0f;

	// 使用中かどうか
	isActive = true;

	//ルアーを投げたら
	isUse = false;
	// ルアーを投げているか
	isThrow = false;
	// ルアーが画面の左半分にあるか
	isLureLeft = false;

	fade = -1; //透明度

	// ルアーのマウス
	LureMouse = {};
}

// 座標更新用
void Lure::UpdatePos()
{
	_X = _SaveX;
	_Y = _SaveY;
}

// 初期化
void Lure::Init()
{ 
	// 使用中かどうか
	isActive = false;
	//ルアーを投げたら
	isUse = false;
	// ルアーを投げているか
	isThrow = false;

	// 現在の座標
	_X = LURE_POS_X;
	_Y = LURE_POS_Y;

	// 直前の座標
	_SaveX = _X;
	_SaveY = _Y;

	// ルアーのマウス処理初期化
	LureMouse.Init();

	//透明度
	fade = 255;
}

// 画像ロード
void Lure::Load()
{
	// ルアーの画像ロード
	handle = LoadGraph(LURE_PATH);
}

// マウス処理
void Lure::Mouse()
{
	//ルアーが投げられていなかったら
	if (!isUse)
	{
		int zX = 0, zY = 0;	//一時保存用の座標

		// マウスの位置を取得
		GetMousePoint(&zX, &zY);

		//左クリックを押された かつ 投げている途中じゃない
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT) && !isThrow)
		{
			//ルアー設置範囲内なら以下実行
			if (zX >= 30 && zX <= SCREEN_SIZE_X - 30 &&
				zY >= 30 && zY <= SCREEN_SIZE_Y - 145)
			{
				//クリックした位置にルアーを表示
				_SaveX = (float)zX;
				_SaveY = (float)zY;

				// 投げている判定にする
				isThrow = true;

				// 投げられた位置が画面の左半分かどうか
				if (_SaveX < LURE_POS_X) {
					isLureLeft = true;
				}
				else {
					isLureLeft = false;
				}

				//isActive = true;
			}
		}
	}
}

// 移動処理
void Lure::Move()
{
	// ルアーを投げたなら
	if (isThrow) {
		// ルアーをクリックしたところまでゆっくり移動させる
		_X += GetDirection(_SaveX, _SaveY, _X, _Y, 'x', 6);
		_Y += GetDirection(_SaveX, _SaveY, _X, _Y, 'y', 6);

		// クリックしたところまで動いたら止まる
		if ((isLureLeft && _X <= _SaveX) ||
			(!isLureLeft && _X >= _SaveX)) {
			_X = _SaveX; // クリックしたところまで動いたら止まる
		}

		if (_Y < _SaveY) {
			_Y = _SaveY; // クリックしたところまで動いたら止まる
		}

		// クリックしたところまで移動したら
		if (_X == _SaveX && _Y == _SaveY) {
			// 投げていない
			isThrow = false;

			// 使用中にする
			isUse = true;
		}
	}

	//ルアーを投げれたら
	if (isUse)
	{
		//左クリックが押し続けられていたら
		if (Input::Mouse::Keep(MOUSE_INPUT_LEFT))
		{
			//初期値に向かって進行
			_X += GetDirection(LURE_POS_X, LURE_POS_Y, _X, _Y, 'x', 2);
			_Y += GetDirection(LURE_POS_X, LURE_POS_Y, _X, _Y, 'y', 2);

			//初期値の範囲、20以内に入ったら
			if (GetDistance(LURE_POS_X, LURE_POS_Y, _X, _Y) <= 20)
			{
				//初期値を代入
				_X = LURE_POS_X;
				_Y = LURE_POS_Y;

				//使用フラグを折る
				isUse = false;
				
				//isActive = false;
			}
		}
	}
}

// 通常処理
void Lure::Step()
{
	//ルアー投げる処理
	Mouse();
	//巻き取り
	Move();
}

// 画像描画
void Lure::Draw()
{

	//デバック用　ルアーの範囲
	DrawBox(30, 30, SCREEN_SIZE_X - 30, SCREEN_SIZE_Y - 145, GetColor(0, 0, 255), false);

	/*if (isActive) {*/

	//透明度変更
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	DrawRotaGraph((int)_X, (int)_Y, 1.0f, 0.0f, handle, true, false);
	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//DrawRotaGraph(500, 500, 1.0f, 0.0f, handle, true, false);
	//}
	
	//釣り糸
	DrawLine((int)_X, (int)_Y, (int)(LURE_POS_X - 2), (int)(LURE_POS_Y - 5), GetColor(255, 255, 255));
}

// 終了処理
void Lure::Fin()
{
	// ルアーの画像削除
	DeleteGraph(handle);
}
