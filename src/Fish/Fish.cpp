#include "Fish.h"

Fish::Fish()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// �n���h��
		handle[FishIndex] = 0;

		// ���݂̍��W
		_x[FishIndex] = 0.0f;
		_y[FishIndex] = 0.0f;

		// ���O�̍��W
		_savex[FishIndex] = 0.0f;
		_savey[FishIndex] = 0.0f;
		
		// �E�������Ă��邩�ǂ���
		isLeft[FishIndex] = true;
	}
}

// ������
void Fish::Init()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// �n���h��
		handle[FishIndex] = 0;

		// ���݂̍��W
		_x[FishIndex] = 0.0f;
		_y[FishIndex] = 0.0f;

		// ���O�̍��W
		_savex[FishIndex] = 0.0f;
		_savey[FishIndex] = 0.0f;

		// �E�������Ă��邩�ǂ���
		isLeft[FishIndex] = true;
	}
}

// �摜���[�h
void Fish::Load()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		// �n���h��
		handle[FishIndex] = 0;
	}
}

// �ʏ폈��
void Fish::Step()
{
	for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
		if (isLeft[FishIndex]) {

		}
	}
}

// �I������
void Fish::Fin()
{
}
