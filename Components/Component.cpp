#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

ActionType Component::Leftpress()
{
	return SELECT;
}

ActionType Component::RightPress()
{
	return ADD_Right_ToolBar;
}

void Component::hover()
{

}

void Component::released()
{
}

Component::Component()
{}

Component::~Component()
{}

