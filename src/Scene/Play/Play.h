#pragma once
#include "../../Scene/Scene.h"
#include "DxLib.h"
#include "../../Player/Player.h"
#include "../../Mouse/Mouse.h"

class Play
{
private:
	Player player;
public:
	//�v���C�V�[���̏�����
	void Init();

	//�v���C�V�[���̒ʏ폈��
	void Step();

	//�v���C�V�[���̕`�揈��
	void Draw();

	//�v���C�V�[���̏I������
	void Fin();
};
