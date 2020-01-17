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

void Lazer::Initialize(Vector2 pos,Vector2 angleX)
{
	_position = pos;

	_charge = 0;

	_rotate = 0;

	_angle = angleX.x;

	float velocity = 4.0f;

	isExtend = false;

	isRoll = false;

	SetActive(false);

	img = image.getPlayer();
}
void Lazer::Render()
{
	if (!isActive)return;

	DrawBox(_position.x + 32, _position.y - 500, _position.x+32, _position.y, GetColor(255, 0, 255), FALSE);

	if (isRoll)
	{
		DrawBox(_position.x, _position.y, _rollpos.x, _rollpos.y, GetColor(255, 0, 255), TRUE);
	}
}

void Lazer::Update()
{
	if (!isActive)return;
	
	_charge++;

	if(_charge/60==10)
	isExtend = true;

	Extend();

	

	if (isRoll)
	{
		_rotate++;
		int rota = _rotate % 60;
		Rotation(&_rollpos.x, &_rollpos.y, _position.x + 32+rota, _position.y+rota, _position.x, _position.y - 1.2,_angle);
	}

}

void Lazer::SetActive(bool value)
{
	isActive = value;
}

void Lazer::SetRote(bool value)
{
	isRoll = value;
}

void Lazer::Extend()
{
	if (!isExtend)return;

	if (_size.y <= 500&&_charge%60==3)
	{
		_size.y += 1;

		return;
	}

	if (_size.x <= 32&& _charge % 60 == 3)
	{

		_size.x += 0.01;
		return;
	}

	SetRote(true);
}

//pos_x,pos_y‚É’l‚ª•Ô‚éAx,y‚Í‰ñ“]‚³‚¹‚é‚à‚ÌAxc,yc‚Í‰ñ“]‚Ì’†SA1.0‚Í‰ñ“]‚³‚¹‚éŠp“x
void Lazer::Rotation(float *pos_x, float *pos_y, float x, float y, float xc, float yc, float angle)
{
	*pos_x = (x - xc)*cos(angle) - (y - yc)*sin(angle) + xc;
	*pos_y = (x - xc)*sin(angle) + (y - yc)*cos(angle) + yc;
}
