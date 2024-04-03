#pragma once
#include "../../Scene/Scene.h"
#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Mouse/Mouse.h"

class Play
{
private:
	Player player;

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
