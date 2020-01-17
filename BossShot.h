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
	//デストラクタ
	~BossShot();

	//弾を撃つ
	void Shot(const Vector2& pos);
	void Shot(const Vector2& pos, float angle);
	void Shot(const Vector2& pos,int *posNum);


	//処理の更新
	void Update();

	//描画
	void Render();

	Vector2 Position();
	
	int BulletCount()
	{
		return bulletcnt;
	}

public:
	std::list<Bullet*>_shotList;
	std::list<AroundW*>_aroundList;
	std::list<CreateW*>_crewallList;
	BulletCache _cache;
	BulletCache _around;
	BulletCache _crewall;
	Vector2 bulletPos;

	int bulletcnt=0;
};