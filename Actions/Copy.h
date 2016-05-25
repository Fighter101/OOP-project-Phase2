#pragma once
#include"Action.h"
class Copy : public Action
{



public:
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

	Copy(ApplicationManager*);
	virtual ~Copy();
};