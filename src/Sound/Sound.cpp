#include"sound.h"
#include"DxLib.h"

int Sound::Bgm::handle[BGM_MAX_NUM];
int Sound::Se::handle[SE_MAX_NUM];

//BGM�̃p�X
char bgmSoundPath[BGM_MAX_NUM][255] =
{
	//
	"",
};

//����
int soundVolume_bgm[BGM_MAX_NUM] =
{
	100,		//
};

//SE�̃p�X
char seSoundPath[SE_MAX_NUM][255] =
{
	//
	"",
};

//����
int soundVolume_se[SE_MAX_NUM] =
{
	100,			//
};

//�T�E���h�܂Ƃߏ�����
void Sound::Init()
{
	Bgm::Init();
	Se::Init();
}

//BGM�̏�����
void Sound::Bgm::Init()
{
	for (int i = 0; i < BGM_MAX_NUM; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(bgmSoundPath[i]);
		//�{�����[���̐ݒ�
		ChangeVolumeSoundMem(255 * soundVolume_bgm[i] / 100, handle[i]);
	}
}
//BGM�̒ʏ폈���F���
void Sound::Bgm::Play(int type)
{
	//BGM�̍Đ�
	PlaySoundMem(handle[type], DX_PLAYTYPE_LOOP, true);
}
//BGM�̉��ʒ��߁F���,����(�߰��ð��)
void Sound::Bgm::SetVolume(int type, int volume)
{
	//���ʂ̐ݒ�i0�`255�j�i����volume���̉��ʂŏo�́j
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}
//BGM�̒�~�F���
void Sound::Bgm::StopSound(int type)
{
	//BGM�̒�~
	StopSoundMem(handle[type]);
}

//SE�̏�����
void Sound::Se::Init()
{
	for (int i = 0; i < SE_MAX_NUM; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(seSoundPath[i]);
		//�{�����[���̐ݒ�
		int vo = soundVolume_se[i];
		SetVolume(i, vo);
	}
}
//SE�̒ʏ폈���F���
void Sound::Se::Play(int type)
{
	//���ʉ��̍Đ�
	PlaySoundMem(handle[type], DX_PLAYTYPE_BACK, true);
}
//SE�̉��ʒ��߁F���,����(�߰��ð��)
void Sound::Se::SetVolume(int type, int volume)
{
	//���ʂ̐ݒ�i0�`255�j�i����volume���̉��ʂŏo�́j
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}