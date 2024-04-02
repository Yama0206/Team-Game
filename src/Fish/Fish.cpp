#include "Fish.h"
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
		
		// �E�������Ă��邩�ǂ���
		isLeft[FishIndex] = true;
	}
}

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
		// �n���h��
		handle[FishIndex] = 0;

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
		if (isLeft[FishIndex]) {
			_SaveX[FishIndex] -= FISH_SPEED;
		}
		else {
			_SaveX[FishIndex] += FISH_SPEED;
		}
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
