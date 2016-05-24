#pragma once
#include"Action.h"
class Select : public Action
{ 
	

public:
	Select(ApplicationManager*);
	virtual ~Select();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();

};
