#pragma once
#include"Action.h"
class Cut : public Action
{
	


public:
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	
	Cut(ApplicationManager*);
	virtual ~Cut();
};
