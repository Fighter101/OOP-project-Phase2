#pragma once
#include "..\OOP-project-Phase2\Actions\Action.h"
#include "..\OOP-project-Phase2\Components\Connection.h"
class ConnectTwoPins :
	public Action
{
	InputPin* Dst;
	OutputPin* Src;
public:
	ConnectTwoPins(ApplicationManager *pApp);
	~ConnectTwoPins();
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

