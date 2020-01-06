#include "Boss.h"

//初期化
void Boss::Initialize()
{
	_size = Vector2(32, 32);
	_pos = Vector2(100, 100);
	_hp_max = 5000;
	_hp = _hp_max;
	_dir = 1;
	_speed = 5.0;
	_pattern = 0;
	_cnt = 0;
	aroundShot = false;
}

//描画
void Boss::Render()
{
	DrawBox(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, GetColor(0, 0, 255), FALSE);
}

//更新
void Boss::Update()
{
	switch(_pattern)
	{
	case 0://movePos
		moveField();
		break;
	case 1://moveWall
		createWall();
		break;
	case 2://moveFloor
		createFloor();
		break;
	case 3://aroundWall
		aroundWall();
		break;
	case 4://rollBeam
		rollBeam();
		break;
	case 5://stay
		stay();
		break;
	default:
		break;
	}
}

//解放
void Boss::Release()
{

}

//ボスが移動
void Boss::moveField()
{

}

//壁を生成
void Boss::createWall()
{
	aroundShot = true;
}

//地形生成
void Boss::createFloor()
{
	aroundShot = true;
}

//壁移動する弾
void Boss::aroundWall()
{
	aroundShot = true;
}

//ビーム薙ぎ払い
void Boss::rollBeam()
{
	aroundShot = true;
}

void Boss::stay()
{
	aroundShot = false;
}

