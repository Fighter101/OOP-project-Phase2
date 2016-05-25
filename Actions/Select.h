#pragma once
#include"Action.h"
class Component;
class Select : public Action
{ 
	

public:
	Select(ApplicationManager*, Component*);
	virtual ~Select();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();

};
