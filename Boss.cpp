#include "Boss.h"
#include "Define.h"

//������
void Boss::Start()
{
	_size = Vector2(32, 32);
	_position = Vector2(500, 500);
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
	_img = LoadGraph("Texture\\boss.png");
}

//�`��
void Boss::Render()
{
	SetTransColor(255, 255, 0);
	DrawGraph(_position.x, _position.y, _img, TRUE);
	DrawBox(_position.x, _position.y, _position.x + _size.x, _position.y + _size.y, GetColor(0, 0, 255), FALSE);
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
	_position.x += _velocity.x;
	if (_elapsedTime >= 1)
	{
 		_pattern = 1;
	}
}

//�ǂ𐶐�
void Boss::createWall()
{
	aroundShot = false;

	if (_shotspace % 30==0)
	{
		aroundShot = true;
	}

	if (_shotspace % 120 == 0)
	{
		shot = true;
		aroundShot = false;
	}

	if (_position.x <= 1124)
	{
		_position.x += _velocity.x;

		return;
	}

	_hp -= 1;

	if (_hp <= (_hp_max / 5 *3))
	{
		_pattern=3;
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
	if (_shotspace % 30 == 0)
	{
		aroundShot = true;
	}

	if(_position.x<=Define::WIN_WIDTH-200)
	{
		_position.x += _velocity.x;
		shot = false;
		return;
	}

	if (_shotspace % 120 == 0)
	{
		shot = true;
		aroundShot = false;
	}

	_hp -= 1;

	if (_hp <= (_hp_max / 4))
	{
		_pattern = 4;
	}
}

//�r�[���ガ����
void Boss::rollBeam()
{

	aroundShot = false;
	
	
	if (_position.x >= Define::WIN_WIDTH / 2)
	{
		_position.x -= _velocity.x;
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

