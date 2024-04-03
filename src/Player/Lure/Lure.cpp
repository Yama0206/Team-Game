#include "Lure.h"
#include "DxLib.h"
#include "../../Mouse/Mouse.h"
#include "../../Input/Input.h"

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
	//LureMouse.Init();
}

// 画像ロード
void Lure::Load()
{
	// ルアーの画像ロード
	handle = LoadGraph(LURE_PATH);
}

// 通常処理
void Lure::Step()
{
	// マウスの動き
	LureMouse.Move();

	// 左クリックを押したなら
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT)) {

	}

	_SaveX = LureMouse.GetX();
	_SaveY = LureMouse.GetY();

	// ルアーをクリックしたところまで移動させる
	if (_X < _SaveX) {
		_X += _SaveX / 60;
	}
	else if (_X >= _SaveX) {
		_X = _SaveX;
	}
	if (_Y < _SaveY) {
		_Y += _SaveY / 60;
	}
	else if (_Y >= _SaveY) {
		_Y = _SaveY;
	}
}

// 画像描画
void Lure::Draw()
{
	DrawRotaGraph(_X, _Y, 0.0f, handle, true, false);
}

// 終了処理
void Lure::Fin()
{
	// ルアーの画像削除
	DeleteGraph(handle);
}
