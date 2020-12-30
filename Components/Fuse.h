#pragma once
#include "Component.h"

	class Fuse :public Component
{
public:
	Fuse(GraphicsInfo* r_GfxInfo);
	Fuse::Fuse(GraphicsInfo* r_GfxInfo, double res, double volt);
	virtual void Draw(UI*);	//Draws the Fuse
	double getSourceVoltage(TerminalNum Term);
	int GetOutStatus();
	CompType getCompType();
	int GetInputStatus();
	virtual void Operate();
};

