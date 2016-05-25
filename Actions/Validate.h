#pragma once
#include"Action.h"

class Validate :public Action
{

	bool sim;

public:
	Validate(ApplicationManager*,bool);
	virtual ~Validate();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
