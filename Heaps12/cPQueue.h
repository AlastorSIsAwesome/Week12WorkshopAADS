#pragma once
#include <vector>
#include <algorithm>
#include "cItem.h"

class cPQueue
{
private:
protected:
	//cItem* m_ptrRoot = nullptr;
	//int m_NumOfNodes = 0;


	//void Swap(cItem* _child, cItem* _parent);
	//void HeapSort();

	//bool Equals(cItem* _item1, cItem* _item2);
	//bool IsGreater(cItem* _item1, cItem* _item2);

	//void Push(cItem* _itemToBePushed, cItem* _currentNode);

	std::vector<cItem> m_Heap;

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
	int GetLength();


	/// <summary>
	/// Returns the priority of the item at the front of the queue without popping it
	/// </summary>
	/// <returns></returns>
	float PriorityFront();
};