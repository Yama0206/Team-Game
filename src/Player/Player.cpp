#include "Player.h"
#include "../Mouse/Mouse.h"
#include "../Input/Input.h"

//�v���C���[�̏�����
void Player::Init()
{
	//�v���C���[�̍��W�̏�����
	posX = 0;		//X���W
	posY = 0;		//Y���W

	//�v���C���[�̉摜�n���h���̏�����
	ImageHundle = -1;
}

//�v���C���[�̓ǂݍ��ݏ���
void Player::Load()
{
	ImageHundle = LoadGraph(PLAYER_PATH);
}

void Player::SetDefaultValue()
{
	//�v���C���[�̍��W�̏�����
	posX = 0;		//X���W
	posY = 0;		//Y���W
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
