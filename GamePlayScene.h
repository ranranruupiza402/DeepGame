#pragma once
#include "AbstractScene.h"
#include<memory>
#include "TileMap.h"
#include "Boss.h"
#include "BossShot.h"
#include"Player.h"
#include"PlayerAttak.h"

class GamePlayScene:public AbstractScene
{
public:
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
	
private:
	Player _player;
	Boss _boss;
	BossShot bossShot;
	TileMap _tileMap;
	int i;
};

