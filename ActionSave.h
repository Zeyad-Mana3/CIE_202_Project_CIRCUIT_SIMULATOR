#pragma once
#ifndef _ACTION_SAVE_
#define _ACTION_SAVE_


#include "Actions/Action.h"

class saveAction : public Action
{

public:
	saveAction(ApplicationManager* pApp);
	virtual ~saveAction(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
#endif