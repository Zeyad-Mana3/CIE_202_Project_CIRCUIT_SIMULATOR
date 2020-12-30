#include "Bulb.h"


Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
Bulb::Bulb(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}
int Bulb::GetOutStatus() {
	if (HIGH)
	return 1;
	if (LOW)
		return 0;
}
int Bulb::GetInputStatus()
{
	return -1;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass Bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, Selected); //update to draw Bulb

}
CompType Bulb::getCompType()
{
	return BULB;
}
double Bulb::getSourceVoltage(TerminalNum Term)
{
	return 0;
}
void Bulb::Operate()
{

}