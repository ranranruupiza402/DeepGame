#pragma once
#include <DxLib.h>
#include "Define.h"
#include "Vector2.h"

//��ʂ͈̔͂ɉ����ē����APlayer��X���W���d�Ȃ����痎���ė���e
class AroundW
{
public:
	//���񂷂�
	AroundW();
	//�f�X�g��
	~AroundW();

	//������
	void Initialize(Vector2 pos);
	//�`��
	void Render();
	//�X�V
	void Update();
	
	void Around();

	void SetActive(bool value);

	void setSamePlPos(bool value);

	Vector2 Position()
	{
		return _pos;
	}

	int SpownTime()
	{
		return _spown;
	}

private:
	Vector2 _pos;	//���W
	Vector2 _plPos; //player�̍��W
	Vector2 _vel;	//�����x
	int _spown;	    //�X�|�[�����Ă���̎���
	int cnt;        //�o�ߎ��ԎZ�o�p
	bool isActive;	//�\����\��
	bool samePlPos;

};