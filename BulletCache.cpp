#include"BulletCache.h"

BulletCache::~BulletCache()
{
	while (!_cache.empty())
	{
		auto bullet = _cache.front();
		delete bullet;
		_cache.pop();
	}

	while (!_around.empty())
	{
		auto around = _around.front();
		delete around;
		_around.pop();
	}

	while (!_crewall.empty())
	{
		auto crewall = _crewall.front();
		delete crewall;
		_crewall.pop();
	}
}

Bullet*BulletCache::Instance(Vector2 pos, float angle,float *radius)
{
	//�L���b�V��������ꍇ
	if (_cache.size() > 0)
	{
		//�L���b�V�����擾
		auto bullet = _cache.front();
		//������
		bullet->Initialize(pos, angle,*radius);

		_cache.pop();
		return bullet;
	}

	//�C���X�^���X�𐶐�
	auto bullet = new Bullet();
	//������
	bullet->Initialize(pos, angle,*radius);

	return bullet;
}

AroundW*BulletCache::Instance(Vector2 pos)
{
	if (_around.size() > 0)
	{
		auto around = _around.front();

		around->Initialize(pos);

		_around.pop();
		return around;
	}

	auto around = new AroundW();

	around->Initialize(pos);

	return around;
}

CreateW*BulletCache::Instance(Vector2 pos, int posNum)
{
	if (_crewall.size() > 0)
	{
		auto crewall = _crewall.front();
		crewall->Initialize(pos, posNum);

		_crewall.pop();
		return crewall;
	}

	auto crewall = new CreateW();

	crewall->Initialize(pos, posNum);

	return crewall;
}

//�e���L���b�V������
void BulletCache::Cache(Bullet* bullet)
{
	bullet->SetActive(false);

	_cache.push(bullet);
}

void BulletCache::Cache(AroundW* around)
{
	around->SetActive(false);

	_around.push(around);
}

void BulletCache::Cache(CreateW* crewall)
{
	crewall->SetActive(false);
}

void BulletCache::ShowDebugLog()
{
	DrawFormatString(0,16, GetColor(255, 255, 255), "�e�̃L���b�V�����F%d", _cache.size());
	DrawFormatString(0, 32, GetColor(255, 255, 255), "around�̃L���b�V�����F%d", _around.size());
}