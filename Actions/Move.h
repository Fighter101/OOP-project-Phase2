#pragma once
#include "Action.h"
#include"..\ApplicationManager.h"
class Move :
	public Action
{
private:
	Component*ptr;
	GraphicsInfo Old;
	GraphicsInfo New;
	
public:
	Move(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~Move();
};

