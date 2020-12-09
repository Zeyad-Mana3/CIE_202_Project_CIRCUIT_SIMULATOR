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

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass Bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, Selected); //update to draw Bulb

}

void Bulb::Operate()
{

}