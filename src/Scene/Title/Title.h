#pragma once

enum TITLE_IMAGE_NUM
{
	TITLE_SKY,
	TITLE_SEA,
	TITLE_JETTY,
	TITLE_CLOUD1,
	TITLE_CLOUD2,
	TITLE_CLOUD3,
	TITLE_CLOUD4,
	TITLE_TITLE,
	TITLE_START,

	TITLE_IMAGE_MAX_NUM,
};

//画像パス
const char TITLE_IMAGE_PATH[TITLE_IMAGE_MAX_NUM][255] =
{
	"data/title/sky.png",
	"data/title/sea.png",
	"data/title/jetty.png",
	"data/title/cloud1.png",
	"data/title/cloud2.png",
	"data/title/cloud3.png",
	"data/title/cloud4.png",
	"data/title/title.png",
	"data/title/start.png",
};

class Title
{
private:
	int imageHandle[TITLE_IMAGE_MAX_NUM];

	float seaY;
	float jettyY;
	float cloudX[4][2];
	float cloudY;
	float titleY;

	int fade[2];

	bool lighting;

	int progress;

	float countTime;

public:

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();

};