#include "TitleScene.h"
#include <DxLib.h>
#include"Define.h"
#include"GamePlayScene.h"
#include"Keyboard.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) 
	: AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_E)==1) {
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
