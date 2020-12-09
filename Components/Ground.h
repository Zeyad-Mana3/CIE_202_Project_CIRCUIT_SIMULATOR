#pragma once
#include "Component.h"

	class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo);
	Ground::Ground(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Ground
	virtual void Operate();
};

