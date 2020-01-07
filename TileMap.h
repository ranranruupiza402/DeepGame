#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

using namespace std;
//タイルマップの衝突情報を格納する構造体
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
	//衝突判定
	int TileColl(const Vector2&pos, const Vector2&size, const Vector2&velocity);

	//文字列の分割
	vector<int>Split(const string&str, char delim = ',');

	//タイルマップ情報
	vector<vector<int>>_map;

	//タイルマップの画像
	int _mapgrp;

	//タイルマップのサイズ
	int _tileSize;

};