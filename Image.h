#pragma once

#include "Singleton.h"
#include <vector>
class Image:public Singleton<Image>
{
public:
	Image();
	~Image() = default;
	void load();
	void relese();

	int getPlayer()const;
private:
	int myLoadGraph(const char*FileName);
	int myLoadDivGraph(char *FileName, int AllNum,
		int XNum, int YNum,
		int XSize, int YSize, int *HandleBuf);
	std::vector<int>_images;
	int _player;
};

