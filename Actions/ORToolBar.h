#pragma once
#include"Action.h"

class ORToolBar : public Action
{
public:
	ORToolBar(ApplicationManager*);
	virtual ~ORToolBar();
	

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
