#pragma once
#include <string>

class cItem
{
private:
protected:
	// cant be bothered to make them protected, prob should tho
	std::string m_ItemIdentifier = "";
	float m_PriorityValue = 0.0f;

public:


	cItem* m_ptrLeftChild = nullptr;
	cItem* m_ptrRightChild = nullptr;
	cItem* m_ptrParent = nullptr; // needed?

	cItem();

	inline cItem(std::string _identifier, float _priority)
		:m_ItemIdentifier(_identifier), m_PriorityValue(_priority) {
	};

	~cItem();



	inline float GetPriority()
	{
		return m_PriorityValue;
	}

	inline void SetPriority(float _priority)
	{
		m_PriorityValue = _priority;
	}

	inline std::string GetIdentifier()
	{
		return m_ItemIdentifier;
	}

	inline void SetIdentifier(std::string _identifier)
	{
		m_ItemIdentifier = _identifier;
	}
};

