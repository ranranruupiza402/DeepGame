#pragma once
#include "Vector2.h"
#include "DxLib.h"

class Bullet
{
public:
	//コンストラクタ
	Bullet();
	//角度をつける
	Bullet(Vector2 pos, float angle);
	//デストラクタ
	~Bullet()=default;

	void Initialize(Vector2 pos, float angle,float radius);

	void Render();

	void Update();

	void SetActive(bool value);

	Vector2 Position() {
		return _position;
	}
	Vector2 size() {
		return _size;
	}

    float* Radius()
	{
		return radius;
	}

private:
	Vector2 _position;	//座標
	Vector2 _size;		//大きさ
	Vector2 _velocity;	//加速度
	float _radius;
	float* radius;
	int img;			//画像
	bool isActive;		//表示非表示
};
