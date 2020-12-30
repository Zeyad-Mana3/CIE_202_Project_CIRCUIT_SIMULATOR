#pragma once
#include "Component.h"

class Bulb:public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo);
	Bulb::Bulb(GraphicsInfo* r_GfxInfo, double res, double volt);
	int GetOutStatus();
	int GetInputStatus();
	virtual void Draw(UI*);	//Draws the Bulb
	CompType getCompType();
	double getSourceVoltage(TerminalNum Term);
	virtual void Operate();
	CompType getCompType();

};

