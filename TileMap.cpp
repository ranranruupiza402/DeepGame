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
		//1�s���ǂݍ���
		std::string line;
		while (std::getline(ifs, line))
		{
			//�ǂݍ��񂾕�������J���}��؂�ŕ���
			std::vector<int>data = Split(line);

			//�}�b�v�����i�[
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

			//�}�b�v�̕`��
			int destX = col % 10;
			int destY = (col / 10) % 10;

			DrawRectGraph(x*_tileSize, y*_tileSize,
				destX*_tileSize, destY*_tileSize,
				_tileSize, _tileSize, Image::getIns()->getTileMap(), true);

			//X�����Ƀ}�b�v�^�C����1���i�߂�
			x++;
		}
		//y�����Ƀ}�b�v�^�C����1�i�߂�
		y++;
	}
}

TileHitInfo TileMap::FindTileHitInfo(const Vector2 & pos, const Vector2 & size, const Vector2 & velocity)
{
	//������s���L�����̒��S���W���擾
	Vector2 center = Vector2((pos.x) + (size.x / 2), (pos.y) + (size.y / 2));

	//X�����̔���
	auto hitx = TileColl(center, size, Vector2(velocity.x, 0));
	//Y�����̍��W
	auto hity = TileColl(center, size, Vector2(0, velocity.y));

	//�Փˌ��ʂ��i�[����
	TileHitInfo info = { false,false,0 };

	//AND���Z�q���g�p���ďՓ˂��Ă���ꍇ�́h1�h�A��������Ȃ���΁h0�h�Ƃ���
	info._hitX = (hitx & 1);
	info._hitY = (hity & 1);

	//�Փ˂����I�u�W�F�N�g�ԍ����擾����
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
		//���S���W�{�e�T�C�Y+velocity�ŏՓ˔�����s��
		unsigned int x = static_cast<int>(pos.x + imageWidth[index] + velocity.x) / _tileSize;
		unsigned int y = static_cast<int>(pos.y + imageHeight[index] + velocity.y) / _tileSize;

		if (y > _map.size())
			continue;
		if (x > _map[y].size())
			continue;

		//0�ł͂Ȃ��ꍇ�A��������̃I�u�W�F�N�g�ɏՓ˂���
		if (_map[y][x] > 0)
		{
			//����8�r�b�g�ɏՓ˃t���O�A���8�r�b�g�ɏՓ˂����I�u�W�F�N�g����
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
