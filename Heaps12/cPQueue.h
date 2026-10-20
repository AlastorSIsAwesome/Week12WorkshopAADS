#pragma once
#include "cItem.h"

class cPQueue
{
private:
protected:
	cItem* m_ptrRoot = nullptr;
	int m_NumOfNodes = 0;


	void Swap(cItem* _child, cItem* _parent);
	void HeapSort();

public:
	cPQueue();
	~cPQueue();

	/// <summary>
	/// Adds item to the queue
	/// </summary>
	/// <param name="_item"></param>
	void Push(cItem _item);

	/// <summary>
	/// Returns the highest prioriy item and removes it from the queue
	/// </summary>
	/// <returns></returns>
	cItem Pop();

	/// <summary>
	/// Num of items in the queue
	/// </summary>
	/// <returns></returns>
	inline int GetLength()
	{
		return m_NumOfNodes;
	}

	/// <summary>
	/// Returns the priority of the item at the front of the queue without popping it
	/// </summary>
	/// <returns></returns>
	float PriorityFront();
};

