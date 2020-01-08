#include "GamePlayScene.h"
#include<DxLib.h>
#include "TileMap.h"
#include "Define.h"

using namespace std;
GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl, parameter)
{
	
	_tileMap = make_shared<TileMap>();
	_boss.Initialize();
	_player.Start();
	i = 0;
}

void GamePlayScene::update()
{
	//_player->update();
	//auto info = _tileMap->FindTileHitInfo(_player.Position(),_palyer.Size(),_player.Velocity());

	//_tileMap->draw();
	i++;
	_player.Update();
	_boss.Update();
	bossShot.Update();

	if (_boss.AroundShot() == true)
	{
		for (int i = 1; i <= 360; i += 45)
		{
			bossShot.Shot(_boss.Position(), i);
		}
	}

	_player.Render();
	_boss.Render();
	bossShot.Render();

	DrawBox(10+i, 600,40+i ,640 , GetColor(0, 255, 255), FALSE);

	DrawBox(0, 685, Define::WIN_WIDTH, Define::WIN_HEGHT, GetColor(0, 255, 255), FALSE);
}

void GamePlayScene::draw()
{
	//_player->draw();
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
