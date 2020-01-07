#include"BulletCache.h"

BulletCache::~BulletCache()
{
	while (!_cache.empty())
	{
		auto bullet = _cache.front();
		delete bullet;
		_cache.pop();
	}
}

Bullet*BulletCache::Instance(Vector2 pos, float angle)
{
	//キャッシュがある場合
	if (_cache.size() > 0)
	{
		//キャッシュを取得
		auto bullet = _cache.front();
		//初期化
		bullet->Initialize(pos, angle);

		_cache.pop();
		return bullet;
	}

	//インスタンスを生成
	auto bullet = new Bullet();
	//初期化
	bullet->Initialize(pos, angle);

	return bullet;
}

//弾をキャッシュする
void BulletCache::Cache(Bullet* bullet)
{
	bullet->SetActive(false);

	_cache.push(bullet);
}

void BulletCache::ShowDebugLog()
{
	DrawFormatString(0,16, GetColor(255, 255, 255), "弾のキャッシュ数：%d", _cache.size());
}