#pragma once
#include"Action.h"
class Simulate :public Action
{
	
public:
	Simulate(ApplicationManager*);
	virtual~Simulate();
	virtual void ReadActionParameters();
	virtual void Execute(); 
	virtual void Redo();
	virtual void Undo();

};