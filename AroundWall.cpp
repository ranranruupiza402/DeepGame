#include "AroundWall.h"

//コンスト
AroundW::AroundW()
{

}
//デストラ
AroundW::~AroundW()
{

}

//初期化
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
	//進行方向：上
	if (_pos.x - 20 <= 0)
	{
		_vel = Vector2(0, -4);
	}
	//進行方向：左
	if (_pos.y + 16 >= Define::WIN_HEGHT-64)
	{
		_vel = Vector2(-4, 0);
	}
	//進行方向：右
	if (_pos.y - 20 <= 0)
	{
		_vel = Vector2(4, 0.001);
	}
	//進行方向：下
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
