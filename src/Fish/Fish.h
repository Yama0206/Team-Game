#pragma once

// 魚の最大数
const int FISH_MAX_NUM = 10;

// 魚の画像パス
const char FISH_PATH[] = { "data/play/fish.png" };
const char CAUGHT_FISH_PATH[] = {"data/play/uokage.png"};

// 魚の速度
const float FISH_SPEED = 5.0f;

// 魚画像のサイズ
const float FISH_X_SIZE = 100.0;
const float FISH_Y_SIZE = 42.0;

//魚出現最大時間
const int FISH_POP_TIME = 1;

// 魚の画像の種類
enum FISH_IMAGE_TYPE {
	IMAGE_TYPE_NORMAL = 0,
	IMAGE_TYPE_CAUGHT,

	IMAGE_TYPE_NUM,
};
// Fishクラス
class Fish {
private:
	int handle[IMAGE_TYPE_NUM][FISH_MAX_NUM];								 // 魚画像ハンドル
	float _X[FISH_MAX_NUM], _Y[FISH_MAX_NUM];				 // 現在の座標
	float _SaveX[FISH_MAX_NUM], _SaveY[FISH_MAX_NUM];		 // 移動後の座標
	int Poptime;											 //魚が出てくるまでの時間
	float countTime;

	int fishSpeed[FISH_MAX_NUM];	//移動速度

	bool isLeft[FISH_MAX_NUM];								 // 左を向いているかどうか
	bool isActive[FISH_MAX_NUM];							 //	生きているかどうか
	bool isCaught[FISH_MAX_NUM];							 // かかっているかどうか

	int CaughtNum; // 何匹釣れているか
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
	void GetSaveXPos(float X,int FishIndex) { _SaveX[FishIndex] = X; }

	// 移動後のY座標取得用(引数:移動後の座標,配列番号)
	void GetSaveYPos(float Y,int FishIndex) { _SaveY[FishIndex] = Y; }

	//ルアーに当たった後の座標を設定
	void SetHitUpdatePosX(float X, int FishIndex) { _X[FishIndex] -= X; }
	void SetHitUpdatePosY(float Y, int FishIndex) { _Y[FishIndex] -= Y; }

	//魚が生きているかどうかのフラグ取得用
	bool GetIsActive(int FishIndex) { return isActive[FishIndex]; }

	// 座標更新用(引数:配列番号)
	void UpdatePos();
	 
	// isCaught変更用(引数:配列番号,変更先)
	void SetisCaught(int FishIndex, bool _isCaught);

	// isCaught取得用関数
	bool GetisCaught(int FishIndex) { return isCaught[FishIndex]; }

	// 初期化
	void Init();

	// 画像ロード
	void Load();

	// 通常処理(引数:ルアーの座標)
	void Step(float lureX, float lureY);

	// 画像描画
	void Draw();

	// 終了処理
	void Fin();

	//移動処理
	void Move();

	//出現時間管理処理
	void SetPopTime();

	//魚出現
	void Pop();

	//魚かかったとき
	void Caught(float lureX, float lureY);
};