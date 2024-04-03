#include "Lure.h"
#include "DxLib.h"
#include "../../Input/Input.h"
#include "../../Scene/Scene.h"

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
	isActive = false;
	// ���A�[����ʂ̍������ɂ��邩
	isLureLeft = false;

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
	_X = 0.0f;
	_Y = 0.0f;

	// ���O�̍��W
	_SaveX = 0.0f;
	_SaveY = 0.0f;

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
	// �}�E�X�̓���
	LureMouse.Move();

	// ���N���b�N���������Ȃ�
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT)) {
		_SaveX = (float)LureMouse.GetX();
		_SaveY = (float)LureMouse.GetY();
	}

	if (_SaveX < SCREEN_SIZE_X) {
		isLureLeft = true;
	}
	else {
		isLureLeft = false;
	}
}

// �ړ�����
void Lure::Move()
{
	// ���A�[���N���b�N�����Ƃ���܂ňړ�������
	// �N���b�N�����Ƃ���܂œ�������~�܂�
	if ((isLureLeft && _X > _SaveX) ||
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
	}


}

// �ʏ폈��
void Lure::Step()
{

}

// �摜�`��
void Lure::Draw()
{
	DrawRotaGraph((int)_X, (int)_Y, 0.0f, handle, true, false);
}

// �I������
void Lure::Fin()
{
	// ���A�[�̉摜�폜
	DeleteGraph(handle);
}
