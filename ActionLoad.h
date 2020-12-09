#pragma once
#include "Actions/Action.h"
class ActionLoad :
    public Action
{

public:
	ActionLoad(ApplicationManager* pApp);
	virtual ~ActionLoad(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

