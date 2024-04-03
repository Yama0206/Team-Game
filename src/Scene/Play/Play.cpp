#include "Play.h"

const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//�v���C�V�[���̔w�i�摜�̃p�X
const char JETTY_PATH[] = { "data/play/jetty.png" };					//�v���C�V�[���̎V���摜�̃p�X


//�v���C�V�[���̏�����
void Play::Init()
{
	//�v���C���[�̏�����
	player.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���̓ǂݍ���
void Play::Load()
{
	//�摜�ǂݍ���
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//�w�i
	jettyHandle = LoadGraph(JETTY_PATH);	//�V��

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
