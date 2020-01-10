#pragma once
#include "Vector2.h"
#include "DxLib.h"
#include"Image.h"

class Lazer
{
public:
	//コンストラクタ
	Lazer();
	//角度をつける
	Lazer(Vector2 pos, float angle);
	//デストラクタ
	~Lazer();

	void Initialize(Vector2 pos);

	void Render();

	void Update();

	void SetActive(bool value);

	void SetRote(bool value);

	void Extend();

	void Rotation(float * pos_x,float * pos_Y,float x,float y,float xc,float yc);

	Vector2 Position()
	{
		return _position;
	}

	Vector2 Size()
	{
		return _size;
	}

private:
	int _charge;
	int _rotate;
	Vector2 _position;
	Vector2 _size;
	Vector2 _velocity;
	Vector2 _rollpos;
	int img;
	bool isActive;
	bool isExtend;
	bool isRoll;

	Image image;
};