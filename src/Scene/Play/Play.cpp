#include "Play.h"

//�摜�p�X
const char BACKGROUND_PATH[] = { "data/play/backGround.png" };		//�v���C�V�[���̔w�i�摜�̃p�X
const char JETTY_PATH[] = { "data/play/jetty.png" };					//�v���C�V�[���̎V���摜�̃p�X

TimeLimit timeLimit;	//���Ԑ���

//�v���C�V�[���̏�����
void Play::Init()
{
	
	IsFishToLureHit = false;		//���ƃ��A�[�������������ǂ����̊m�F�t���O�̏�����

	player.Init();					//�v���C���[�̏�����
	fish.Init();					//�t�B�b�V���̏�����
	lure.Init();					//���A�[�̏�����

	//�������Ԃ̏�����
	timeLimit.Init();

	//�v���C�V�[���̒ʏ폈���ɑJ��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���̏����l�ݒ�
void Play::SetDefaultValue()
{
	//�v���C���[�̏����l�ݒ�
	player.SetDefaultValue();
}

//�v���C�V�[���̓ǂݍ���
void Play::Load()
{
	//�摜�ǂݍ���
	//�w�i�֘A
	backgroundHandle = LoadGraph(BACKGROUND_PATH);	//�w�i
	jettyHandle = LoadGraph(JETTY_PATH);			//�V��
	
	//�v���C���[�֘A
	player.Load();									//�v���C���[�摜�̓ǂݍ���
	fish.Load();									//�t�B�b�V���̉摜�̓ǂݍ���
	lure.Load();									//���A�[�摜�̓ǂݍ���
}

//�v���C���[�V�[���̒ʏ폈��
void Play::Step()
{
	player.Step();			//�v���C���[�̒ʏ폈��
	fish.Step(lure.GetXPos(),lure.GetYPos());			//�t�B�b�V���̒ʏ폈��
	lure.Step();			//���A�[�̒ʏ폈��

	//���ƃ��A�[�������������ǂ������m�F����t���O�ɑ��
	IsFishToLureHit = FishToLureCollision();

	//�m�F
	FishToLureHit();

	//�������Ԃ̒ʏ폈��
	timeLimit.Step();
	
}

//�v���C���[�V�[���̕`�揈��
void Play::Draw()
{
	//�w�i�`��
	DrawGraph(0, 0, backgroundHandle, true);	//�w�i
	DrawGraph(0, 0, jettyHandle, true);	//�V��

	//�������Ԃ̕`��
	timeLimit.Draw();

	fish.Draw();		//�t�B�b�V���摜�̕`��
	lure.Draw();		//���A�[�摜�̕`��		
	player.Draw();		//�v���C���[�摜�̕`��

	//�m�F
	if (IsFishToLureHit)
		DrawFormatString(100, 100, GetColor(255, 0, 0), "%f", num);

	//for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
	//	if (fish.GetisCaught(FishIndex))
	//		DrawFormatString(100, 100, GetColor(255, 0, 0), "%f", num);
	//}

}

//�v���C���[�V�[���̏I������
void Play::Fin()
{
	lure.Fin();			//���A�[�̏I������
	player.Fin();		//�v���C���[�̏I������
	fish.Fin();			//�t�B�b�V���̏I������

	//�������Ԃ̏I������
	timeLimit.Fin();

	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}

//���ƃ��A�[�̓����蔻��
bool Play::FishToLureCollision()
{
	if (lure.GetisUse())
	{
		//���̐���for������
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
			// ���������Ă���Ȃ��΂�
			if (lure.GetisCaught())
				continue;

			//���������Ă��邩�ǂ���
			if (fish.GetIsActive(FishIndex)) {
				//���ƃ��A�[�̓����蔻��
				if (GetDistance(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex)) < 70)
				{
					// �ǂ̋��������������𓯎��ɂƂ�
					fish.SetisCaught(FishIndex, true);
					lure.SetisCaught(true);

					return true;
				}
			}
		}
	}

	return false;
}

//���ƃ��A�[������������
void Play::FishToLureHit()
{
	if (IsFishToLureHit)
	{
		for (int FishIndex = 0; FishIndex < FISH_MAX_NUM; FishIndex++) {
			fish.SetHitUpdatePosX(GetDirection(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex), 'x', 1), FishIndex);
			fish.SetHitUpdatePosX(GetDirection(lure.GetXPos(), lure.GetYPos(), fish.GetXPos(FishIndex), fish.GetYPos(FishIndex), 'x', 1), FishIndex);
		}
	}
}
