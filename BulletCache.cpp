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
	//�L���b�V��������ꍇ
	if (_cache.size() > 0)
	{
		//�L���b�V�����擾
		auto bullet = _cache.front();
		//������
		bullet->Initialize(pos, angle);

		_cache.pop();
		return bullet;
	}

	//�C���X�^���X�𐶐�
	auto bullet = new Bullet();
	//������
	bullet->Initialize(pos, angle);

	return bullet;
}

//�e���L���b�V������
void BulletCache::Cache(Bullet* bullet)
{
	bullet->SetActive(false);

	_cache.push(bullet);
}

void BulletCache::ShowDebugLog()
{
	DrawFormatString(0,16, GetColor(255, 255, 255), "�e�̃L���b�V�����F%d", _cache.size());
}