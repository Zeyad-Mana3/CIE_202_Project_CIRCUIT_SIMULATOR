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

void Fuse::Operate()
{

}