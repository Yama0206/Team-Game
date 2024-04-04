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

	//���A�[�𓊂�����
	isUse = false;
	// ���A�[�𓊂��Ă��邩
	isThrow = false;
	// ���A�[����ʂ̍������ɂ��邩
	isLureLeft = false;

	fade = -1; //�����x

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
	// �g�p�����ǂ���
	isActive = false;
	//���A�[�𓊂�����
	isUse = false;
	// ���A�[�𓊂��Ă��邩
	isThrow = false;

	// ���݂̍��W
	_X = LURE_POS_X;
	_Y = LURE_POS_Y;

	// ���O�̍��W
	_SaveX = _X;
	_SaveY = _Y;

	// ���A�[�̃}�E�X����������
	LureMouse.Init();

	//�����x
	fade = 255;
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
	//���A�[���������Ă��Ȃ�������
	if (!isUse)
	{
		int zX = 0, zY = 0;	//�ꎞ�ۑ��p�̍��W

		// �}�E�X�̈ʒu���擾
		GetMousePoint(&zX, &zY);

		//���N���b�N�������ꂽ ���� �����Ă���r������Ȃ�
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT) && !isThrow)
		{
			//���A�[�ݒu�͈͓��Ȃ�ȉ����s
			if (zX >= 30 && zX <= SCREEN_SIZE_X - 30 &&
				zY >= 30 && zY <= SCREEN_SIZE_Y - 145)
			{
				//�N���b�N�����ʒu�Ƀ��A�[��\��
				_SaveX = (float)zX;
				_SaveY = (float)zY;

				// �����Ă��锻��ɂ���
				isThrow = true;

				// ������ꂽ�ʒu����ʂ̍��������ǂ���
				if (_SaveX < LURE_POS_X) {
					isLureLeft = true;
				}
				else {
					isLureLeft = false;
				}

				//isActive = true;
			}
		}
	}
}

// �ړ�����
void Lure::Move()
{
	// ���A�[�𓊂����Ȃ�
	if (isThrow) {
		// ���A�[���N���b�N�����Ƃ���܂ł������ړ�������
		_X += GetDirection(_SaveX, _SaveY, _X, _Y, 'x', 6);
		_Y += GetDirection(_SaveX, _SaveY, _X, _Y, 'y', 6);

		// �N���b�N�����Ƃ���܂œ�������~�܂�
		if ((isLureLeft && _X <= _SaveX) ||
			(!isLureLeft && _X >= _SaveX)) {
			_X = _SaveX; // �N���b�N�����Ƃ���܂œ�������~�܂�
		}

		if (_Y < _SaveY) {
			_Y = _SaveY; // �N���b�N�����Ƃ���܂œ�������~�܂�
		}

		// �N���b�N�����Ƃ���܂ňړ�������
		if (_X == _SaveX && _Y == _SaveY) {
			// �����Ă��Ȃ�
			isThrow = false;

			// �g�p���ɂ���
			isUse = true;
		}
	}

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
				
				//isActive = false;
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

	//�f�o�b�N�p�@���A�[�͈̔�
	DrawBox(30, 30, SCREEN_SIZE_X - 30, SCREEN_SIZE_Y - 145, GetColor(0, 0, 255), false);

	/*if (isActive) {*/

	//�����x�ύX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	DrawRotaGraph((int)_X, (int)_Y, 1.0f, 0.0f, handle, true, false);
	//�\�������ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//DrawRotaGraph(500, 500, 1.0f, 0.0f, handle, true, false);
	//}
	
	//�ނ莅
	DrawLine((int)_X, (int)_Y, (int)(LURE_POS_X - 2), (int)(LURE_POS_Y - 5), GetColor(255, 255, 255));
}

// �I������
void Lure::Fin()
{
	// ���A�[�̉摜�폜
	DeleteGraph(handle);
}
