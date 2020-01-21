#pragma once
#include<DxLib.h>
#include"Vector2.h"
class Boss
{
public:
	//������
	void Start();

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

	//���W��Ԃ�
	Vector2 Position()
	{
		return _position;
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

	bool AroundShot()
	{
		return aroundShot;
	}

	bool Shot()
	{
		return shot;
	}

private:
	int _cnt;			//���̍s���܂ł̃J�E���^
	int _waitCnt;       //�U���̌㌄
	int _pattern;		//�s���p�^�[��
	int _dir;			//�����Ă������
	int _hp;			//�̗�
	int _hp_max;		//�ő�̗�
	int _img;			//�摜
	int _startTime;		//�s���J�n��������
	int _elapsedTime;	//���݂Ɍo�ߎ���
	int _shotspace;		//�e�̔��ˊԊu�p
	Vector2 _position;		//���W
	Vector2 _size;		//�傫��
	Vector2 _velocity;	//�����x
	double _speed;		//����
	bool aroundShot;	//�����ʂɒe�����t���O
	bool shot;			//�e�����ˏo
	bool air;           //�󒆂ɂ��邩
};
