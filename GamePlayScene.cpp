#include "GamePlayScene.h"
#include<DxLib.h>
#include "TileMap.h"

using namespace std;
GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
	//_player = make_shared<Player>();
	_tileMap = make_shared<TileMap>();
}

void GamePlayScene::update()
{
	//_player->update();
	//auto info = _tileMap->FindTileHitInfo(_player.Position(),_palyer.Size(),_player.Velocity());

	_tileMap->draw();
}

void GamePlayScene::draw()
{
	//_player->draw();
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
