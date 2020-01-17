#include "CreateWall.h"

CreateW::CreateW()
{

}

CreateW::~CreateW()
{

}

void CreateW::Initialize(Vector2 pos,int posNum)
{
	_pos=OpenSpace(posNum);
	_pos.x = pos.x;

	SetActive(true);
}

void CreateW::Render()
{
	DrawBox(_pos.x - 32, 0, _pos.x, _pos.y, GetColor(255, 125, 0),TRUE);

	DrawBox(_pos.x - 32,_pos.y+100, _pos.x,Define::WIN_HEGHT, GetColor(255, 125, 0), TRUE);
}

void CreateW::Update()
{
	Slide();
}

//‰¡ˆÚ“®
void CreateW::Slide()
{
	_vel = Vector2(-2, 0);

	_pos += _vel;
}

//‹ó”’•‚ğŒˆ‚ß‚é
Vector2 CreateW::OpenSpace(int posNum)
{
	switch (posNum)
	{
	case 0:
		return Vector2(0, 550);
		break;
	case 1:
		return Vector2(0, 500);
		break;
	case 2:
		return Vector2(0, 450);
		break;
	case 3:
		return Vector2(0, 400);
		break;
	case 4:
		return Vector2(0, 300);
		break;
	}
}

void CreateW::SetActive(bool value)
{
	isActive = value;
}