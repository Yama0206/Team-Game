#pragma once

// �����̉摜�p�X
const char LURE_PATH[256] = { "data/play/lure.png" };

// ���A�[�摜�̃T�C�Y
const int LURE_SIZE = 10;

class Lure {
private:
	Mouse LureMouse; // ���A�[�̃}�E�X�����N���X

	int handle; // ���A�[�摜�n���h��
	float _X, _Y; // ���݂̍��W
	float _SaveX, _SaveY; // �ړ���̍��W

	bool isActive; // �g�p�����ǂ���
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
	void GetSaveXPos(int X) { _SaveX = X; }
	// �ړ����Y���W�擾�p(����:�ړ���̍��W)
	void GetSaveYPos(int Y) { _SaveY = Y; }

	// ���W�X�V�p
	void UpdatePos();

	// ������
	void Init();

	// �摜���[�h
	void Load();

	// �ʏ폈��
	void Step();

	// �摜�`��
	void Draw();

	// �I������
	void Fin();
};