#include "ActionDelete.h"
#include "ApplicationManager.h"
ActionDelete::ActionDelete(ApplicationManager* pApp):Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{
	UI* pUI = pManager->GetUI();

	pManager->DeleteCompS();



	pUI->PrintMsg("Components Deleted.");
}

void ActionDelete::Undo()
{
}

void ActionDelete::Redo()
{
}
