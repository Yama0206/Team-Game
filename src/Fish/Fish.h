#pragma once

// 魚の最大数
const int FISH_MAX_NUM = 20;

// Fishクラス
class Fish {
private:
	int handle[FISH_MAX_NUM]; // 魚画像ハンドル
	float _X[FISH_MAX_NUM], _Y[FISH_MAX_NUM]; // 現在の座標
	float _SaveX[FISH_MAX_NUM], _SaveY[FISH_MAX_NUM]; // 移動後の座標
	bool isLeft[FISH_MAX_NUM]; // 右を向いているかどうか

public:
	Fish(); // コンストラクタ

	// 座標変更用(引数:x座標,y座標,配列番号)
	void Setpos(float x, float y,int FishIndex) {
		_SaveX[FishIndex] = x;
		_SaveY[FishIndex] = y;
	}

	// X座標取得用(引数:配列番号)
	float GetxPos(int FishIndex) { return _X[FishIndex]; }
	// Y座標取得用(引数:配列番号)
	float GetyPos(int FishIndex) { return _Y[FishIndex]; }

	// 移動後のX座標取得用(引数:移動後の座標,配列番号)
	void GetsavexPos(int X,int FishIndex) { _SaveX[FishIndex] = X; }

	// 移動後のY座標取得用(引数:移動後の座標,配列番号)
	void GetsaveyPos(int Y,int FishIndex) { _SaveY[FishIndex] = Y; }

	// 座標更新用(引数:配列番号
	void UpdatePos(int FishIndex) {
		_X[FishIndex] = _SaveX[FishIndex];
		_Y[FishIndex] = _SaveY[FishIndex];
	}
	 
	// 初期化
	void Init();

	// 画像ロード
	void Load();

	// 通常処理
	void Step();

	// 終了処理
	void Fin();
};