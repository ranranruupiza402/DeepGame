#pragma once
#include"Vector2.h"
#include"Player.h"
#include"DxLib.h"
class PlayerAttak
{
public:
	void Start(Vector2 pos);

	void Update();

	void Render();

	void SetActive(bool value);

	Vector2 Position()
	{
		return _position;
	}

private:
	Vector2 _position;
	Vector2 _size;
	int img;
	bool isActive;
};