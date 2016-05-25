#pragma once
#include"Action.h"
#include<string>
class Load : public Action
{

public:

	Load(ApplicationManager*);
	~Load();
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};