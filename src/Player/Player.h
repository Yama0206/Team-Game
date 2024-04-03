#pragma once
#include "DxLib.h"

const char PLAYER_PATH[] = {"a"};		//�v���C���[�̉摜�p�X

class Player
{
private:
	//�v���C���[�̍��W
	float posX, posY;
	//�v���C���[�摜�n���h��
	int ImageHundle;
	
public:
	//X���W�AY���W���擾
	float GetPlayerPosX() { return posX; }
	float GetPlayerPosY() { return posY; }

	//�v���C���[�̏�����
	void Init();

	//�v���C���[�̏����l�ݒ�
	void SetDefaultValue();

	//�v���C���[�̓ǂݍ��ݏ���
	void Load();

	//�v���C���[�̒ʏ폈��
	void Step();

	//�v���C���[�֘A�̕`�揈��
	void Draw();

	//�v���C���[�̏I������
	void Fin();

	//�v���C���[���쏈��
	void Operation();
};
