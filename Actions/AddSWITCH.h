#pragma once
#include"Action.h"
class AddSwitch : public Action
{
	int  Cx, Cy;
public:
	AddSwitch(ApplicationManager*);
	virtual ~AddSwitch();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};
