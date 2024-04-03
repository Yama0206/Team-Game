#include "Lure.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/Scene.h"
#include "../../MathPlus/MathPlus.h"

// �R���X�g���N�^
Lure::Lure()
{
	// ���A�[�摜�n���h��
	handle = -1;
	// ���݂̍��W
	_X = 0.0f;
	_Y = 0.0f;
	// �ړ���̍��W
	_SaveX = 0.0f;
	_SaveY = 0.0f;

	// �g�p�����ǂ���
	isActive = true;
	// ���A�[����ʂ̍������ɂ��邩
	isLureLeft = true;

	//���A�[�𓊂�����
	isUse = false;

	// ���A�[�̃}�E�X
	LureMouse = {};
}

// ���W�X�V�p
void Lure::UpdatePos()
{
	_X = _SaveX;
	_Y = _SaveY;
}

// ������
void Lure::Init()
{ 
	// ���݂̍��W
	_X = LURE_POS_X;
	_Y = LURE_POS_Y;

	// ���O�̍��W
	_SaveX = _X;
	_SaveY = _Y;

	// ���A�[�̃}�E�X����������
	LureMouse.Init();
}

// �摜���[�h
void Lure::Load()
{
	// ���A�[�̉摜���[�h
	handle = LoadGraph(LURE_PATH);
}

// �}�E�X����
void Lure::Mouse()
{
	//// �}�E�X�̓���
	//LureMouse.Move();

	//// ���N���b�N���������Ȃ�
	//if (Input::Mouse::Push(MOUSE_INPUT_LEFT)) {
	//	_SaveX = (float)LureMouse.GetX();
	//	_SaveY = (float)LureMouse.GetY();

	//	isActive = true;
	//}

	//if (_SaveX < SCREEN_SIZE_X) {
	//	isLureLeft = true;
	//}
	//else {
	//	isLureLeft = false;
	//}

	//���A�[���������Ă��Ȃ�������
	if (!isUse)
	{
		int zX = 0, zY = 0;	//�ꎞ�ۑ��p�̍��W

		// �}�E�X�̈ʒu���擾
		GetMousePoint(&zX, &zY);

		//���N���b�N����������
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
		{
			//���A�[�ݒu�͈͓��Ȃ�ȉ����s
			if (zX >= 30 && zX <= SCREEN_SIZE_X - 30 &&
				zY >= 30 && zY <= SCREEN_SIZE_Y - 145)
			{
				//�N���b�N�����ʒu�Ƀ��A�[��\��
				_X = zX;
				_Y = zY;

				//�\���t���O
				isUse = true;
			}
		}
	}
}

// �ړ�����
void Lure::Move()
{
	// ���A�[���N���b�N�����Ƃ���܂ňړ�������
	// �N���b�N�����Ƃ���܂œ�������~�܂�
	/*if ((isLureLeft && _X > _SaveX) ||
		(!isLureLeft && _X < _SaveX)) {
		_X += (_SaveX - SCREEN_SIZE_X) / 60;
	}
	else {
		_X = _SaveX;
	}

	if (_Y < _SaveY) {
		_Y += _SaveY / 60;
	}
	else if (_Y >= _SaveY) {
		_Y = _SaveY;
	}*/

	//���A�[�𓊂��ꂽ��
	if (isUse)
	{
		//���N���b�N�������������Ă�����
		if (Input::Mouse::Keep(MOUSE_INPUT_LEFT))
		{
			//�����l�Ɍ������Đi�s
			_X += GetDirection(LURE_POS_X, LURE_POS_Y, _X, _Y, 'x', 2);
			_Y += GetDirection(LURE_POS_X, LURE_POS_Y, _X, _Y, 'y', 2);

			//�����l�͈̔́A20�ȓ��ɓ�������
			if (GetDistance(LURE_POS_X, LURE_POS_Y, _X, _Y) <= 20)
			{
				//�����l����
				_X = LURE_POS_X;
				_Y = LURE_POS_Y;

				//�g�p�t���O��܂�
				isUse = false;
			}
		}
	}
}

// �ʏ폈��
void Lure::Step()
{
	//���A�[�����鏈��
	Mouse();
	//�������
	Move();
}

// �摜�`��
void Lure::Draw()
{
	if (isActive) {

		DrawRotaGraph((int)_X, (int)_Y, 1.0f, 0.0f, handle, true, false);
		//DrawRotaGraph(500, 500, 1.0f, 0.0f, handle, true, false);
	}
	
	DrawLine(_X, _Y, LURE_POS_X - 2, LURE_POS_Y - 5, GetColor(255, 255, 255));

	//�f�o�b�N�p�@���A�[�͈̔�
	DrawBox(30, 30, SCREEN_SIZE_X - 30, SCREEN_SIZE_Y -145, GetColor(0, 0, 255),false);
}

// �I������
void Lure::Fin()
{
	// ���A�[�̉摜�폜
	DeleteGraph(handle);
}
