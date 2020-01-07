#pragma once
#include<DxLib.h>
#include<queue>
#include"Vector2.h"
#include"Bullet.h"

class BulletCache
{
public:
	//�f�X�g���N�^
	~BulletCache();

	//�e�𐶐�����L���b�V�������邩�ǂ���
	Bullet*Instance(Vector2 pos, float angle);

	//�e���L���b�V������
	void Cache(Bullet* bullet);

	void ShowDebugLog();

private:
	//�L���b�V���N���X
	std::queue<Bullet*>_cache;
};