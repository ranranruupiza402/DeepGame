#include"BossShot.h"

//�f�X�g���N�^
BossShot::~BossShot()
{
	for (auto shot : _shotList)
	{
		delete shot;
	}
}

//���𔭎˂���
void BossShot::Shot(const Vector2& pos, float angle)
{
	//�e�𓮓I�ɐ���
	Bullet*shot = _cache.Instance(pos, angle);
	//�e�����X�g�Ɋi�[
	_shotList.push_back(shot);
}

void BossShot::Update()
{
	//�C�e���[�^���g�p
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