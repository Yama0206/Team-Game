#include "Lure.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/Scene.h"

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
	isActive = false;
	// ルアーが画面の左半分にあるか
	isLureLeft = false;

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
	// 現在の座標
	_X = 0.0f;
	_Y = 0.0f;

	// 直前の座標
	_SaveX = 0.0f;
	_SaveY = 0.0f;

	// ルアーのマウス処理初期化
	LureMouse.Init();
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
	// マウスの動き
	LureMouse.Move();

	// 左クリックを押したなら
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT)) {
		_SaveX = (float)LureMouse.GetX();
		_SaveY = (float)LureMouse.GetY();
	}

	if (_SaveX < SCREEN_SIZE_X) {
		isLureLeft = true;
	}
	else {
		isLureLeft = false;
	}
}

// 移動処理
void Lure::Move()
{
	// ルアーをクリックしたところまで移動させる
	// クリックしたところまで動いたら止まる
	if ((isLureLeft && _X > _SaveX) ||
		(!isLureLeft && _X < _SaveX)) {
		_X += (_SaveX - SCREEN_SIZE_X) / 60;
	}
	else {
		_X = _SaveX;
	}

	if (_Y < _SaveY) {
		_Y += _SaveY / 60;
	}
	else if (_Y >= _SaveY) {
		_Y = _SaveY;
	}


}

// 通常処理
void Lure::Step()
{

}

// 画像描画
void Lure::Draw()
{
	DrawRotaGraph((int)_X, (int)_Y, 0.0f, handle, true, false);
}

// 終了処理
void Lure::Fin()
{
	// ルアーの画像削除
	DeleteGraph(handle);
}
