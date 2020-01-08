#pragma once
#include<vector>
#include<string.h>
#include"Vector2.h"

struct TileHitInfo
{
	bool _hitx; //X�����ɏՓ˂��Ă��邩
	bool _hity; //Y�����ɏՓ˂��Ă��邩
	int _no;    //�^�C���}�b�v�̔ԍ�
};
class TileMap
{
public:
	//������
	void Start();

	//�`��
	void Render();

	//���݈ʒu�{�T�C�Y+verocity���猻�݂̏Փˏ����擾����
	TileHitInfo FindTileHitInfo(const Vector2& pos, const Vector2& size, const Vector2& velocity);

private:
	//�^�C���}�b�v�̏Փ˔�����s��
	int TileCollision(const Vector2& pos, const Vector2& size, const Vector2& velocity);

	//������𕪊�����
	std::vector<int>Split(const std::string&str, char delim = ',');

	//�^�C���}�b�v�̏��
	////�@int [][]���񎟌��z��Ɠ����̏�����
	std::vector<std::vector<int>>_map;

	//�^�C���}�b�v�̉摜
	int _mapgrp;

	//�^�C���}�b�v�̃T�C�Y
	int _tileSize;
};