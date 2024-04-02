#pragma once

// ���̍ő吔
const int FISH_MAX_NUM = 20;

// Fish�N���X
class Fish {
private:
	int handle[FISH_MAX_NUM]; // ���摜�n���h��
	float _X[FISH_MAX_NUM], _Y[FISH_MAX_NUM]; // ���݂̍��W
	float _SaveX[FISH_MAX_NUM], _SaveY[FISH_MAX_NUM]; // �ړ���̍��W
	bool isLeft[FISH_MAX_NUM]; // �E�������Ă��邩�ǂ���

public:
	Fish(); // �R���X�g���N�^

	// ���W�ύX�p(����:x���W,y���W,�z��ԍ�)
	void Setpos(float x, float y,int FishIndex) {
		_SaveX[FishIndex] = x;
		_SaveY[FishIndex] = y;
	}

	// X���W�擾�p(����:�z��ԍ�)
	float GetxPos(int FishIndex) { return _X[FishIndex]; }
	// Y���W�擾�p(����:�z��ԍ�)
	float GetyPos(int FishIndex) { return _Y[FishIndex]; }

	// �ړ����X���W�擾�p(����:�ړ���̍��W,�z��ԍ�)
	void GetsavexPos(int X,int FishIndex) { _SaveX[FishIndex] = X; }

	// �ړ����Y���W�擾�p(����:�ړ���̍��W,�z��ԍ�)
	void GetsaveyPos(int Y,int FishIndex) { _SaveY[FishIndex] = Y; }

	// ���W�X�V�p(����:�z��ԍ�
	void UpdatePos(int FishIndex) {
		_X[FishIndex] = _SaveX[FishIndex];
		_Y[FishIndex] = _SaveY[FishIndex];
	}
	 
	// ������
	void Init();

	// �摜���[�h
	void Load();

	// �ʏ폈��
	void Step();

	// �I������
	void Fin();
};