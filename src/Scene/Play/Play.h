#pragma once
#include "../../Scene/Scene.h"
#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Fish/Fish.h"
#include "../../Mouse/Mouse.h"

class Play
{
private:
	//�N���X�̕ϐ��錾
	Player player;		//�v���C���[�N���X
	Fish fish;			//���N���X

	int backgroundHandle;	//�w�i�摜�n���h��
	int jettyHandle;		//�V���摜�n���h��

public:
	//�v���C�V�[���̏�����
	void Init();

	//�v���C�V�[���̏����l�ݒ�
	void SetDefaultValue();

	//�v���C�V�[���̓ǂݍ���
	void Load();

	//�v���C�V�[���̒ʏ폈��
	void Step();

	//�v���C�V�[���̕`�揈��
	void Draw();

	//�v���C�V�[���̏I������
	void Fin();
};
