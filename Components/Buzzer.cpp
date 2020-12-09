#include "Buzzer.h"
Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass Buzzer drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, Selected); //update to draw Buzzer

}

void Buzzer::Operate()
{

}