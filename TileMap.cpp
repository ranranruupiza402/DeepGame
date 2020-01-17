#include<DxLib.h>
#include<fstream>
#include<sstream>
#include"TileMap.h"
#include "GamePlayScene.h"
#include"Player.h"

//初期化
void TileMap::Start()
{
	//画像の読み込み
	_mapgrp = LoadGraph("Texture\\pipo-map111.png");

	//マップを読み込む
	std::ifstream ifs("csv\\map.csv");

	//読み込みに成功したら
	if (ifs)
	{
		//1行ずつ読み込む
		std::string line;
		while (std::getline(ifs, line))
		{
			//読み込んだ文字列をカンマ区切るで分割
			std::vector<int>data = Split(line);

			//マップ情報を格納
			_map.push_back(data);
		}
	}

	//タイルマップのサイズ指定
	_tileSize = 40;
}

void TileMap::Render()
{
	//Xの位置とYの位置
	int x = 0, y = 0;

	//マップ情報を行単位で読み込む
	for (auto row : _map)
	{
		x = 0;
		//マップ情報を取得
		for (auto col : row)
		{
			//下地の描画
			DrawRectGraph(x*_tileSize, y*_tileSize, 0, 0, _tileSize, _tileSize, _mapgrp, true);

			//マップの描画
			auto destX = col % 10;
			auto destY = (col / 10) % 10;

			DrawRectGraph(x*_tileSize, y*_tileSize, destX*_tileSize, destY*_tileSize, _tileSize, _tileSize, _mapgrp, true);

			//X方向にマップタイルを1つ分進める
			x++;
		}
		//Y方向にマップタイルを1つ分進める
		y++;
	}
}

//現在位置＋サイズ+velocityから現在の衝突情報を取得する
TileHitInfo TileMap::FindTileHitInfo(const Vector2& pos, const Vector2& size, const Vector2& velocity)
{
	//判定を行うキャラの中心座標を取得
	Vector2 center = Vector2((pos.x) + (size.x / 2), (pos.y) + (size.y / 2));

	//X方向の判定
	auto hitx = TileCollision(center, size, Vector2(velocity.x, 0));
	//Y方向の座標
	auto hity = TileCollision(center, size, Vector2(0, velocity.y));

	//衝突結果を格納する
	TileHitInfo info = { false,false,0 };

	//AND演算子を使用して衝突している場合は”1”、そうじゃなければ”0”とする
	info._hitx = (hitx & 1);
	info._hity = (hity & 1);

	//衝突したオブジェクト番号を取得する
	info._no = (hitx >> 8) | (hity >> 8);

	return info;
}

//タイルマップの衝突判定を行う
int TileMap::TileCollision(const Vector2 & pos, const Vector2 & size, const Vector2 & velocity)
{
	auto sizeX = static_cast<int>(size.x / 2);
	auto sizeY = static_cast<int>(size.y / 2);
	std::vector<int>imageWidth = { -sizeX,sizeX,-sizeX,sizeX };
	std::vector<int>imageHeight = { -sizeY,-sizeY,sizeY,sizeY };

	for (unsigned int index = 0; index < imageWidth.size(); index++)
	{
		//中心座標＋各サイズ+velocityで衝突判定を行う
		unsigned int x = static_cast<int>(pos.x + imageWidth[index] + velocity.x) / _tileSize;
		unsigned int y = static_cast<int>(pos.y + imageHeight[index] + velocity.y) / _tileSize;

		if (y > _map.size())
			continue;
		if (x > _map[y].size())
			continue;

		//0ではない場合、何かしらのオブジェクトに衝突した
		if (_map[y][x] != 0 )
		{
			if (_map[y][x] != 1) {
				//下位8ビットに衝突フラグ、上位8ビットに衝突したオブジェクトを代入
				return 1 | (_map[y][x] << 8);
			}

		}
	}

	//当たってない
	return 0;
}

std::vector<int>TileMap::Split(const std::string&str, char delim)
{
	std::stringstream iss(str);
	std::string tmp;
	std::vector<int>mapRow;

	//文字列をカンマ区切るで読み込む
	while (getline(iss, tmp, delim))
		mapRow.push_back(std::atoi(tmp.c_str()));

	return mapRow;
}