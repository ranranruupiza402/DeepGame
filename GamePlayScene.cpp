#include "GamePlayScene.h"
#include<DxLib.h>

GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
	
}

void GamePlayScene::update()
{
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
