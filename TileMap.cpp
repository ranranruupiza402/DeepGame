#include "TileMap.h"
#include <sstream>
#include <fstream>
#include "Image.h"
#include "DxLib.h"

using namespace std;
TileMap::TileMap()
{
	ifstream ifs("csv/map.csv");
	if (ifs) {
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
	_tileSize=40;
}

void TileMap::draw()
{
	int x = 0, y = 0;
	for (auto row : _map) {
		x = 0;
		for (auto col : row) {
			DrawRectGraph(x*_tileSize, y*_tileSize, 0, 0, _tileSize, _tileSize, Image::getIns()->getTileMap(), true);

			//マップの描画
			int destX = col % 10;
			int destY = (col / 10) % 10;

			DrawRectGraph(x*_tileSize, y*_tileSize,
				destX*_tileSize, destY*_tileSize,
				_tileSize, _tileSize, Image::getIns()->getTileMap(), true);

			//X方向にマップタイルを1つ分進める
			x++;
		}
		//y方向にマップタイルを1つ進める
		y++;
	}
}

TileHitInfo TileMap::FindTileHitInfo(const Vector2 & pos, const Vector2 & size, const Vector2 & velocity)
{
	//判定を行うキャラの中心座標を取得
	Vector2 center = Vector2((pos.x) + (size.x / 2), (pos.y) + (size.y / 2));

	//X方向の判定
	auto hitx = TileColl(center, size, Vector2(velocity.x, 0));
	//Y方向の座標
	auto hity = TileColl(center, size, Vector2(0, velocity.y));

	//衝突結果を格納する
	TileHitInfo info = { false,false,0 };

	//AND演算子を使用して衝突している場合は”1”、そうじゃなければ”0”とする
	info._hitX = (hitx & 1);
	info._hitY = (hity & 1);

	//衝突したオブジェクト番号を取得する
	info._no = (hitx >> 8) | (hity >> 8);

	return info;
}

int TileMap::TileColl(const Vector2 & pos, const Vector2 & size, const Vector2 & velocity)
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
		if (_map[y][x] > 0)
		{
			//下位8ビットに衝突フラグ、上位8ビットに衝突したオブジェクトを代入
			return 1 | (_map[y][x] << 8);
		}
	}

	return 0;
}

vector<int> TileMap::Split(const string & str, char delim)
{
	stringstream iss(str);
	string tmp;
	vector<int>mapRow;

	while (getline(iss,tmp,delim))
	{
		mapRow.push_back(atoi(tmp.c_str()));
	}
	return mapRow;
}
