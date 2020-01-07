#include"BossShot.h"

//デストラクタ
BossShot::~BossShot()
{
	for (auto shot : _shotList)
	{
		delete shot;
	}
}

//球を発射する
void BossShot::Shot(const Vector2& pos, float angle)
{
	//弾を動的に生成
	Bullet*shot = _cache.Instance(pos, angle);
	//弾をリストに格納
	_shotList.push_back(shot);
}

void BossShot::Update()
{
	//イテレータを使用
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		(*it)->Update();

		if ((*it)->Position().x > Define::WIN_WIDTH)
		{
			_cache.Cache(*it);
			it = _shotList.erase(it);
			continue;
		}

		++it;
	}
}

void BossShot::Render()
{
	_cache.ShowDebugLog();
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}