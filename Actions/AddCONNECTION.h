#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "action.h"
#include "..\Components\Connection.h"
#include"..\Pin\Pin.h"
class AddCONNECTION : public Action
{
private:
	bool check;
	//two points are the source and the destination of the connection
	Pin* DstPin;
	Pin* SrcPin;
	Gate* SrcGate;
	Gate* DstGate;

	int x1, y1, x2, y2;	//Two corners of the rectangular area
public:
	AddCONNECTION(ApplicationManager *pApp);
	virtual ~AddCONNECTION(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif