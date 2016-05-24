#pragma once
#include"Action.h"
class Delete : public Action
{


public:
	Delete(ApplicationManager*);
	virtual ~Delete();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};