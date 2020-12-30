#include "ActionDisSelection.h"
#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddConnection.h"
#include "ActionAddBuzzer.h"
#include "ActionAddGround.h"
#include "ActionAddSwitch.h"
#include "UI\UI.h"
#include"ApplicationManager.h"
#include "Components/Component.h"



ActionDisSelection::ActionDisSelection(ApplicationManager* pApp) : Action(pApp)
{

}

ActionDisSelection::~ActionDisSelection(void)
{


}

void ActionDisSelection::Execute()
{



	UI* pUI = pManager->GetUI();
	
	for (int i = 0; i < pManager->CompCount; i++)
		if (pManager->CompList[i]->Selected == true)
			pManager->CompList[i]->Selected = false;
}

void ActionDisSelection::Undo()
{

}
void ActionDisSelection::Redo()
{


}