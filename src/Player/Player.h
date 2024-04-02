#pragma once
#include "DxLib.h"

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
	void InitPlayer();

	//�v���C���[�̒ʏ폈��
	void StepPlayer();

	//�v���C���[�֘A�̕`�揈��
	void DrawPlayer();

	//�v���C���[�̏I������
	void FinPlayer();

	//�v���C���[���쏈��
	void PlayerOperation();
};
