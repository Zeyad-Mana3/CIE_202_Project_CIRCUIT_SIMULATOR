#include "ActionLoad.h"
#include <string>
#include<fstream>
#include<iostream>
#include "ApplicationManager.h"
#include "Components\Component.h"
#include <windows.h>
#include "ApplicationManager.h"
#include "Components\Component.h"
#include < windows.h >
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

ActionLoad::ActionLoad(ApplicationManager* pApp) : Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{



}

void ActionLoad::Execute()
{
	UI* pUI = pManager->GetUI();
	Component** compList = pManager->getCompList();
	int compCount = pManager->getCompCount();
	pUI->PrintMsg("Type the file name you want to load from: ");     //Print Action Message        
	string filename = pUI->GetSrting();
	pUI->ClearStatusBar();
	ifstream file(filename + ".txt");
	string comptype;
	string ID;
	string X, Y;
	string Label;
	string line;
	int flag = 0;

	while (getline(file, line)) {
		//split the line at space and fill the required variables
		bool flag_comptype = true;
		bool flag_ID = false;
		bool flag_label = false;
		bool flag_x = false;
		bool flag_y = false;
		int ind;
		flag += 1;
		if (flag >= 2) {
			for (int i = 0; i < line.length(); i++) {
				if (line.at(i) == '\t' && flag_comptype) {
					comptype = line.substr(0, i);
					flag_comptype = false;
					flag_ID = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_ID) {
					ID = line.substr(ind + 1, i - ind);
					flag_ID = false;
					flag_label = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_label) {
					Label = line.substr(ind + 1, i - ind);
					flag_label = false;
					flag_x = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_x) {
					X = line.substr(ind + 1, i - ind);
					flag_x = false;
					flag_y = true;
					ind = i;
				}
				else if (flag_y) {
					Y = line.substr(ind + 1, line.length() - ind);
					flag_comptype = true;
					flag_y = false;
				}
			}
		}
	}
}

void ActionLoad::Undo()
{
}

void ActionLoad::Redo()
{
}

