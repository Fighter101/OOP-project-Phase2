#pragma once
#include "action.h"
#include"..\Components\Component.h"
class EditLabel :public Action
{
private:
	Component*ptr;
	string NewLabel;
public:
	EditLabel(ApplicationManager*pApp);
	
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual ~EditLabel();
};