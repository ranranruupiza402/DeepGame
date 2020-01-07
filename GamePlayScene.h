#pragma once
#include "AbstractScene.h"
<<<<<<< HEAD
#include<memory>
//#include "Player.h"
#include "TileMap.h"
=======
#include "Boss.h"
#include "BossShot.h"
>>>>>>> tatsuya

class GamePlayScene:public AbstractScene
{
public:
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
<<<<<<< HEAD
private:
	//std::shared_ptr<Player>_player;
	std::shared_ptr<TileMap>_tileMap;
=======

private:
	Boss _boss;
	BossShot bossShot;
	int i;
>>>>>>> tatsuya
};

