#include "Lure.h"
#include "DxLib.h"
#include "../../Mouse/Mouse.h"
#include "../../Input/Input.h"

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
	//LureMouse.Init();
}

// �摜���[�h
void Lure::Load()
{
	// ���A�[�̉摜���[�h
	handle = LoadGraph(LURE_PATH);
}

// �ʏ폈��
void Lure::Step()
{
	// �}�E�X�̓���
	LureMouse.Move();

	// ���N���b�N���������Ȃ�
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT)) {

	}

	_SaveX = LureMouse.GetX();
	_SaveY = LureMouse.GetY();

	// ���A�[���N���b�N�����Ƃ���܂ňړ�������
	if (_X < _SaveX) {
		_X += _SaveX / 60;
	}
	else if (_X >= _SaveX) {
		_X = _SaveX;
	}
	if (_Y < _SaveY) {
		_Y += _SaveY / 60;
	}
	else if (_Y >= _SaveY) {
		_Y = _SaveY;
	}
}

// �摜�`��
void Lure::Draw()
{
	DrawRotaGraph(_X, _Y, 0.0f, handle, true, false);
}

// �I������
void Lure::Fin()
{
	// ���A�[�̉摜�폜
	DeleteGraph(handle);
}
