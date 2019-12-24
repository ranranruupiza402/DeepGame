#include "TitleScene.h"
#include <DxLib.h>
#include"Define.h"
#include"GamePlayScene.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) 
	: AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		Parameter parameter;
		const bool stackClear = false;
		_implSceneChanged->onSceneChanged(eScene::GamePlay, parameter, stackClear);
		return;
	}
}

void TitleScene::draw()
{
	DrawString(Define::WIN_WIDTH/2, Define::WIN_HEGHT/2, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255, 255, 255));
}
