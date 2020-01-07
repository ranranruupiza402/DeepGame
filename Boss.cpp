#include "Boss.h"
#include "Define.h";

//������
void Boss::Initialize()
{
	_size = Vector2(32, 32);
	_pos = Vector2(500, 500);
	_velocity = Vector2(1, 0);
	_hp_max = 5000;
	_hp = _hp_max;
	_dir = 1;
	_speed = 5.0;
	_pattern = 0;
	_cnt = 0;
	_waitCnt = 5000;//�~���b�œ���
	_shotspace = 0;
	_startTime = GetNowCount();
	aroundShot = false;
	shot = false;
	air = false;
}

//�`��
void Boss::Render()
{
	DrawBox(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, GetColor(0, 0, 255), FALSE);
}

//�X�V
void Boss::Update()
{

	aroundShot = false;
	shot = false;
	_shotspace++;

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
	default:
		break;
	}

	_elapsedTime = (GetNowCount() - _startTime) / 1000;
}

//���
void Boss::Release()
{

}

//�{�X���ړ�
void Boss::moveField()
{
	_pos.x += _velocity.x;
	if (_elapsedTime >= 1)
	{
 		_pattern = 1;
	}
}

//�ǂ𐶐�
void Boss::createWall()
{
	

	if (_pos.x <= 1124)
	{
		_pos.x += _velocity.x;

		return;
	}


	if (_shotspace % 30 == 0)
	{

		aroundShot = true;
		shot = true;
	}

	_hp -= 10;

	if (_hp <= (_hp_max / 4 == 3))
	{
		_pattern=4;
	}
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

	aroundShot = false;
	
	
	if (_pos.x >= Define::WIN_WIDTH / 2)
	{
		_pos.x -= _velocity.x;
		shot = false;
		return;
	}

	shot = true;

	if (_shotspace% 30 == 0)
	{
		aroundShot = true;
		shot = true;
	}
}

