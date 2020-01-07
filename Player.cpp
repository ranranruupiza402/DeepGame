
#include "Player.h"
#include <DxLib.h>
#include "Image.h"

const static float SPEED = 9;

Player::Player() : _x(300), _y(300)
{
	
}

bool Player::update()
{
	move();
	return true;
}

void Player::draw() const
{
	DrawRotaGraphF(_x, _y, 1.0, 0.0, Image::getIns()->getPlayer(), TRUE);
}

void Player::move()
{
	float moveX = 0, moveY = 0;
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1)&PAD_INPUT_LEFT > 0) {
		moveX -= SPEED;
	}
	_x += moveX;
	_y += moveY;
}