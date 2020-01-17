#include "AroundWall.h"

//�R���X�g
AroundW::AroundW()
{

}
//�f�X�g��
AroundW::~AroundW()
{

}

//������
void AroundW::Initialize(Vector2 pos)
{
	_pos = pos;
	_spown = 0;
	cnt = 0;

	SetActive(true);
	_vel = Vector2(-4, 0);
}

void AroundW::Render()
{
	if (!isActive)
	{
		return;
	}

	DrawCircle(_pos.x, _pos.y, 16, GetColor(255, 255, 0), TRUE);
}

void AroundW::Update()
{
	if (!isActive)
	{
		return;
	}

	cnt++;

	if (cnt % 60 == 0)
	{
		_spown++;
	}

	Around();
}

void AroundW::Around()
{
	//�i�s�����F��
	if (_pos.x - 20 <= 0)
	{
		_vel = Vector2(0, -4);
	}
	//�i�s�����F��
	if (_pos.y + 16 >= Define::WIN_HEGHT-64)
	{
		_vel = Vector2(-4, 0);
	}
	//�i�s�����F�E
	if (_pos.y - 20 <= 0)
	{
		_vel = Vector2(4, 0.001);
	}
	//�i�s�����F��
	if (/*_pos.x <= _plPos.x||*/_pos.x>=Define::WIN_WIDTH-20&&_pos.y-20>=0)
	{
		_vel = Vector2(-0.01, 4);
	}

	_pos += _vel;
}

void AroundW::SetActive(bool value)
{
	isActive = value;
}
