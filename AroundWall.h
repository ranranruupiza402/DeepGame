#pragma once
#include <DxLib.h>
#include "Define.h"
#include "Vector2.h"

//画面の範囲に沿って動く、PlayerとX座標が重なったら落ちて来る弾
class AroundW
{
public:
	//こんすと
	AroundW();
	//デストラ
	~AroundW();

	//初期化
	void Initialize(Vector2 pos);
	//描画
	void Render();
	//更新
	void Update();
	
	void Around();

	void SetActive(bool value);

	void setSamePlPos(bool value);

	Vector2 Position()
	{
		return _pos;
	}

	int SpownTime()
	{
		return _spown;
	}

private:
	Vector2 _pos;	//座標
	Vector2 _plPos; //playerの座標
	Vector2 _vel;	//加速度
	int _spown;	    //スポーンしてからの時間
	int cnt;        //経過時間算出用
	bool isActive;	//表示非表示
	bool samePlPos;

};