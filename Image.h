#pragma once

#include "Singleton.h"
#include <vector>
class Image:public Singleton<Image>
{
public:
	Image();
	~Image() = default;
	void load() {};
	void relese();

	int getPlayer()const;
	int getTileMap()const;
private:
	int myLoadGraph(const char*FileName);
	int myLoadDivGraph(const char *FileName, int AllNum,
		int XNum, int YNum,
		int XSize, int YSize, int *HandleBuf);
	std::vector<int>_images;
	int _player;
	int _tileMap;
};

