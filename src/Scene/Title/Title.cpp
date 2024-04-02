#include"DxLib.h"
#include"../Title/Title.h"
#include"../../Scene/Scene.h"
#include"../../Input/Input.h"

int titleImageHandle;	//�^�C�g���摜�p�X
SCENE_ID g_CurrentSceneID;	//�V�[���ϐ�

//������
void TitleInit()
{
	//�摜�ǂݍ���
	titleImageHandle = LoadGraph("data/title/kariTitle.png");
	//�ʏ폈���Ɉڍs
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//�ʏ폈��
void TitleStep()
{
	//���N���b�N�ňȉ�
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		//�I��������
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//�`��
void TitleDraw()
{
	//�q�[�`��
	DrawGraph(0, 0, titleImageHandle, true);
}

//�I������
void TitleFin()
{
	//�v���C��ʂֈڍs
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}