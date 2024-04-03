#include "Play.h"
#include"../../TimeLimit/TimeLimit.h"

//�摜�p�X
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//�v���C�V�[���̔w�i�摜�̃p�X
const char JETTY_PATH[] = { "data/play/jetty.png" };					//�v���C�V�[���̎V���摜�̃p�X

TimeLimit timeLimit;	//��������

//�v���C�V�[���̏�����
void Play::Init()
{
	//�v���C���[�̏�����
	player.Init();

	//�������Ԃ̏�����
	timeLimit.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���̏����l�ݒ�
void Play::SetDefaultValue()
{
	player.SetDefaultValue();
}

//�v���C�V�[���̓ǂݍ���
void Play::Load()
{
	//�摜�ǂݍ���
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//�w�i
	jettyHandle = LoadGraph(JETTY_PATH);	//�V��

	player.Load();

}

//�v���C���[�V�[���̒ʏ폈��
void Play::Step()
{
	player.Step();

	//�������Ԃ̒ʏ폈��
	timeLimit.Step();
}

//�v���C���[�V�[���̕`�揈��
void Play::Draw()
{
	//�w�i�`��
	DrawGraph(0, 0, backgroundHandle, true);	//�w�i
	DrawGraph(0, 0, jettyHandle, true);	//�V��

	//�������Ԃ̕`��
	timeLimit.Draw();

	player.Draw();
}

//�v���C���[�V�[���̏I������
void Play::Fin()
{
	player.Fin();

	//�������Ԃ̏I������
	timeLimit.Fin();
}
