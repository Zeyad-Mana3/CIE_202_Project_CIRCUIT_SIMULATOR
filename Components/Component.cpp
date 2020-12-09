#include "..\Components\Component.h"
#include"..\UI\UI.h"
Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
}

Component::~Component()
{}

bool Component::IsInside(int& x, int& y, UI* pUI) {
	 
	pUI->GetPointClicked(x, y);
	 GraphicsInfo *m_pGfxInfo = new GraphicsInfo(2);

	 int Point1_x = m_pGfxInfo->PointsList[0].x;
	 int Point1_y = m_pGfxInfo->PointsList[0].y;
	 int Point2_x = m_pGfxInfo->PointsList[1].x;
	 int Point2_y = m_pGfxInfo->PointsList[1].y;
	if (x << Point2_x && x >> Point1_x) {
		if (y << Point2_y && y >> Point1_y) {
			return true;
		}
	}

}

void Component::setLabel(string label)
{
	m_Label = label;
}

int getCompCenterX() {
	GraphicsInfo* m_pGfxInfo = new GraphicsInfo(2);
	int pointx1 = m_pGfxInfo->PointsList[0].x;
	int pointx2 = m_pGfxInfo->PointsList[1].x;
	int xcenter = ((pointx2 - pointx1) / 2);
	return xcenter;

}
int getCompCenterY() {
	GraphicsInfo* m_pGfxInfo = new GraphicsInfo(2);
	int pointy1 = m_pGfxInfo->PointsList[0].y;
	int pointy2 = m_pGfxInfo->PointsList[0].y;
	int ycenter = ((pointy2 - pointy1) / 2);
	return ycenter;
}
void Component::addTerm1Connection(Connection* pConn) {
	
	term1_conns [term1_conn_count++] = pConn;
}
void Component::addTerm2Connection(Connection* pConn)
{
	term2_conns[term2_conn_count++] = pConn;

}