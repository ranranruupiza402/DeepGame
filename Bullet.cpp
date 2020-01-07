#include <cmath>
#include"Bullet.h"
#include"Define.h"

//�R���X�g���N�^
Bullet::Bullet() :_size(Vector2(16, 16))
{
	_velocity = Vector2(1, 0);
}

//�p�x�t��
Bullet::Bullet(Vector2 pos, float angle) : _position(pos), _size(Vector2(16, 16))
{
	float velocity = 3.0f;

	double x = cos((Define::PI / 180)*angle)*velocity;
	double y = sin((Define::PI / 180)*angle)*velocity;

	_velocity = Vector2(x, y);
}

//�f�X�g���N�^
Bullet::~Bullet()
{

}

//������
void Bullet::Initialize(Vector2 pos, float angle)
{
	_position = pos;

	float velocity = 4.0f;
	double x = cos((Define::PI / 180)*angle)*velocity;
	double y = sin((Define::PI / 180)*angle)*velocity;

	_velocity = Vector2(x, y);

	SetActive(true);
}

void Bullet::Render()
{
	if (!isActive)
	{
		return;
	}

	DrawCircle(_position.x+16, _position.y+16 , 8, GetColor(255, 0, 0), FALSE);
}

void Bullet::Update()
{
	if (!isActive);

	_position += _velocity;
}

void Bullet::SetActive(bool value)
{
	isActive = value;
}