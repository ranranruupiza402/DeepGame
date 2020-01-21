#include <cmath>
#include"Bullet.h"
#include"Define.h"

//コンストラクタ
Bullet::Bullet() :_size(Vector2(16, 16))
{
	_velocity = Vector2(1, 0);
}

//角度付き
Bullet::Bullet(Vector2 pos, float angle) : _position(pos), _size(Vector2(16, 16))
{
	float velocity = 3.0f;

	double x = cos((Define::PI / 180)*angle)*velocity;
	double y = sin((Define::PI / 180)*angle)*velocity;

	_velocity = Vector2(x, y);
}

//初期化
void Bullet::Initialize(Vector2 pos, float angle,float radius)
{
	_position = pos;
	_radius = radius;
	this->radius = &_radius;
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

	DrawCircle(_position.x+16, _position.y+16 , _radius, GetColor(255, 0, 0), FALSE);
}

void Bullet::Update()
{
	if (!isActive)
	return;

	_position += _velocity;
}

void Bullet::SetActive(bool value)
{
	isActive = value;
}