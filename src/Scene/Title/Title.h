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

//‰æ‘œƒpƒX
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

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();

};