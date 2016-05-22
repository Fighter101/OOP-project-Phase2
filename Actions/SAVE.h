#pragma once
#include"Action.h"
#include<string>
class Save : public Action
{
	
	public:

	Save(ApplicationManager*);
	~Save();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};