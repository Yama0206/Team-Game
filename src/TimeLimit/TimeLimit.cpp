#include"DxLib.h"
#include"TimeLimit.h"
#include"../FrameRate/FrameRate.h"
#include"../Scene/Scene.h"

//������
void TimeLimit::Init()
{
	//�摜�ǂݍ���
	LoadDivGraph(TIME_IMAGE_PATH,10,5,2,44,64,imageHandle);

	//�������Ԑݒ�
	currentTime = TIME_LIMIT;
	timeCount = 0.0;
}

//�ʏ폈��
void TimeLimit::Step()
{
	//���Ԃ��J�E���g
	timeCount += 1.0f / FRAME_RATE;

	//�J�E���g���P�b�ɂȂ�����
	if (timeCount >= 1)
	{
		//���݂̎��Ԃ�����
		currentTime--;
		//�J�E���g��߂�
		timeCount = 0.0f;
	}

	//���Ԃ̃J�E���g���O�ɌŒ�
	if (currentTime <= 0)
	{
		currentTime = 0;
	}
}

//�`��
void TimeLimit::Draw()
{
	//�\�̈�
	int imageNum = currentTime / 10;	//�摜�p����
	DrawGraph(30, SCREEN_SIZE_Y - 80, imageHandle[imageNum], true);
	
	//��̈�
	imageNum = currentTime % 10;	//�摜�p����
	DrawGraph(30+50, SCREEN_SIZE_Y - 80, imageHandle[imageNum], true);
}

//�I������
void TimeLimit::Fin()
{

}