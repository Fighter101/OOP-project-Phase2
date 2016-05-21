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
	return SELECT;
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

