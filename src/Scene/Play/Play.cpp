#include "Play.h"


//�v���C�V�[���̏�����
void Play::Init()
{
	//�v���C���[�̏�����
	player.Init();

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
	player.Draw();
}

//�v���C���[�V�[���̏I������
void Play::Fin()
{
	player.Fin();
}
