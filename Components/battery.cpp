#include "battery.h"
#include "Component.h"

battery::battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
battery::battery(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}

void battery::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->Drawbattery(*m_pGfxInfo, Selected); //update to draw battery

}
CompType battery::getCompType()
{
	return BATTERY;
}
double battery::getSourceVoltage(TerminalNum Term) 
{
	if (Term == TERM1) {
		return sourceVoltage;
	}
	else {
		return (-sourceVoltage);
	}
}
int battery::GetOutStatus() {
	return -1;
}
int battery::GetInputStatus()
{
	return -1;
}

void battery::Operate()
{

}