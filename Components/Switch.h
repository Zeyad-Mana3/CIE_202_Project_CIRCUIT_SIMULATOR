#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);
	Switch::Switch(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Switch
	CompType getCompType();
	int GetOutStatus();
	void setInputStatus(STATUS s);
	double getSourceVoltage(TerminalNum Term);
	int GetInputStatus();
	virtual void Operate();
	CompType getCompType();

};

