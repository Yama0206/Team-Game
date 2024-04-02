//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "FrameRate/FrameRate.h"	//フレームレート
#include "Input/Input.h"	//入力機能
#include "Scene/Scene.h"	

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//ウィンドウの名前を変える
	SetMainWindowText("釣りキング");

	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) 
	{
		return -1;
	}

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	SCENE_ID g_CurrentSceneID = SCENE_ID_INIT_TITLE;		//シーンID

	//入力制御初期化
	Input::Init();

	//-----------------------------------------
	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//フレームレート管理
		if (FPS())
		{
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			//-----------------------------------------
			//ここからゲームの本体を書くことになる
			//-----------------------------------------

			//火山
			//シーン遷移
			switch (g_CurrentSceneID)
			{
				//タイトルシーン初期化
			case SCENE_ID_INIT_TITLE:

				break;
				//タイトルシーン通常処理
			case SCENE_ID_LOOP_TITLE:

				break;
				//タイトルシーン終了処理
			case SCENE_ID_FIN_TITLE:

				break;


				//プレイシーン初期化
			case SCENE_ID_INIT_PLAY:

				break;
				//プレイシーン通常処理
			case SCENE_ID_LOOP_PLAY:

				break;
				//プレイシーン終了処理
			case SCENE_ID_FIN_PLAY:

				break;


				//リザルトシーン初期化処理
			case SCENE_ID_INIT_RESULT:

				break;
				//リザルトシーン通常処理
			case SCENE_ID_LOOP_RESULT:

				break;
				//リザルトシーン終了処理
			case SCENE_ID_FIN_RESULT:

				break;
			}


			//-----------------------------------------
			//ループの終わりに

			//FPS計算
			CalcFPS();

			//FPS表示（デバック用）
			DrawFPS();

			//フリップ関数
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

