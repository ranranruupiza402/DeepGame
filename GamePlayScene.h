#pragma once
#include "AbstractScene.h"
#include<memory>
//#include "Player.h"
#include "TileMap.h"

class GamePlayScene:public AbstractScene
{
public:
	GamePlayScene(IOnSceneChangedListener*impl,const Parameter&parameter);
	virtual~GamePlayScene()=default;

	void update()override;
	void draw()override;
private:
	//std::shared_ptr<Player>_player;
	std::shared_ptr<TileMap>_tileMap;
};

