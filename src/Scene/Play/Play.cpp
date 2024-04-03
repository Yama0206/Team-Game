#include "Play.h"

//�摜�p�X
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//�v���C�V�[���̔w�i�摜�̃p�X
const char JETTY_PATH[] = { "data/play/jetty.png" };					//�v���C�V�[���̎V���摜�̃p�X

TimeLimit timeLimit;	//���Ԑ���

//�v���C�V�[���̏�����
void Play::Init()
{
	player.Init();		//�v���C���[�̏�����

	//�������Ԃ̏�����
	timeLimit.Init();

	//�v���C�V�[���̒ʏ폈���ɑJ��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���̏����l�ݒ�
void Play::SetDefaultValue()
{
	//�v���C���[�̏����l�ݒ�
	player.SetDefaultValue();
}

//�v���C�V�[���̓ǂݍ���
void Play::Load()
{
	//�摜�ǂݍ���
	//�w�i�֘A
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//�w�i
	jettyHandle = LoadGraph(JETTY_PATH);			//�V��
	
	//�v���C���[�摜�̓ǂݍ���
	player.Load();									

}

//�v���C���[�V�[���̒ʏ폈��
void Play::Step()
{
	//�v���C���[�̒ʏ폈��
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

	//�v���C���[�摜�̕`��
	player.Draw();
}

//�v���C���[�V�[���̏I������
void Play::Fin()
{
	//�v���C���[�̏I������
	player.Fin();

	//�������Ԃ̏I������
	timeLimit.Fin();

	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
