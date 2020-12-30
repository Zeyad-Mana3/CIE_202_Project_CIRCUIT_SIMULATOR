#include "Connection.h"
#include "../Components/Component.h"


Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo);
}

Component* Connection::getOtherComponent(Component* Cmpnt) //rana
{
	Connection* conn1;
	//Cmpnt = conn1->Comp1;
	conn1 = Cmpnt->term1_conns[0];
	return conn1->Comp2;
}

