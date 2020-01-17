#include"BossShot.h"

//デストラクタ
BossShot::~BossShot()
{
	for (auto shot : _shotList)
	{
		delete shot;
	}

	for (auto around : _aroundList)
	{
		delete around;
	}
	for (auto crewall : _crewallList)
	{
		delete crewall;
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

//球を発射(壁をまわる)
void BossShot::Shot(const Vector2& pos)
{
	AroundW*around = _around.Instance(pos);
	bulletcnt++;
	_aroundList.push_back(around);
}

void BossShot::Shot(const Vector2& pos, int *posNum)
{
	CreateW*crewall = _crewall.Instance(pos, *posNum);

	_crewallList.push_back(crewall);
}

void BossShot::Update()
{
	//イテレータを使用
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		(*it)->Update();

		if ((*it)->Position().x > Define::WIN_WIDTH|| (*it)->Position().y > Define::WIN_HEGHT
			|| (*it)->Position().x < 0|| (*it)->Position().y< 0)
		{
			_cache.Cache(*it);
			it = _shotList.erase(it);
			continue;
		}

		++it;
	}

	for (auto it = _aroundList.begin(); it != _aroundList.end();)
	{
		(*it)->Update();
		if ((*it)->SpownTime() > 60 || (*it)->Position().x > Define::WIN_WIDTH || (*it)->Position().y > Define::WIN_HEGHT
			|| (*it)->Position().x < 0 || (*it)->Position().y < 0)
		{
			_around.Cache(*it);
			it = _aroundList.erase(it);
			bulletcnt--;
			continue;
		}
		++it;
	}

	for (auto it = _crewallList.begin(); it != _crewallList.end();)
	{
		(*it)->Update();
		if ((*it)->Position().x <= 0)
		{
			_crewall.Cache(*it);
			it = _crewallList.erase(it);
			continue;
		}
		++it;
	}
}

Vector2 BossShot::Position()
{
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		return (*it)->Position();
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
	for (auto around : _aroundList)
	{
		around->Render();
	}
	for (auto crewall : _crewallList)
	{
		crewall->Render();
	}
}