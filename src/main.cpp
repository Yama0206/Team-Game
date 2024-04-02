//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "FrameRate/FrameRate.h"	//�t���[�����[�g
#include "Input/Input.h"	//���͋@�\
#include "Scene/Scene.h"	

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//�E�B���h�E�̖��O��ς���
	SetMainWindowText("�ނ�L���O");

	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) 
	{
		return -1;
	}

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	SCENE_ID g_CurrentSceneID = SCENE_ID_INIT_TITLE;		//�V�[��ID

	//���͐��䏉����
	Input::Init();

	//-----------------------------------------
	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		//�t���[�����[�g�Ǘ�
		if (FPS())
		{
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------

			//�ΎR
			//�V�[���J��
			switch (g_CurrentSceneID)
			{
				//�^�C�g���V�[��������
			case SCENE_ID_INIT_TITLE:

				break;
				//�^�C�g���V�[���ʏ폈��
			case SCENE_ID_LOOP_TITLE:

				break;
				//�^�C�g���V�[���I������
			case SCENE_ID_FIN_TITLE:

				break;


				//�v���C�V�[��������
			case SCENE_ID_INIT_PLAY:

				break;
				//�v���C�V�[���ʏ폈��
			case SCENE_ID_LOOP_PLAY:

				break;
				//�v���C�V�[���I������
			case SCENE_ID_FIN_PLAY:

				break;


				//���U���g�V�[������������
			case SCENE_ID_INIT_RESULT:

				break;
				//���U���g�V�[���ʏ폈��
			case SCENE_ID_LOOP_RESULT:

				break;
				//���U���g�V�[���I������
			case SCENE_ID_FIN_RESULT:

				break;
			}


			//-----------------------------------------
			//���[�v�̏I����

			//FPS�v�Z
			CalcFPS();

			//FPS�\���i�f�o�b�N�p�j
			DrawFPS();

			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

