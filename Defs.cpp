
#include"GUI\UI_Info.h"
const STATUS operator&(const STATUS a, const STATUS b)
{
	return (a == HIGH && b == HIGH) ? HIGH : LOW;
}

const STATUS operator|(const STATUS a, const STATUS b)
{
	return (a == HIGH || b == HIGH) ? HIGH : LOW;
}

const STATUS operator^(const STATUS a, const STATUS b)
{
	return (a != b) ? HIGH : LOW;
}

const STATUS operator~(const STATUS a)
{
	return ((a == HIGH) ? LOW : HIGH);
}
bool IsInDesign(GraphicsInfo r_GfxInfo)
{
	return (r_GfxInfo.x1 <UI.width - UI.GateItemWidth&&r_GfxInfo.x1>UI.GateItemWidth&&r_GfxInfo.y1 > UI.ToolBarHeight&&r_GfxInfo.y1 < UI.StatusBarHeight);
}