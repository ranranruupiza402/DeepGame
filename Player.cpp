#include"Player.h"
#include <Dxlib.h>
#include<memory>


void Player::Start()
{
	//boss = new Boss();
	speed = -16;
	_gravity = 2;
	_grp = LoadGraph("player.png");
	_size = Vector2(32, 32);
	_radius = 16;
	_position = Vector2(350, 654);
	_velocity = Vector2(0, 0);
	dashDownSpeed = 0.5f;
	dashSpeed = 0;
	Jump2 = FALSE;
	Jump3 = FALSE;
	_hp = 1;
	playerEnd = FALSE;
	MaxJumpCount = 2;
	JumpCount = 0;
	
	
}

void Player::Render()
{
	DrawGraph(_position.x, _position.y, _grp, TRUE);
}

void Player::Update()
{
	if (playerEnd == TRUE)
		return;
	//	キー入力を更新
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	_velocity = Vector2(0, 0);

	//	右キーで右に移動
	if (key & PAD_INPUT_RIGHT) {
		_velocity.x += 6;
	}

	//	左キーで右に移動
	if (key & PAD_INPUT_LEFT) {
		_velocity.x -= 6;
	}
	_position.y -= Jump;
	Jump -= 1;
	if (_position.y > 654)
	{
		_position.y = 654;
		Jump = 0;
		Jump2 = FALSE;
		Jump3 = FALSE;

	}

	if ((key&PAD_INPUT_1) && _position.y == 654 && Jump2 == FALSE && Jump3 == FALSE)
	{
		Jump = 20;
		Jump2 = TRUE;
	}
	if (Jump2 == TRUE && Jump3&&FALSE&&Jump > 0)
	{
		Jump = 20;
	}

	
	
	DashDownSpeed();
	DashSpeed();
	if (_hp <= 0)
	{
		playerEnd = TRUE;
	}
	//_position += _velocity + (Vector2(_velocity.x, _velocity.y)*dashSpeed);
}

void Player::Release()
{
	
}

void Player::UpdatePosition(bool hitX, bool hitY)
{
	//	X方向に衝突
	if (hitX)
		_velocity.x = 0;

	//	Y方向に衝突
	if (hitY)
		_velocity.y = 0;

	_position += _velocity + (Vector2(_velocity.x, _velocity.y)*dashSpeed);
}

void Player::DashDownSpeed()
{
	if (dashSpeed < 0)
	{
		dashSpeed = 0;
	}

	if (!(dashSpeed > 0)) return;

	dashSpeed -= dashDownSpeed;
}
void Player::Attak()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key&PAD_INPUT_3)
	{
		//_playerAttak.Position();
	}
}
void Player::IsHit()
{
	

}
void Player::DashSpeed()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	if ((key&PAD_INPUT_2) && dashSpeed == 0)
	{
		dashSpeed = 3;
	}
}