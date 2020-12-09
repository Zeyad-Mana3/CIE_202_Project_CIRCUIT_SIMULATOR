#include "Ground.h"
Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}
Ground::Ground(GraphicsInfo* r_GfxInfo, double res, double volt) : Component(r_GfxInfo)
{
	resistance = res;
	sourceVoltage = volt;
}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass Ground drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, Selected); //update to draw Ground

}

void Ground::Operate()
{

}