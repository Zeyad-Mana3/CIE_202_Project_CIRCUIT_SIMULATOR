#include "..\Connections\Connection.h""
#include "../ApplicationManager.h"
#include "ActionAddConnection.h"
#include"..\UI\UI.h"
#include "..\Components\Component.h"

ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{


}

ActionAddConnection::~ActionAddConnection(void)
{



}

void ActionAddConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//choose the first comp
	while (pManager->GetComponentByCordinates(Cx1, Cy1) == NULL)
	{
		pUI->PrintMsg("Select a component to add connection");

		pUI->GetPointClicked(Cx1, Cy1);
	}
	Component* comp1 = pManager->GetComponentByCordinates(Cx1, Cy1);

	
	// choose the scound comp

	pUI->PrintMsg("Select the second component to add connection");
	pUI->GetPointClicked(Cx2, Cy2);
	// error massage when the user dosen't choose new comp
	while (pManager->GetComponentByCordinates(Cx2, Cy2) == pManager->GetComponentByCordinates(Cx1, Cy1))
	{
		pUI->PrintMsg("you didn't choose another comp, please Select different one");

		pUI->GetPointClicked(Cx2, Cy2);
		while (pManager->GetComponentByCordinates(Cx1, Cy1) == NULL)
		{
		
			pUI->GetPointClicked(Cx2, Cy2);
			
			
		}

	}
	Component* comp2 = pManager->GetComponentByCordinates(Cx2, Cy2);
	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners


	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	pGInfo->PointsList[0].x = comp1->m_pGfxInfo->PointsList[1].x;

	pGInfo->PointsList[0].y = comp1->m_pGfxInfo->PointsList[1].y;

	pGInfo->PointsList[1].x = comp2->m_pGfxInfo->PointsList[0].x;
	pGInfo->PointsList[1].y = comp2->m_pGfxInfo->PointsList[0].y;


	//Connection* con = new Connection(pGInfo, comp1, comp2);
	//pManager->AddConnection(con);
	//comp1->addTerm1Connection(con);
	//comp2->addTerm2Connection(con);


	}
	
	


void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}

