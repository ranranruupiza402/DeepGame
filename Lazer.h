#pragma once
#include "Vector2.h"
#include "DxLib.h"

class Lazer
{
public:
	//�R���X�g���N�^
	Lazer();
	//�p�x������
	Lazer(Vector2 pos, float angle);
	//�f�X�g���N�^
	~Lazer();

	void Initialize(Vector2 pos);

	void Render();

	void Update();

	void SetActive(bool value);

	void Extend();

	void Rotation();

	Vector2 Position()
	{
		return _position;
	}

	Vector2 Size()
	{
		return _size;
	}

private:
	int _charge;
	Vector2 _position;
	Vector2 _size;
	Vector2 _velocity;
	int img;
	bool isActive;
	bool isExtend;
	bool isRoll;
};