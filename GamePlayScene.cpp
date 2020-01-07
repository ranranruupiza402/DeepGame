#include "GamePlayScene.h"
#include<DxLib.h>
#include "TileMap.h"
#include "Define.h"

using namespace std;
GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl, parameter)
{
	_player.Start();
	_tileMap.Start();
	_boss.Initialize();
	i = 0;
}

void GamePlayScene::update()
{
	i++;
	_player.Update();
	auto info = _tileMap.FindTileHitInfo(_player.Position(), _player.Size(), _player.Velocity());
	_player.UpdatePosition(info._hitx, info._hity);
	_boss.Update();
	bossShot.Update();

	if (_boss.AroundShot() == true)
	{
		for (int i = 1; i <= 360; i += 45)
		{
			bossShot.Shot(_boss.Position(), i);
		}
	}

	_tileMap.Render();
	_player.Render();
	_boss.Render();
	bossShot.Render();

	DrawBox(10+i, 600,40+i ,640 , GetColor(0, 255, 255), FALSE);

	DrawBox(0, 685, Define::WIN_WIDTH, Define::WIN_HEGHT, GetColor(0, 255, 255), FALSE);
	DrawFormatString(20, 50, GetColor(255, 255, 255), "HitX:%d hitY:%d no:%d", info._hitx, info._hity, info._no);
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
	
}
