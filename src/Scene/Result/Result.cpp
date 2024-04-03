#include"DxLib.h"
#include"../Title/Title.h"
#include"../../Scene/Scene.h"
#include"../../Input/Input.h"

int resultImageHandle=0;	//���U���g�摜�p�X

//������
void ResultInit()
{
	//�摜�ǂݍ���
	resultImageHandle = LoadGraph("data/result/result.png");
	//�ʏ폈���Ɉڍs
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}

//�ʏ폈��
void ResultStep()
{
	//���N���b�N�ňȉ�
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		//�I��������
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

//�`��
void ResultDraw()
{
	//�w�i�`��
	DrawGraph(0, 0, resultImageHandle, true);
}

//�I������
void ResultFin()
{
	//�v���C��ʂֈڍs
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}