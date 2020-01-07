#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

//タイルマップの衝突情報を格納する構造体
struct TileHitInfo{
	bool _hitX;
	bool _hitY;
	bool _hitZ;
};
class TileMap
{
public:
	TileMap();
	~TileMap();
};

