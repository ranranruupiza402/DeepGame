#pragma once
#include "Vector2.h"
#include "DxLib.h"

class Bullet
{
public:
	//�R���X�g���N�^
	Bullet();
	//�p�x������
	Bullet(Vector2 pos, float angle);
	//�f�X�g���N�^
	~Bullet()=default;

	void Initialize(Vector2 pos, float angle,float radius);

	void Render();

	void Update();

	void SetActive(bool value);

	Vector2 Position() {
		return _position;
	}
	Vector2 size() {
		return _size;
	}

    float* Radius()
	{
		return radius;
	}

private:
	Vector2 _position;	//���W
	Vector2 _size;		//�傫��
	Vector2 _velocity;	//�����x
	float _radius;
	float* radius;
	int img;			//�摜
	bool isActive;		//�\����\��
};
