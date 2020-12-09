#pragma once
#include "Action.h"
#include "..\Connections\Connection.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"


class ActionAddConnection : public Action, Component
{
private:
		//Parameters for line length to be occupied by the connection
	int Cx1, Cy1, Cx2, Cy2;	//Center point of the conmponent 
		int x1, y1, x2, y2;	
		
	public:
		ActionAddConnection(ApplicationManager* pApp);
		virtual ~ActionAddConnection(void);

		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();
	};

