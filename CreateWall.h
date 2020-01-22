#pragma once
#include<DxLib.h>
#include"Define.h"
#include"Vector2.h"

class CreateW
{
public:
	//コンスト
	CreateW();
	//デストラ
	~CreateW();

	void Initialize(Vector2 pos,int posNum);
	
	void Render();

	void Update();

	void Slide();

	Vector2 OpenSpace(int posNum);

	Vector2 Position()
	{
		return _pos;
	}

	Vector2 Size()
	{
		return _size;
	}
	

	void SetActive(bool value);

private:
	Vector2 _pos;
	Vector2 _vel;
	Vector2 _size;
	int _posNum;
	bool isActive;
};