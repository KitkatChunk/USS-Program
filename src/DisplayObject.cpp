#include "DisplayObject.h"

Scene* DisplayObject::getParent() const
{
	return m_pParentScene;
}

void DisplayObject::setParent(Scene* parent)
{
	m_pParentScene = parent;
}
