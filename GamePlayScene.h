#pragma once
#include "AbstractScene.h"
#include<memory>
#include "Player.h"
#include "TileMap.h"
#include "Boss.h"
#include "BossShot.h"
#include "Lazer.h"
#include"AroundWall.h"

class GamePlayScene:public AbstractScene
{
public:
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
private:
	std::shared_ptr<Player>_player;
	std::shared_ptr<TileMap>_tileMap;
	std::shared_ptr<Boss>_boss;
private:
	//Boss* boss;
	BossShot bossShot;
	Lazer lazer;
	AroundW around;
	int i;
};

