#pragma once

// 魚の最大数
const int FISH_MAX_NUM = 4;

// 魚の画像パス
const char FISH_PATH[] = { "data/play/fish.png" };

// 魚の速度
const float FISH_SPEED = 5.0f;

// 魚画像のサイズ
const int FISH_X_SIZE = 100;
const int FISH_Y_SIZE = 42;

// Fishクラス
class Fish {
private:
	int handle[FISH_MAX_NUM];								 // 魚画像ハンドル
	float _X[FISH_MAX_NUM], _Y[FISH_MAX_NUM];				 // 現在の座標
	float _SaveX[FISH_MAX_NUM], _SaveY[FISH_MAX_NUM];		 // 移動後の座標
	int Poptime[FISH_MAX_NUM];								 //魚が出てくるまでの時間

	bool isLeft[FISH_MAX_NUM];								 // 左を向いているかどうか
	bool isActive[FISH_MAX_NUM];							 //	生きているかどうか

public:

	Fish(); // コンストラクタ

	// 座標変更用(引数:X座標,Y座標,配列番号)
	void Setpos(float X, float Y,int FishIndex) 
	{
		_SaveX[FishIndex] = X;
		_SaveY[FishIndex] = Y;
	}

	// X座標取得用(引数:配列番号)
	float GetXPos(int FishIndex) { return _X[FishIndex]; }
	// Y座標取得用(引数:配列番号)
	float GetYPos(int FishIndex) { return _Y[FishIndex]; }

	// 移動後のX座標取得用(引数:移動後の座標,配列番号)
	void GetSaveXPos(int X,int FishIndex) { _SaveX[FishIndex] = X; }

	// 移動後のY座標取得用(引数:移動後の座標,配列番号)
	void GetSaveYPos(int Y,int FishIndex) { _SaveY[FishIndex] = Y; }

	// 座標更新用(引数:配列番号
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

	//移動処理
	void Move();

	//出現時間管理処理
	void SetPopTime();
};