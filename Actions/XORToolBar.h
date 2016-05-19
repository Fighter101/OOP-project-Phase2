#pragma once
#include"Action.h"

class XORToolBar : public Action
{
public:
	XORToolBar(ApplicationManager*);
	virtual ~XORToolBar();
	

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
