#include "Image.h"
#include<DxLib.h>

Image::Image()
{
	_player = myLoadGraph("Texture/Player.png");

}

void Image::relese()
{
	const int size = _images.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(_images[i]);
	}
	_images.clear();
}

int Image::getPlayer() const
{
	return _player;
}
int Image::getTileMap() const
{
	return _tileMap;
}

int Image::myLoadGraph(const char * FileName)
{
	int handle;
	handle = LoadGraph(FileName);
	_images.push_back(handle);
	return handle;
}

int Image::myLoadDivGraph(const char * FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int * HandleBuf)
{
	int handle;
	handle = LoadDivGraph(FileName,AllNum,XNum,YNum,XSize,YSize,HandleBuf);
	for (int i = 0; i < AllNum; i++) {
		_images.push_back(HandleBuf[i]);
	}
	return handle;
}
