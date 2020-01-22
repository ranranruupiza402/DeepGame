#pragma once
#include"Vector2.h"
#include "Bullet.h"
#include"Boss.h"
#include<memory>

class Player
{
public:
	Player() {};
	~Player() = default;
	void Start();

	void Render();

	void Update();

	void Release();
	void UpdatePosition(bool hitX, bool hitY);

	void IsHit();
	void DashSpeed();
	void DashDownSpeed();
	//void IsHitBoss( Boss &boss);

	void Attak();
	//ç¿ïWÇï‘Ç∑
	Vector2 Position()
	{
		return _position;
	}

	//ëÂÇ´Ç≥Çï‘Ç∑
	Vector2 Size()
	{
		return _size;
	}
	
	float Radius()
	{
		return _radius;
	}

	Vector2 Velocity() {
		return _velocity;
	}
public:
	std::shared_ptr<Boss>boss;
	int _grp;
	float _gravity;
	Vector2 _position;
	Vector2 _size;
	float _radius;
	Vector2 _velocity;
	int _hp;
	float speed;
	float dashSpeed;
	float dashDownSpeed;
	int Jump;
	int JumpCount;
	int MaxJumpCount;
	bool Jump2;
	bool Jump3;
	bool playerEnd;
	Bullet _bossShot;
	int _seHandle;
};