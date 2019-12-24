#pragma once
#include "AbstractScene.h"
class GamePlayScene:public AbstractScene
{
public:
	const static char*ParameterTagStage;//パラメーターのタグ「ステージ」
	const static char*ParameterTagLevel;//パラメーターのタグ「レベル」
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
};

