#pragma once
 #include "Actions/Action.h"
#include "ActionDisSelection.h"
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
class ActionDisSelection : public Action
{

private:
	int Cx, Cy;
public:
	ActionDisSelection(ApplicationManager* pApp);	//constructor
	virtual ~ActionDisSelection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};

