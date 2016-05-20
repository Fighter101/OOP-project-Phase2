#pragma once
#include"Action.h"
class AddLED : public Action
{
	int Cx, Cy;

public:
	AddLED(ApplicationManager*);
	virtual	~AddLED();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};