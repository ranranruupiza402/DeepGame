#pragma once
#include<DxLib.h>
#include"Vector2.h"
class Boss
{
public:
	//初期化
	void Start();

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

	//座標を返す
	Vector2 Position()
	{
		return _position;
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

	bool AroundShot()
	{
		return aroundShot;
	}

	bool Shot()
	{
		return shot;
	}

private:
	int _cnt;			//次の行動までのカウンタ
	int _waitCnt;       //攻撃の後隙
	int _pattern;		//行動パターン
	int _dir;			//向いている方向
	int _hp;			//体力
	int _hp_max;		//最大体力
	int _img;			//画像
	int _startTime;		//行動開始した時間
	int _elapsedTime;	//現在に経過時間
	int _shotspace;		//弾の発射間隔用
	Vector2 _position;		//座標
	Vector2 _size;		//大きさ
	Vector2 _velocity;	//加速度
	double _speed;		//速さ
	bool aroundShot;	//八方位に弾を撃つフラグ
	bool shot;			//弾幕を射出
	bool air;           //空中にいるか
};
