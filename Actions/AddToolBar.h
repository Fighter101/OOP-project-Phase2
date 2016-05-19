#pragma once
#include"Action.h"

class AddToolBar : public Action
{
public:
	AddToolBar(ApplicationManager*);
	virtual ~AddToolBar();
	

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};