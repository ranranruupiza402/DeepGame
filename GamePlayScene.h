#pragma once
#include "AbstractScene.h"
class GamePlayScene:public AbstractScene
{
public:
	const static char*ParameterTagStage;//�p�����[�^�[�̃^�O�u�X�e�[�W�v
	const static char*ParameterTagLevel;//�p�����[�^�[�̃^�O�u���x���v
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
};

