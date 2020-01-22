#include "CreateWall.h"

CreateW::CreateW()
{

}

CreateW::~CreateW()
{

}

void CreateW::Initialize(Vector2 pos,int posNum)
{
	_pos = Vector2(pos.x, OpenSpace(posNum).y);
	_size = Vector2(32,Define::WIN_HEGHT- OpenSpace(posNum).y);

	SetActive(true);
}

void CreateW::Render()
{
	DrawBox(_pos.x , _pos.y, _pos.x+_size.x, _pos.y+_size.y, GetColor(255, 125, 0),TRUE);
	DrawBox(_pos.x, 0, _pos.x + _size.x, _pos.y-(_size.y+20), GetColor(255, 125, 0), TRUE);

}

void CreateW::Update()
{
	Slide();
}

//â°à⁄ìÆ
void CreateW::Slide()
{
	_vel = Vector2(-2, 0);

	_pos += _vel;
}

//ãÛîíïùÇåàÇﬂÇÈ
Vector2 CreateW::OpenSpace(int posNum)
{
	switch (posNum)
	{
	case 0:
		return Vector2(0, 600);
		break;
	case 1:
		return Vector2(0, 575);
		break;
	case 2:
		return Vector2(0, 550);
		break;
	case 3:
		return Vector2(0, 525);
		break;
	case 4:
		return Vector2(0, 500);
		break;
	}
}

void CreateW::SetActive(bool value)
{
	isActive = value;
}