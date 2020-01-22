#pragma once
#include<list>
#include"Vector2.h"
#include"Bullet.h"
#include"Lazer.h"
#include"BulletCache.h"
#include"Define.h"

class BossShot
{
public:
	//�f�X�g���N�^
	~BossShot();

	//�e������
	void AroundWall(const Vector2& pos);
	void ShotBullet(const Vector2& pos, float angle,float *radius);
	void CreateWall(const Vector2& pos,int *posNum);


	//�����̍X�V
	void Update();

	//�`��
	void Render();

	Vector2 Position(int num);

	Vector2 AWPosition(int num);

	Vector2 CWPosition(int num);

	Vector2 CWSize(int num);

	float* Radius();
	
	int BulletCount()
	{
		return bulletcnt;
	}


public:
	std::vector<Bullet*>_shotList;
	std::vector<AroundW*>_aroundList;
	std::vector<CreateW*>_crewallList;
	BulletCache _cache;
	BulletCache _around;
	BulletCache _crewall;
	Vector2 bulletPos;


	int bulletcnt=0;
	float _radius;
};