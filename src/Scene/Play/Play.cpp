#include "Play.h"


//�v���C�V�[���̏�����
void Play::Init()
{
	//�v���C���[�̏�����
	player.Init();

	//�摜�ǂݍ���
	backgroundHandle = LoadGraph("data/play/backGround.png");	//�w�i
	jettyHandle = LoadGraph("data/play/jetty.png");	//�V��

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C���[�V�[���̒ʏ폈��
void Play::Step()
{
	player.Step();
}

//�v���C���[�V�[���̕`�揈��
void Play::Draw()
{
	//�w�i�`��
	DrawGraph(0, 0, backgroundHandle, true);	//�w�i
	DrawGraph(0, 0, jettyHandle, true);	//�V��

	player.Draw();
}

//�v���C���[�V�[���̏I������
void Play::Fin()
{
	player.Fin();
}
