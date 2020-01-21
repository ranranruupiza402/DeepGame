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
			Collition(_player->Position(), _player->Size(), _posList[i], bossShot->Radius());
			//_posList.push_back(bossShot->Position());
			/*_posList[i]=_posList.back();
			_posList.pop_back();
			_posList.clear*/
		}
		_posList.clear();
	}

	if (_boss.Shot() == true && _boss.Pattern() == 1)
	{
		int posNum = GetRand(4);
		bossShot->CreateWall(_boss.Position(), &posNum);
	}

	if (_boss.Shot() == true && _boss.Pattern() == 3&&bossShot->BulletCount()<=4)
	{
			bossShot->AroundWall(_boss.Position());
	}

	//if(i%60==0)
	//{
	//}

	_player->Render();
	_boss.Render();
	bossShot->Render();

	DrawBox(0, 685, Define::WIN_WIDTH, Define::WIN_HEGHT, GetColor(0, 255, 255), FALSE);
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}

bool GamePlayScene::Collition(const Vector2 plPos,Vector2 size,const Vector2 bulletPos,float *bulletRad)
{
	if (plPos.x <= bulletPos.x + *bulletRad && //¶
		plPos.x + size.x >= bulletPos.x - *bulletRad && //‰E
		plPos.y <= bulletPos.y + *bulletRad && //ã
		plPos.y + size.y >= bulletPos.y - *bulletRad)//‰º
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
