#include "ActionSelection.h"
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



ActionSelection::ActionSelection(ApplicationManager* pApp): Action (pApp)
{
	
}

ActionSelection::~ActionSelection(void)
{
	 
	
}

void ActionSelection::Execute()
{
	


	UI* pUI = pManager->GetUI();
	//	while (pManager->GetComponentByCordinates(Cx, Cy) == NULL)
	//	{
	Component* item;
	pUI->GetPointClicked(Cx, Cy);
	if (pManager->GetComponentByCordinates(Cx, Cy) != NULL)
	{
		item = pManager->GetComponentByCordinates(Cx, Cy); // edited by zeyad
		item->Selected = true; // problem at running 
		item->Draw(pUI);
	}
	else {
		//if (item->Selected == true) {
		//	item->Selected = false;
		//}

		//else {
			item->Selected == true;
		
	}


	
}

void ActionSelection::Undo()
{

}
void ActionSelection::Redo()
{


}