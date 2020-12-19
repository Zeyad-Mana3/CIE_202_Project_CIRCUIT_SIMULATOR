#pragma once
#include "Actions/Action.h"
class ActionDelete :
    public Action
{

private:
	Component* CompS[];

public:
	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};



