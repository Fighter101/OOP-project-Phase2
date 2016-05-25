#pragma once
#include "Action.h"
#include"..\ApplicationManager\ApplicationManager.h"
class Move :
	public Action
{
private:
	
	
public:
	Move(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~Move();
};

