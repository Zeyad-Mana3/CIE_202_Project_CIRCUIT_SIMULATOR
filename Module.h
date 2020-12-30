#pragma once
#include "Components/Component.h"

class Module :public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);
	Module::Module(GraphicsInfo* r_GfxInfo, double res, double volt);
		virtual void Draw(UI*);	//Draws the Module
		CompType getCompType();
		double getSourceVoltage(TerminalNum Term);
		int GetInputStatus();
		int GetOutStatus();
		virtual void Operate();
};


