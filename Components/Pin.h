#ifndef _PIN_H
#define _PIN_H

//#include "..\Defs.h"
#include"..\GridItem.h"
class Pin :public GridItem
{
protected:
	STATUS m_Status;	//Status of the Pin
	GraphicsInfo Position;
public:
	virtual ActionType Leftpress() = 0;
	virtual ActionType RightPress() = 0;
	virtual void hover() = 0;
	virtual void released() = 0;
	Pin();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
	virtual GraphicsInfo GetPosition();
	virtual void SetPosition(GraphicsInfo r_GfxInfo);
};

#endif