#pragma once
#include<vector>
#include<string.h>
#include"Vector2.h"

struct TileHitInfo
{
	bool _hitx; //X方向に衝突しているか
	bool _hity; //Y方向に衝突しているか
	int _no;    //タイルマップの番号
};
class TileMap
{
public:
	//初期化
	void Start();

	//描画
	void Render();

	//現在位置＋サイズ+verocityから現在の衝突情報を取得する
	TileHitInfo FindTileHitInfo(const Vector2& pos, const Vector2& size, const Vector2& velocity);

private:
	//タイルマップの衝突判定を行う
	int TileCollision(const Vector2& pos, const Vector2& size, const Vector2& velocity);

	//文字列を分割する
	std::vector<int>Split(const std::string&str, char delim = ',');

	//タイルマップの情報
	////　int [][]←二次元配列と同等の書き方
	std::vector<std::vector<int>>_map;

	//タイルマップの画像
	int _mapgrp;

	//タイルマップのサイズ
	int _tileSize;
};