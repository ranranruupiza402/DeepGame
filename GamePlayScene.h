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

	bool Collition(const Vector2 plPos, Vector2 size, const Vector2 bulletPos, float *bulletRad);
	bool CircleCollition(const Vector2 plPos, Vector2 size, float plRad, const Vector2 bulletPos, float bulletRad);
	bool BoxCollition(const Vector2 plPos, Vector2 size, Vector2 bulletPos, Vector2 bulletSize);

	void update()override;
	void draw()override;
private:
	std::shared_ptr<Player>_player;
	std::shared_ptr<TileMap>_tileMap;
	std::shared_ptr<Boss>_boss;
	std::shared_ptr<BossShot>bossShot;
private:
	std::vector<Vector2>_posList; 
	std::vector<Vector2>_aroundPosList;
	std::vector<Vector2>_crewallPosList;
	std::vector<Vector2>_crewallSizeList;
	
	//Boss* boss;
	Lazer lazer;
	AroundW around;
	//int i;

	float* bullRad;
	float bulletRad = 8.0f;
};

