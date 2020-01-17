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
	//�f�X�g���N�^
	~BulletCache();

	//�e�𐶐�����L���b�V�������邩�ǂ���
	Bullet*Instance(Vector2 pos, float angle);

	AroundW*Instance(Vector2 pos);

	CreateW*Instance(Vector2 pos, int posNum);

	Lazer*Instance(Vector2 pos, Vector2 angleX);

	//�e���L���b�V������
	void Cache(Bullet* bullet);

	void Cache(AroundW* around);

	void Cache(CreateW* crewall);

	void Cache(Lazer* lazer);

	void ShowDebugLog();

private:
	//�L���b�V���N���X
	std::queue<Bullet*>_cache;
	std::queue<AroundW*>_around;
	std::queue<CreateW*>_crewall;
	std::queue<Lazer*>_lazer;
};