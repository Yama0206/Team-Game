#include "Fish.h"
#include "../Scene/Scene.h"
#include "../FrameRate/FrameRate.h"

#include "DxLib.h"

Fish::Fish()
{
	//���̍ő吔�܂�for������
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// �n���h��
		handle[FishIndex] = 0;

		// ���݂̍��W
		_X[FishIndex] = 0.0f;
		_Y[FishIndex] = 0.0f;
		// ���O�̍��W
		_SaveX[FishIndex] = 0.0f;
		_SaveY[FishIndex] = 0.0f;
		
		isLeft[FishIndex] = true; // ���������Ă��邩�ǂ���
		isActive[FishIndex] = false; // �����Ă��邩�ǂ���
	}

	//�����o�Ă���܂ł̎���
	Poptime = 0;
	countTime = 0;
}

// ���W�X�V�p
void Fish::UpdatePos()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) 
	{
		_X[FishIndex] = _SaveX[FishIndex];
		_Y[FishIndex] = _SaveY[FishIndex];
	}
}

// ������
void Fish::Init()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���݂̍��W
		_X[FishIndex] = 500.0f;
		_Y[FishIndex] = 500.0f;

		// ���O�̍��W
		_SaveX[FishIndex] = _X[FishIndex];
		_SaveY[FishIndex] = _Y[FishIndex];

		//���������Ă��邩�ǂ���
		if (GetRand(1) == 0)
		{
			isLeft[FishIndex] = true;
		}
		else
		{
			isLeft[FishIndex] = false;
		}
		
	}

	//�����o�Ă���܂ł̎���
	Poptime = 0;
	countTime = 0;
}

// �摜���[�h
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���̉摜���[�h
		handle[FishIndex] = LoadGraph(FISH_PATH);
	}
}

// �ʏ폈��
void Fish::Step()
{
	//�ړ�����
	Move();

	//�o������
	Pop();

	//���W�X�V����
	//UpdatePos();
}

// �摜�`��
void Fish::Draw()
{
	//60%�ŕ`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)255 * 0.6);

	//���̍ő吔�܂�for������
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) 
	{
		//�����g�p���Ȃ�`��
		if (isActive[FishIndex])
		{
			DrawRotaGraph((int)_X[FishIndex], (int)_Y[FishIndex],
						1.0f, 0.0f, handle[FishIndex], true, isLeft[FishIndex]);
		}

		//DrawFormatString(30, 30, GetColor(255, 0, 0), "%d", Poptime);
	}

	//�\�������ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �I������
void Fish::Fin()
{
	//���̍ő吔�܂�for������
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���̉摜�폜
		DeleteGraph(handle[FishIndex]);
	}
}

//�ړ�����
void Fish::Move()
{
	//���̍ő吔�܂�for������
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {

		if (isActive[FishIndex])
		{
			// ���̈ړ�����
			if (isLeft[FishIndex]) {
				_X[FishIndex] -= fishSpeed[FishIndex]; // ���������Ă���Ƃ����ɓ���
			}
			else {
				_X[FishIndex] += fishSpeed[FishIndex]; // �E�������Ă���Ƃ��ɉE�ɓ���
			}
		}

		// ������ʊO�ɍs�����Ƃ�
		//��
		if (isLeft[FishIndex])
		{
			if (_X[FishIndex] > SCREEN_SIZE_X + FISH_X_SIZE / 2)
			{
				isActive[FishIndex] = false; // �����E��
			}
		}
		//��
		else
		{
			if (_X[FishIndex] < -FISH_X_SIZE / 2)
			{
				isActive[FishIndex] = false; // �����E��
			}
		}
		
	}
}

//�o�����ԊǗ�����
void Fish::SetPopTime()
{
	//���̍ő吔�܂�for������
	/*for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++)
	{
		if (FishIndex <= 4) {
			Poptime[FishIndex] = GetRand(10);
		}
	}*/

	countTime += 1.0f / FRAME_RATE;	//���Ԃ��J�E���g
}

//���o��
void Fish::Pop()
{
	//�o�����ԊǗ�����
	SetPopTime();

	//�J�E���g���o�����Ԃ��z������
	if (countTime > Poptime)
	{
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++)
		{
			//�g�p����ĂȂ�������ȉ����s
			if (!isActive[FishIndex])
			{
				//���������Ă��邩�ǂ����@�����_���Ō���
				//��
				if (GetRand(1) == 0)
				{
					isLeft[FishIndex] = true;
				}
				//��
				else
				{
					isLeft[FishIndex] = false;
				}

				//���E����ʒu��ݒ�
				if (isLeft[FishIndex])
				{
					//�E�[�ɐݒ�
					_X[FishIndex] = SCREEN_SIZE_X+ FISH_X_SIZE/2;
					_Y[FishIndex] = GetRand(SCREEN_SIZE_Y - 145 - 30) + 30;
				}
				else
				{
					//���[�ɐݒ�
					_X[FishIndex] = 0 - FISH_X_SIZE / 2;
					_Y[FishIndex] = GetRand(SCREEN_SIZE_Y - 145 - 30) + 30;
				}

				//�����g�p���ɂ���
				isActive[FishIndex] = true;

				//���̃X�s�[�h��ݒ�
				fishSpeed[FishIndex] = GetRand(FISH_SPEED - 1) + 1;

				//���̏o�����Ԃ�ݒ�
				Poptime = GetRand(FISH_POP_TIME) + 1;
				//�J�E���g�����Z�b�g
				countTime = 0;

				break;
			}
		}
	}
}