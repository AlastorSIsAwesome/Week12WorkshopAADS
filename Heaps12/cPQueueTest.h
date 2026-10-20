#pragma once
#include <cassert>
#include <iostream>
#include "cPQueue.h"

class cPQueueTest
{
protected:
	//std::vector<cItem> m_Items;
	std::vector<std::string> Keys =
	{
		"Akima",
		"Janica",
		"Aubrey",
		"Reilly",
		"Bella",
		"Jane",
		"Gabe",
		"Ben",
		"Huntress",
		"Sylvia"
	};

	std::vector<float> Priorities =
	{
		5.f,
		0.03f,
		1.f,
		0.00001f,
		6.9f,
		4.2f,
		1.9f,
		500.f,
		7.f,
		2.f
	};


	//int m_NumOfItems = 10;

public:
	cPQueueTest();
	~cPQueueTest();

	void RunTests(cPQueue& _PQ);

	void PopulatePQ(cPQueue& _PQ);

	void PopPQ(cPQueue& _PQ);

	void MaxElement(cPQueue& _PQ);
	
};