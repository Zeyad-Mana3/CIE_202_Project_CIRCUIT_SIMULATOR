#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

Switch::Switch(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}
void Switch::Draw(UI* pUI)
{
	//Call output class and pass Switch drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, Selected); //update to draw Switch

}

void Switch::Operate()
{

}