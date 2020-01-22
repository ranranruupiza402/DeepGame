#include "GamePlayScene.h"
#include<DxLib.h>
#include "TileMap.h"
#include "Define.h"

using namespace std;
GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl, parameter), _tileMap(make_shared<TileMap>())
{	
	_tileMap->Start();
	_boss.Initialize();
	_player = make_shared<Player>();
	bossShot = make_shared<BossShot>();
	_player->Start();
	//i = 0;
	bullRad = &bulletRad;
}

void GamePlayScene::update()
{
	_player->Update();
	auto info = _tileMap->FindTileHitInfo(_player->Position(),_player->Size(),_player->Velocity());
	_player->UpdatePosition(info._hitx, info._hity);
	_tileMap->Render();
	//i++;
	_boss.Update();

	bossShot->Update();

	if (_boss.AroundShot() == true)
	{
		for (float i = 1; i <= 360; i += 45)
		{
			bossShot->ShotBullet(_boss.Position(), i,bullRad);
			
		}
		for (int i = 0; i < bossShot->_shotList.size(); i++)
		{
			_posList.push_back(bossShot->Position(i));
		}
		for (int i = 0;i<_posList.size(); i++)
		{
		//	Collition(_player->Position(), _player->Size(), _posList[i], bossShot->Radius());

			if (CircleCollition(_player->Position(), _player->Size(), _player->Radius(), _posList[i], bulletRad))
			{
				
			}
		}
		_posList.clear();
	}

	if (_boss.Shot() == true && _boss.Pattern() == 1)
	{
		int posNum = GetRand(4);
		bossShot->CreateWall(_boss.Position(), &posNum);

		for (int i = 0; i < bossShot->_crewallList.size(); i++)
		{
			_crewallPosList.push_back(bossShot->CWPosition(i));
			_crewallSizeList.push_back(bossShot->CWSize(i));
		}
		for (int i = 0; i < _crewallPosList.size(); i++)
		{
			if (BoxCollition(_player->Position(), _player->Size(), _crewallPosList[i], _crewallSizeList[i]))
			{

			}
		}
		_crewallPosList.clear();
		_crewallSizeList.clear();
	}

	if (_boss.Shot() == true && _boss.Pattern() == 3&&bossShot->BulletCount()<=4)
	{
			bossShot->AroundWall(_boss.Position());

			for (int i = 0; i < bossShot->_aroundList.size(); i++)
			{
				_aroundPosList.push_back(bossShot->AWPosition(i));
			}
			for (int i = 0; i < _aroundPosList.size(); i++)
			{
				if (CircleCollition(_player->Position(), _player->Size(), _player->Radius(), _aroundPosList[i], bulletRad))
				{

				}
			}
			_aroundPosList.clear();
	}

	_player->Render();
	_boss.Render();
	bossShot->Render();

	DrawBox(0, 685, Define::WIN_WIDTH, Define::WIN_HEGHT, GetColor(0, 255, 255), FALSE);
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlayです");
}

bool GamePlayScene::Collition(const Vector2 plPos,Vector2 size,const Vector2 bulletPos,float *bulletRad)
{
	if (plPos.x <= bulletPos.x + *bulletRad && //左
		plPos.x + size.x >= bulletPos.x - *bulletRad && //右
		plPos.y <= bulletPos.y + *bulletRad && //上
		plPos.y + size.y >= bulletPos.y - *bulletRad)//下
	{
		printf("true");
		//DrawCircle(plPos.x, plPos.y, 5, GetColor(255, 255, 255), TRUE);
    	return true;
	}
	else
	{
		return false;
	}
}

bool GamePlayScene::CircleCollition(const Vector2 plPos, Vector2 size, float plRad, const Vector2 bulletPos, float bulletRad)
{
	auto plcentor = plPos + size / 2;

	auto x = abs((plcentor.x + plRad) - (bulletPos.x + bulletRad));
	auto y = abs((plcentor.y + plRad) - (bulletPos.y + bulletRad));

	if (x*x + y * y <= (plRad + bulletRad)*(plRad + bulletRad))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GamePlayScene::BoxCollition(const Vector2 plPos, Vector2 size, Vector2 bulletPos, Vector2 bulletSize)
{
	auto dx = abs((plPos.x + size.x / 2) - (bulletPos.x + bulletSize.x / 2));
	auto dy = abs((plPos.y + size.y / 2) - (bulletPos.y + bulletSize.y / 2));

	if (dx <= (size.x + bulletSize.x) / 2 && dy <= (size.y + bulletSize.y) / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
