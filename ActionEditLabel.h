#pragma once
#ifndef _EDIT_LABEL_H
#define _EDIT_LABEL_H

#include "Actions/Action.h"
#include "Components/Component.h"

class ActionEditLabel : public Action
{

public:

	ActionEditLabel(ApplicationManager* pApp);
	~ActionEditLabel(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
