#pragma once
#include "Component.h"

	class Fuse :public Component
{
public:
	Fuse(GraphicsInfo* r_GfxInfo);
	Fuse::Fuse(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Fuse
	virtual void Operate();
};

