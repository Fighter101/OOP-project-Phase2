#pragma once
#include"Action.h"
class MultiSelect : public Action
{

public:
	MultiSelect(ApplicationManager*);
	virtual ~MultiSelect();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();



};