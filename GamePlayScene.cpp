#include "GamePlayScene.h"
#include<DxLib.h>

GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
	_boss.Initialize();
}

void GamePlayScene::update()
{
	_boss.Update();

	_boss.Render();
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
