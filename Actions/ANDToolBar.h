#pragma once
#include"Action.h"

class ANDToolBar : public Action
{
public:
	ANDToolBar(ApplicationManager*);
	virtual ~ANDToolBar();
	

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
