#pragma once
#include "../../Scene/Scene.h"
#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Fish/Fish.h"
#include "../../Mouse/Mouse.h"

class Play
{
private:
	//クラスの変数宣言
	Player player;		//プレイヤークラス
	Fish fish;			//魚クラス

	int backgroundHandle;	//背景画像ハンドル
	int jettyHandle;		//桟橋画像ハンドル

public:
	//プレイシーンの初期化
	void Init();

	//プレイシーンの初期値設定
	void SetDefaultValue();

	//プレイシーンの読み込み
	void Load();

	//プレイシーンの通常処理
	void Step();

	//プレイシーンの描画処理
	void Draw();

	//プレイシーンの終了処理
	void Fin();
};
