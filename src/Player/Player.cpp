#include "Player.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

//�v���C���[�̏�����
void Player::Init()
{
	//�v���C���[�̍��W�̏�����
	posX = 10;
	posY = 10;

	//�v���C���[�̉摜�n���h���̏�����
	ImageHundle = -1;
}

//�v���C���[�̒ʏ폈��
void Player::Step()
{

}

//�v���C���[�̕`�揈��
void Player::Draw()
{
	DrawFormatString(40, 40, GetColor(255, 0, 0), "%d, %d", posX, posY);
}

//�v���C���[�̏I������
void Player::Fin()
{

}

//�v���C���[�̑��쏈��
void Player::Operation()
{

}
