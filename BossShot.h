#pragma once
#include<list>
#include"Vector2.h"
#include"Bullet.h"
#include"BulletCache.h"
#include"Define.h"

class BossShot
{
public:
	//�f�X�g���N�^
	~BossShot();

	//�e������
	void Shot(const Vector2& pos);
	void Shot(const Vector2& pos, float angle);

	//�����̍X�V
	void Update();

	//�`��
	void Render();

public:
	std::list<Bullet*>_shotList;
	BulletCache _cache;
};