#pragma once

#define WINDOW_WIDTH  (1280)	//ウィンドウの横の長さ
#define WINDOW_HEIGHT  (720)		//ウィンドウの縦の長さ

enum SCENE_ID
{
	//タイトル関連
	SCENE_ID_INIT_TITLE = 100,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイ関連
	SCENE_ID_INIT_PLAY = 200,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//ゲームクリア関連
	SCENE_ID_INIT_RESULT = 300,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,

};

extern SCENE_ID g_CurrentSceneID;

