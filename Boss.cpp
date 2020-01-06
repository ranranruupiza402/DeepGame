#include "Boss.h"

//������
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

//�`��
void Boss::Render()
{
	DrawBox(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, GetColor(0, 0, 255), FALSE);
}

//�X�V
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

//���
void Boss::Release()
{

}

//�{�X���ړ�
void Boss::moveField()
{

}

//�ǂ𐶐�
void Boss::createWall()
{
	aroundShot = true;
}

//�n�`����
void Boss::createFloor()
{
	aroundShot = true;
}

//�ǈړ�����e
void Boss::aroundWall()
{
	aroundShot = true;
}

//�r�[���ガ����
void Boss::rollBeam()
{
	aroundShot = true;
}

void Boss::stay()
{
	aroundShot = false;
}

