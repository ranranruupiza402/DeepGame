#pragma once
#include<DxLib.h>
#include"Vector2.h"

class Boss
{
public:
	//������
	void Initialize();

	//�`��
	void Render();

	//�X�V
	void Update();

	//���
	void Release();

	//boss�̍s���p�^�[���p
	void moveField();
	void createWall();
	void createFloor();
	void aroundWall();
	void rollBeam();
	void stay();

	//���W��Ԃ�
	Vector2 Position()
	{
		return _pos;
	}

	//�傫����Ԃ�
	Vector2 Size()
	{
		return _size;
	}	

	//���݂̍s���p�^�[����Ԃ�
	int Pattern()
	{
		return _pattern;
	}

private:
	int _cnt;			//�J�E���^
	int _pattern;		//�s���p�^�[��
	int _dir;			//�����Ă������
	int _hp;			//�̗�
	int _hp_max;		//�ő�̗�
	int _img;			//�摜
	Vector2 _pos;		//���W
	Vector2 _size;		//�傫��
	double _speed;		//����
	bool aroundShot;	//�����ʂɒe�����t���O

};
