#pragma once

// ���̍ő吔
const int FISH_MAX_NUM = 4;

// ���̉摜�p�X
const char FISH_PATH[] = { "data/play/fish.png" };

// ���̑��x
const float FISH_SPEED = 5.0f;

// ���摜�̃T�C�Y
const int FISH_X_SIZE = 100;
const int FISH_Y_SIZE = 42;

// Fish�N���X
class Fish {
private:
	int handle[FISH_MAX_NUM];								 // ���摜�n���h��
	float _X[FISH_MAX_NUM], _Y[FISH_MAX_NUM];				 // ���݂̍��W
	float _SaveX[FISH_MAX_NUM], _SaveY[FISH_MAX_NUM];		 // �ړ���̍��W
	int Poptime[FISH_MAX_NUM];								 //�����o�Ă���܂ł̎���

	bool isLeft[FISH_MAX_NUM];								 // ���������Ă��邩�ǂ���
	bool isActive[FISH_MAX_NUM];							 //	�����Ă��邩�ǂ���

public:

	Fish(); // �R���X�g���N�^

	// ���W�ύX�p(����:X���W,Y���W,�z��ԍ�)
	void Setpos(float X, float Y,int FishIndex) 
	{
		_SaveX[FishIndex] = X;
		_SaveY[FishIndex] = Y;
	}

	// X���W�擾�p(����:�z��ԍ�)
	float GetXPos(int FishIndex) { return _X[FishIndex]; }
	// Y���W�擾�p(����:�z��ԍ�)
	float GetYPos(int FishIndex) { return _Y[FishIndex]; }

	// �ړ����X���W�擾�p(����:�ړ���̍��W,�z��ԍ�)
	void GetSaveXPos(int X,int FishIndex) { _SaveX[FishIndex] = X; }

	// �ړ����Y���W�擾�p(����:�ړ���̍��W,�z��ԍ�)
	void GetSaveYPos(int Y,int FishIndex) { _SaveY[FishIndex] = Y; }

	// ���W�X�V�p(����:�z��ԍ�
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

	//�ړ�����
	void Move();

	//�o�����ԊǗ�����
	void SetPopTime();
};