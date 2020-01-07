#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

using namespace std;
//�^�C���}�b�v�̏Փˏ����i�[����\����
struct TileHitInfo{
	bool _hitX;
	bool _hitY;
	bool _hitZ;
	int _no;
};
class TileMap
{
public:
	TileMap();
	void draw();
	~TileMap() = default;
	TileHitInfo FindTileHitInfo(
		const Vector2&pos, const Vector2&size, const Vector2&velocity);
private:
	//�Փ˔���
	int TileColl(const Vector2&pos, const Vector2&size, const Vector2&velocity);

	//������̕���
	vector<int>Split(const string&str, char delim = ',');

	//�^�C���}�b�v���
	vector<vector<int>>_map;

	//�^�C���}�b�v�̉摜
	int _mapgrp;

	//�^�C���}�b�v�̃T�C�Y
	int _tileSize;

};