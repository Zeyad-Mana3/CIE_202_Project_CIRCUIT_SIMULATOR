#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddConnection.h"
#include "ActionAddBuzzer.h"
#include "ActionAddGround.h"
#include "ActionAddSwitch.h"
#include "Components/Component.h"
#include"ActionLoad.h"
#include "ActionEditLabel.h"
#include "ActionSave.h"
#include <iostream>
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	IsSimulation = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i<MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_BULB:
			pAct = new ActionAddBulb(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionAddConnection(this);
			break;
		case EDIT_LABEL:
			pAct = new ActionEditLabel(this);
			break;


		// TODO: Add remaining actions
		case SAVE:
			pAct = new saveAction(this);
			break;
		case LOAD:
			pAct = new ActionLoad(this);
			cout << "load";
			break;
		

		case EXIT:
			pUI->ClearDrawingArea();
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////
int ApplicationManager::getCompCount() const {
	return CompCount;
}

Component** ApplicationManager::getCompList()
{
	return CompList;
}

void ApplicationManager::UpdateInterface()
{
	for(int i=0; i<CompCount; i++)
		CompList[i]->Draw(pUI);
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

Component* ApplicationManager::GetComponentByCordinates(int &x, int &y) {
	
	for (int i = 0; i < getCompCount(); i++)
	{
		if (CompList[i]->IsInside(x, y, GetUI()) == true)
			return CompList[i];

	}
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	return true;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
	}
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return 0;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	// TODO
}

void ApplicationManager::DeleteCompS()
{
	for (int i = 0; i < C_S; i++)
	{
		for (int j = 0; j < CompCount; j++)
		{
			if (CompS[i] == CompList[j])
			{
				for (int k = 0; k < CompCount; k++) 
					{
					if (CompList[k]->getCompType() == CON) 
								pUI->DeleteConn(*(CompList[j]->m_pGfxInfo));
					}
				pUI->DeleteComp(*(CompList[j]->m_pGfxInfo));
				CompList[j] = NULL;
				break;
			}

		}
	}

}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	// TODO
}