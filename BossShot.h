#pragma once
#include<list>
#include"Vector2.h"
#include"Bullet.h"
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

	//処理の更新
	void Update();

	//描画
	void Render();

public:
	std::list<Bullet*>_shotList;
	BulletCache _cache;
};