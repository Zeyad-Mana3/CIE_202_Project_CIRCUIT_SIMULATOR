#include "Fuse.h"
Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
Fuse::Fuse(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}
void Fuse::Draw(UI* pUI)
{
	//Call output class and pass Fuse drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, Selected); //update to Fuse Fuse

}
double Fuse::getSourceVoltage(TerminalNum Term)
{
	return 0;
}
int Fuse::GetOutStatus() {
	return -1;
}
CompType Fuse::getCompType()
{
	return FUSE;
}
int Fuse::GetInputStatus()
{
	return -1;
}

void Fuse::Operate()
{

}

CompType Fuse::getCompType()
{
	return FUSE;
}
