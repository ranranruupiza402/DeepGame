#include<cmath>
#include "Vector2.h"
#include "Lazer.h"
#include"Define.h"

Lazer::Lazer() :_size(Vector2(32, 720))
{
	_velocity = Vector2(1, 0);
}

Lazer::Lazer(Vector2 pos, float angle) : _position(pos), _size(Vector2(1, 32))
{
	int velocity = 3.0;

	double x = cos((Define::PI / 180)*angle)*velocity;
	double y = sin((Define::PI / 180)*angle)*velocity;
}

Lazer::~Lazer()
{

}

void Lazer::Initialize(Vector2 pos)
{
	_position = pos;

	_charge = 0;

	float velocity = 4.0f;

	isExtend = false;

	isRoll = false;

	SetActive(false);
}

void Lazer::Render()
{
	if (!isActive)return;

	img = DrawBox(_position.x, _position.y, _position.x - _size.x, _position.y - _size.y, GetColor(255, 0, 255), FALSE);
	if (isRoll)
	{
		DrawRotaGraph2(Define::WIN_WIDTH/2,Define::WIN_HEGHT,_position.x, _position.y, 1.0, Define::PI / 2, DrawBox(_position.x, _position.y, _position.x - _size.x, _position.y - _size.y, GetColor(255, 0, 255), FALSE), FALSE, FALSE);
	}
}

void Lazer::Update()
{
	if (!isActive)return;
	
	_charge++;

	if(_charge/60==10)
	isExtend = true;

	Extend();

	Rotation();
}

void Lazer::SetActive(bool value)
{
	isActive = value;
}

void Lazer::Extend()
{
	if (!isExtend)return;

	if (_size.y <= 720&&_charge%60==3)
	{
		_size.y += 0.1;

		return;
	}

	if (_size.x <= 32&& _charge % 60 == 3)
	{

		_size.x += 0.01;
		return;
	}

	isRoll = true;
}

void Lazer::Rotation()
{
	if (!isRoll)return;
	
	

}