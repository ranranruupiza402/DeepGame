#pragma once
#include<DxLib.h>
#include"Vector2.h"

class Boss
{
public:
	//初期化
	void Initialize();

	//描画
	void Render();

	//更新
	void Update();

	//解放
	void Release();

	//bossの行動パターン用
	void moveField();
	void createWall();
	void createFloor();
	void aroundWall();
	void rollBeam();
	void stay();

	//座標を返す
	Vector2 Position()
	{
		return _pos;
	}

	//大きさを返す
	Vector2 Size()
	{
		return _size;
	}	

	//現在の行動パターンを返す
	int Pattern()
	{
		return _pattern;
	}

private:
	int _cnt;			//カウンタ
	int _pattern;		//行動パターン
	int _dir;			//向いている方向
	int _hp;			//体力
	int _hp_max;		//最大体力
	int _img;			//画像
	Vector2 _pos;		//座標
	Vector2 _size;		//大きさ
	double _speed;		//速さ
	bool aroundShot;	//八方位に弾を撃つフラグ

};
