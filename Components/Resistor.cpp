#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
Resistor::Resistor(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}
void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, Selected); //update to draw resistor

}

void Resistor::Operate()
{

}