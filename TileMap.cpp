#include<DxLib.h>
#include<fstream>
#include<sstream>
#include"TileMap.h"
#include "GamePlayScene.h"
#include"Player.h"

//������
void TileMap::Start()
{
	//�摜�̓ǂݍ���
	_mapgrp = LoadGraph("Texture\\pipo-map111.png");

	//�}�b�v��ǂݍ���
	std::ifstream ifs("csv\\map.csv");

	//�ǂݍ��݂ɐ���������
	if (ifs)
	{
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

	//�^�C���}�b�v�̃T�C�Y�w��
	_tileSize = 40;
}

void TileMap::Render()
{
	//X�̈ʒu��Y�̈ʒu
	int x = 0, y = 0;

	//�}�b�v�����s�P�ʂœǂݍ���
	for (auto row : _map)
	{
		x = 0;
		//�}�b�v�����擾
		for (auto col : row)
		{
			//���n�̕`��
			DrawRectGraph(x*_tileSize, y*_tileSize, 0, 0, _tileSize, _tileSize, _mapgrp, true);

			//�}�b�v�̕`��
			auto destX = col % 10;
			auto destY = (col / 10) % 10;

			DrawRectGraph(x*_tileSize, y*_tileSize, destX*_tileSize, destY*_tileSize, _tileSize, _tileSize, _mapgrp, true);

			//X�����Ƀ}�b�v�^�C����1���i�߂�
			x++;
		}
		//Y�����Ƀ}�b�v�^�C����1���i�߂�
		y++;
	}
}

//���݈ʒu�{�T�C�Y+velocity���猻�݂̏Փˏ����擾����
TileHitInfo TileMap::FindTileHitInfo(const Vector2& pos, const Vector2& size, const Vector2& velocity)
{
	//������s���L�����̒��S���W���擾
	Vector2 center = Vector2((pos.x) + (size.x / 2), (pos.y) + (size.y / 2));

	//X�����̔���
	auto hitx = TileCollision(center, size, Vector2(velocity.x, 0));
	//Y�����̍��W
	auto hity = TileCollision(center, size, Vector2(0, velocity.y));

	//�Փˌ��ʂ��i�[����
	TileHitInfo info = { false,false,0 };

	//AND���Z�q���g�p���ďՓ˂��Ă���ꍇ�́h1�h�A��������Ȃ���΁h0�h�Ƃ���
	info._hitx = (hitx & 1);
	info._hity = (hity & 1);

	//�Փ˂����I�u�W�F�N�g�ԍ����擾����
	info._no = (hitx >> 8) | (hity >> 8);

	return info;
}

//�^�C���}�b�v�̏Փ˔�����s��
int TileMap::TileCollision(const Vector2 & pos, const Vector2 & size, const Vector2 & velocity)
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
		if (_map[y][x] != 0 )
		{
			if (_map[y][x] != 1) {
				//����8�r�b�g�ɏՓ˃t���O�A���8�r�b�g�ɏՓ˂����I�u�W�F�N�g����
				return 1 | (_map[y][x] << 8);
			}

		}
	}

	//�������ĂȂ�
	return 0;
}

std::vector<int>TileMap::Split(const std::string&str, char delim)
{
	std::stringstream iss(str);
	std::string tmp;
	std::vector<int>mapRow;

	//��������J���}��؂�œǂݍ���
	while (getline(iss, tmp, delim))
		mapRow.push_back(std::atoi(tmp.c_str()));

	return mapRow;
}