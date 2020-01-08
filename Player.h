#pragma once
#include"Vector2.h"
#include"Bullet.h"
#include"PlayerAttak.h"

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
	
	void Attak();

	Vector2 Position() const { return _position; }
	Vector2 Size() const { return _size; }
	float Radius() const { return _radius; }

	Vector2 Velocity() {
		return _velocity;
	}
public:
	Bullet _bossShot;
	PlayerAttak _playerAttak;

	int _grp;
	Vector2 _size;
	Vector2 _position;
	float _radius;
	float _gravity;
	Vector2 _velocity;		
	int _hp;					//HP
	float dashSpeed;			//���x
	float dashDownSpeed;		//����
	float dashSpeedCount;		//�_�b�V���Ԋu
	int Jump;					//�W�����v���x
	int JumpCount;				
	int MaxJumpCount;
	bool Jump2;					//�W�����v�t���O
	bool Jump3;

	bool playerEnd;				//���S


};