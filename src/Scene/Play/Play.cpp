#include "Play.h"

//画像パス
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//プレイシーンの背景画像のパス
const char JETTY_PATH[] = { "data/play/jetty.png" };					//プレイシーンの桟橋画像のパス

TimeLimit timeLimit;	//時間制限

//プレイシーンの初期化
void Play::Init()
{
	
	IsFishToLureHit = false;		//魚とルアーが当たったかどうかの確認フラグの初期化

	player.Init();					//プレイヤーの初期化
	fish.Init();					//フィッシュの初期化
	lure.Init();					//ルアーの初期化

	//制限時間の初期化
	timeLimit.Init();

	//プレイシーンの通常処理に遷移
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーンの初期値設定
void Play::SetDefaultValue()
{
	//プレイヤーの初期値設定
	player.SetDefaultValue();
}

//プレイシーンの読み込み
void Play::Load()
{
	//画像読み込み
	//背景関連
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//背景
	jettyHandle = LoadGraph(JETTY_PATH);			//桟橋
	
	//プレイヤー関連
	player.Load();									//プレイヤー画像の読み込み
	fish.Load();									//フィッシュの画像の読み込み
	lure.Load();									//ルアー画像の読み込み
}

//プレイヤーシーンの通常処理
void Play::Step()
{
	player.Step();			//プレイヤーの通常処理
	fish.Step(lure.GetXPos(),lure.GetYPos());			//フィッシュの通常処理
	lure.Step();			//ルアーの通常処理

	//魚とルアーが当たったかどうかを確認するフラグに代入
	IsFishToLureHit = FishToLureCollision();

	//確認
	FishToLureHit();

	//制限時間の通常処理
	timeLimit.Step();
	
}

//プレイヤーシーンの描画処理
void Play::Draw()
{
	//背景描画
	DrawGraph(0, 0, backgroundHandle, true);	//背景
	DrawGraph(0, 0, jettyHandle, true);	//桟橋

	//制限時間の描画
	timeLimit.Draw();

	fish.Draw();		//フィッシュ画像の描画
	lure.Draw();		//ルアー画像の描画		
	player.Draw();		//プレイヤー画像の描画

	//確認
	if (IsFishToLureHit)
		DrawFormatString(100, 100, GetColor(255, 0, 0), "%f", num);

	//for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
	//	if (fish.GetisCaught(FishIndex))
	//		DrawFormatString(100, 100, GetColor(255, 0, 0), "%f", num);
	//}

}

//プレイヤーシーンの終了処理
void Play::Fin()
{
	lure.Fin();			//ルアーの終了処理
	player.Fin();		//プレイヤーの終了処理
	fish.Fin();			//フィッシュの終了処理

	//制限時間の終了処理
	timeLimit.Fin();

	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}

//魚とルアーの当たり判定
bool Play::FishToLureCollision()
{
	if (lure.GetisUse())
	{
		//魚の数分for分を回す
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
			// 今あたっているなら飛ばす
			if (lure.GetisCaught())
				continue;

			//魚が生きているかどうか
			if (fish.GetIsActive(FishIndex)) {
				//魚とルアーの当たり判定
				if (GetDistance(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex)) < 70)
				{
					// どの魚があたったかを同時にとる
					fish.SetisCaught(FishIndex, true);
					lure.SetisCaught(true);

					return true;
				}
			}
		}
	}

	return false;
}

//魚とルアーが当たった時
void Play::FishToLureHit()
{
	if (IsFishToLureHit)
	{
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
			fish.SetHitUpdatePosX(GetDirection(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex), 'x', 1), FishIndex);
			fish.SetHitUpdatePosX(GetDirection(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex), 'x', 1), FishIndex);
		}
	}
}
