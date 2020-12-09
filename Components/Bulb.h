#pragma once
#include "Component.h"

class Bulb:public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo);
	Bulb::Bulb(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Bulb
	virtual void Operate();
};

