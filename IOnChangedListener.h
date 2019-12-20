#pragma once

#include "eScene.h"

class IOnSceneChangeListener
{
public:
	IOnSceneChangeListener() = default;
	virtual ~IOnSceneChangeListener() = default;
	virtual void onSecenChanged(const eScene scene) = 0;
};