#pragma once

// 浮きの画像パス
const char LURE_PATH[256] = { "data/play/lure.png" };

// ルアー画像のサイズ
const int LURE_SIZE = 10;

class Lure {
private:
	Mouse LureMouse; // ルアーのマウス処理クラス

	int handle; // ルアー画像ハンドル
	float _X, _Y; // 現在の座標
	float _SaveX, _SaveY; // 移動後の座標

	bool isActive; // 使用中かどうか
public:

	Lure(); // コンストラクタ

	// 座標変更用(引数:X座標,Y座標,配列番号)
	void Setpos(float X, float Y)
	{
		_SaveX = X;
		_SaveY = Y;
	}

	// X座標取得用
	float GetXPos() { return _X; }
	// Y座標取得用
	float GetYPos() { return _Y; }

	// 移動後のX座標取得用(引数:移動後の座標)
	void GetSaveXPos(int X) { _SaveX = X; }
	// 移動後のY座標取得用(引数:移動後の座標)
	void GetSaveYPos(int Y) { _SaveY = Y; }

	// 座標更新用
	void UpdatePos();

	// 初期化
	void Init();

	// 画像ロード
	void Load();

	// 通常処理
	void Step();

	// 画像描画
	void Draw();

	// 終了処理
	void Fin();
};