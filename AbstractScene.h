#pragma once

#include "IOnChangedListener.h"
#include "Parameter.h"

class IOnChangedListener;

class AbstractScene
{
protected:
	IOnChangedListener*_implSceneChanged;
public:
	AbstractScene(IOnChangedListener*impl, const Parameter& parameter);
	virtual ~AbstractScene() = default;
	virtual void updeta();
	virtual void draw();
};

