#pragma once
#include "Component.h"

	class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Buzzer
	virtual void Operate();
};


