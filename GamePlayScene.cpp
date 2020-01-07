#include "GamePlayScene.h"
#include<DxLib.h>
#include "Define.h"


GamePlayScene::GamePlayScene(IOnSceneChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
	_boss.Initialize();
	i = 0;
}

void GamePlayScene::update()
{
	i++;

	_boss.Update();
	bossShot.Update();

	if (_boss.AroundShot() == true)
	{
		for (int i = 1; i <= 360; i += 45)
		{
			bossShot.Shot(_boss.Position(), i);
		}
	}

	_boss.Render();
	bossShot.Render();

	DrawBox(10+i, 600,40+i ,640 , GetColor(0, 255, 255), FALSE);

	DrawBox(0, 685, Define::WIN_WIDTH, Define::WIN_HEGHT, GetColor(0, 255, 255), FALSE);
}

void GamePlayScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "GamePlay‚Å‚·");
}
