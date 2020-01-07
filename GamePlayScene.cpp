#include "GamePlayScene.h"
#include<DxLib.h>

using namespace std;
GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
	_player = make_shared<Player>();
}

void GamePlayScene::update()
{
	_player->update();
}

void GamePlayScene::draw()
{
	_player->draw();
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
