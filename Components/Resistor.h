#pragma once
#include "Component.h"

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo *r_GfxInfo);
	Resistor::Resistor(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
};
