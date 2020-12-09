#pragma once
#include "Component.h"

class battery :public Component
{
public:
	battery (GraphicsInfo* r_GfxInfo);
	battery::battery(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the battery
	virtual void Operate();
};
