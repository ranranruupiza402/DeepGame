#include "PlayerAttak.h"

void PlayerAttak::Start(Vector2 pos)
{
	_position = pos;
	SetActive(true);
}

//PlayerAttak::PlayerAttak(const Vector2 & pos)
//{
//}


void PlayerAttak::Update()
{

}

void PlayerAttak::Render()
{
	if(!(isActive))
	{
		return;
	}

	DrawBox(_position.x + 16, _position.y + 16, _position.x + 32, _position.y + 32, GetColor(255, 0, 0), FALSE);
}

void PlayerAttak::SetActive(bool value)
{
	isActive = value;
}
