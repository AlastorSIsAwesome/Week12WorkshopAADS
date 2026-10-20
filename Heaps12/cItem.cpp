#include "cItem.h"

cItem::cItem()
{
}

cItem::cItem(std::string _identifier, float _priority)
	:m_ItemIdentifier(_identifier), m_PriorityValue(_priority)
{
}

cItem::~cItem()
{
}
