#pragma once
#include "../../Mouse/Mouse.h"

// �����̉摜�p�X
const char LURE_PATH[256] = { "data/play/lure.png" };

// ���A�[�摜�̃T�C�Y
const int LURE_SIZE = 10;

//���A�[�摜�̏c�A���T�C�Y
const float LURE_HIGHT = 17.0f;
const float LURE_WIDTH = 17.0f;

//���A�[�̏����ʒu
const float LURE_POS_X = 400.0f;
const float LURE_POS_Y = 460.0f;

// �ނ�͂̍ő�l
const int MAX_FISHING_POWER = 500;

class Lure {
private:
	Mouse LureMouse;

	enum LureDirection {
		LURE_LEFT = 0,
		LURE_RIGHT,
	};

	int handle; // ���A�[�摜�n���h��
	float _X, _Y; // ���݂̍��W
	float _SaveX, _SaveY; // �ړ���̍��W

	bool isActive; // �g�p�����ǂ���
	bool isLureLeft; // ���A�[����ʂ̍������ɂ��邩

	bool isUse;	//���A�[�𓊂�����
	bool isThrow; // ���A�[�𓊂��Ă��邩

	int fade; //�����x
	int fishingpower; // �Ƃ�������

public:

	Lure(); // �R���X�g���N�^

	// ���W�ύX�p(����:X���W,Y���W,�z��ԍ�)
	void Setpos(float X, float Y)
	{
		_SaveX = X;
		_SaveY = Y;
	}

	// X���W�擾�p
	float GetXPos() { return _X; }
	// Y���W�擾�p
	float GetYPos() { return _Y; }

	// �ړ����X���W�擾�p(����:�ړ���̍��W)
	void GetSaveXPos(float X) { _SaveX = X; }
	// �ړ����Y���W�擾�p(����:�ړ���̍��W)
	void GetSaveYPos(float Y) { _SaveY = Y; }

	// ���W�X�V�p
	void UpdatePos();

	// ������
	void Init();

	// �摜���[�h
	void Load();

	// �}�E�X����
	void Mouse();

	// �ړ�����
	void Move();

	// �ʏ폈��
	void Step();

	// �摜�`��
	void Draw();

	// �I������
	void Fin();
	
	// �ނ菈��(����:�z��ԍ�)
	void Fishing(int FishIndex);
};