#pragma once
#include"Action.h"

class Paste:public Action
{
	
public:
	Paste(ApplicationManager*);
	virtual ~Paste();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};