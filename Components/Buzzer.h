#pragma once
#include "Component.h"

	class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Buzzer
	CompType getCompType();
	double getSourceVoltage(TerminalNum Term);
	int GetOutStatus();
	int GetInputStatus();
	virtual void Operate();
};


