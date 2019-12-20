#pragma once
#include "AbstractScene.h"
class Title:public AbstractScene
{
public:
	Title(IOnChangedListener*impl,const Parameter&parameter);
	virtual ~Title() = default;
	void updeta()override;
	void draw()override;
};

