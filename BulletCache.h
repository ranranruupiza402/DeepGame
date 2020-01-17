#pragma once
#include<DxLib.h>
#include<queue>
#include"Vector2.h"
#include"Bullet.h"
#include"AroundWall.h"
#include"CreateWall.h"
#include"Lazer.h"

class BulletCache
{
public:
	//デストラクタ
	~BulletCache();

	//弾を生成するキャッシュがあるかどうか
	Bullet*Instance(Vector2 pos, float angle);

	AroundW*Instance(Vector2 pos);

	CreateW*Instance(Vector2 pos, int posNum);

	Lazer*Instance(Vector2 pos, Vector2 angleX);

	//弾をキャッシュする
	void Cache(Bullet* bullet);

	void Cache(AroundW* around);

	void Cache(CreateW* crewall);

	void Cache(Lazer* lazer);

	void ShowDebugLog();

private:
	//キャッシュクラス
	std::queue<Bullet*>_cache;
	std::queue<AroundW*>_around;
	std::queue<CreateW*>_crewall;
	std::queue<Lazer*>_lazer;
};