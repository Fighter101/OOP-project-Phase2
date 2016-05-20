#pragma once 
#include"Action.h"

class CreateTruthTable :public Action
{


public:
	CreateTruthTable(ApplicationManager*);
	virtual ~CreateTruthTable();

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};
