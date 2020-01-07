#pragma once
#include<DxLib.h>
#include<queue>
#include"Vector2.h"
#include"Bullet.h"

class BulletCache
{
public:
	//デストラクタ
	~BulletCache();

	//弾を生成するキャッシュがあるかどうか
	Bullet*Instance(Vector2 pos, float angle);

	//弾をキャッシュする
	void Cache(Bullet* bullet);

	void ShowDebugLog();

private:
	//キャッシュクラス
	std::queue<Bullet*>_cache;
};