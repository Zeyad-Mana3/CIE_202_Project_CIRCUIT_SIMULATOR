#include "ActionSave.h"
#include "../CIE-Final-Project/ApplicationManager.h"
#include "Components/Component.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

saveAction::saveAction(ApplicationManager* pApp) : Action(pApp)
{
}

saveAction::~saveAction(void)
{
}

void saveAction::Execute()
{
	UI* pUI = pManager->GetUI();	// Get pointer to the user interface
	Component** compList = pManager->getCompList(); // created getCompList in AppManager that returns the compList
	int compCount = pManager->getCompCount();	//get the count of the Components
	pUI->PrintMsg("Enter the you desired file name: "); // getting the name from the user
	string fileName;
	fileName = pUI->GetSrting(); // getting the name in status bar
	pUI->ClearStatusBar(); //clear status bar after getting the name from the user
	ofstream file;            //creating file with name filename
	file.open(fileName + ".txt");		//opening the file
	file << "No. of Components: \t";	
	file << compCount;   //Printing the no. of components
	string temp;  //storing var.


	for (int i=0; i < compCount; i++)
	{
		cout << compList[i];

		int ind;

		for (int j = 0; j < temp.length(); j++) {
			if (temp.at(j) == '1') {
				ind = j;
				break;
			}
		}
		temp = temp.substr(0, ind) + to_string(i + 1) + temp.substr(ind + 1, temp.length() - ind);
		file << temp;
	}
}

void saveAction::Undo()
{
}

void saveAction::Redo()
{
}
