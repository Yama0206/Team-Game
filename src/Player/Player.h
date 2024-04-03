#pragma once
#include "DxLib.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = {"data/play/player.png"};		//�v���C���[�̉摜�p�X

const int PLAYER_WIDE = 47;									//�v���C���[�摜�̉���
const int PLAYER_HIGHT = 122;								//�v���C���[�摜�̏c��
const float PLAYER_RAD = 23.5;								//�v���C���[�摜�̔��a

class Player
{
private:
	
	float posX, posY;		//�v���C���[�̍��W
	int ImageHundle;		//�v���C���[�摜�n���h��

	
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
