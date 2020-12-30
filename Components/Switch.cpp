#include "Switch.h"
#include "Component.h"

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
CompType Switch::getCompType()
{
	return SWITCH;
}
int Switch::GetOutStatus() {
	return -1;
}
 double Switch::getSourceVoltage(TerminalNum Term)
 {
	 return 0;
 }
 int Switch::GetInputStatus()
 {
	 if (HIGH)
		 return 1;
	 if (LOW)
		 return 0;
 }
void Switch::Operate()
{

}