#include "Fish.h"
#include "../Scene/Scene.h"

#include "DxLib.h"

Fish::Fish()
{
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
		isActive[FishIndex] = true; // �����Ă��邩�ǂ���
	}
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
		_X[FishIndex] = 0.0f;
		_Y[FishIndex] = 0.0f;

		// ���O�̍��W
		_SaveX[FishIndex] = 0.0f;
		_SaveY[FishIndex] = 0.0f;

		// �E�������Ă��邩�ǂ���
		isLeft[FishIndex] = true;
	}
}

// �摜���[�h
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���̉摜���[�h
		handle[FishIndex] = LoadGraph(FISH_PATH[FishIndex]);
	}
}

// �ʏ폈��
void Fish::Step()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���̈ړ�����
		if (isLeft[FishIndex]) {
			_SaveX[FishIndex] -= FISH_SPEED; // ���������Ă���Ƃ����ɓ���
		}
		else {
			_SaveX[FishIndex] += FISH_SPEED; // �E�������Ă���Ƃ��ɉE�ɓ���
		}

		// ������ʊO�ɍs�����Ƃ�
		if (_SaveX[FishIndex] > SCREEN_SIZE_X + FISH_X_SIZE / 2 ||
			_SaveX[FishIndex] < -FISH_X_SIZE / 2) {
			isActive[FishIndex] = false; // �����E��
		}
	}
}

// �摜�`��
void Fish::Draw()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		DrawRotaGraph(_X[FishIndex], _Y[FishIndex], 0.0f, handle[FishIndex], true, isLeft[FishIndex]);
	}
}

// �I������
void Fish::Fin()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// ���̉摜�폜
		DeleteGraph(handle[FishIndex]);
	}
}
