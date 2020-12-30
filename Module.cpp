#include "Module.h"

Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

Module::Module(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}
void Module::Draw(UI* pUI)
{
	//Call output class and pass Module drawing info to it.
	pUI->DrawModule(*m_pGfxInfo, Selected); //update to draw Module

}
CompType Module::getCompType()
{
	return MODULE;
}
double Module::getSourceVoltage(TerminalNum Term)
{
	return 0;
}
int Module::GetInputStatus()
{
	return -1;
}
int Module::GetOutStatus()
{
	return -1;
}

void Module::Operate()
{

}