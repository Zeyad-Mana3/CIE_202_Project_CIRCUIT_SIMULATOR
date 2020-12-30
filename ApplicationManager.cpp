#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddConnection.h"
#include "ActionAddBuzzer.h"
#include "ActionAddGround.h"
#include "ActionAddSwitch.h"
#include "ActionDisSelection.h"
#include "Components/Component.h"
#include"ActionLoad.h"
#include "ActionEditLabel.h"
#include "ActionSave.h"
#include "ActionSelection.h"
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
		case SELECT:
			pAct = new ActionSelection(this);
			break;
		case DisSelect:
			pAct = new ActionDisSelection(this);

		

		case EXIT:
			pUI->ClearDrawingArea();
			break;
		case SIM_MODE:
			ValidateCircuit();
            break;
		case DSN_MODE:
			pUI->setAppMode(DESIGN);
			pUI->PrintMsg("Design Mode");
			//to be revised
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
		if (CompList[i]->selected(x, y)== true)
			return CompList[i];

	}
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	Ground* item= nullptr;
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] == item) // check the exsistance of the ground 
		{
			for (int j = 0; j < CompCount; j++) {
				if (CompList[j]->term1_conn_count == 1 && CompList[j]->term2_conn_count == 1) // check if the circute is not parallel
				{
					for (int m = 0; m < CompCount; m++)
					{
						if (CompList[m]->term1_conn_count == 0 || CompList[m]->term2_conn_count == 0) // check if the circute is connected 
						{
							return true;
						}
					}

				}
			}

		}
		else {
			return FALSE;

		}
}
	
void ApplicationManager::switchON() {

	

	for (int j = 0; j < CompCount; j++) {
		for (int i = 0; i < CompCount; i++) {
			if (CompList[i]->getCompType() != SWITCH) {
				if (CompList[i]->getCompType() == CON) {
					CompList[i]->Operate();
				}

			}
		}
		for (int i = 0; i < CompCount; i++) {
			if (CompList[i]->getCompType() != SWITCH) {
				CompList[i]->Operate();
			}
		}

	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {

	if (!ValidateCircuit()) {
		UI* pUI = GetUI();
		pUI->PrintMsg("Circuit is not valid!");

	}
	else {
		this->IsSimulation = true;

		pUI->setAppMode(SIMULATION);
		switchON();
		pUI->PrintMsg("Simulation Mode");
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
	}
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() //RANA
{
	// TODO
	double totalRes = 0;
	double totavoltages = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getCompType() == GROUND)
			for (int j = 0; j < (CompCount - 1); i++)
			{
				totalRes = totalRes + CompList[i]->getResistance();
				if (CompList[j]->getCompType() == BATTERY)
					totavoltages = totavoltages + CompList[i]->getSourceVoltage(TERM1);
			}
	}
	double CURRENT = totavoltages/totalRes;
	 
	return CURRENT;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) //rana
{
	

}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete pUI;
}