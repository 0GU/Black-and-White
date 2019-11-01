//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"GameHead.h"
#include"ObjStageSelect.h"
#include"ObjReversibleMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageSelect::Init()
{

}

//�A�N�V����
void CObjStageSelect::Action()
{
	x = (float)Input::GetPosX();
	y = (float)Input::GetPosY();

	//�q���g�{�^�������蔻��

	//right�l���`��ƃY���Ă����ג���
	if (120 <= x && 670 >= x && 420 <= y && 510 >= y )
	{
		if (Input::GetMouButtonL() == true)
		{


			Scene::SetScene(new CSceneReversibleMain());


		}
	}
}

//�h���[
void CObjStageSelect::Draw()
{
	//�`��J���[���
	float	c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float   f[4] = { 0.0f,0.0f,0.0f,1.0f };//�e�L�X�g�p

	RECT_F src; //�`�挳�؂���ʒu�̐ݒ�
	RECT_F dst; //�`���\���ʒu


	src.m_top = 448.0f;
	src.m_left = 0.0f;
	src.m_right = 560.0f;
	src.m_bottom = 540.0f;
	dst.m_top = 420.0f;
	dst.m_left = 120.0f;
	dst.m_right = 680.0;
	dst.m_bottom =510.0;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}