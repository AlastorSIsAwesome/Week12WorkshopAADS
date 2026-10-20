#include "cPQueueTest.h"

cPQueueTest::cPQueueTest()
{
}

cPQueueTest::~cPQueueTest()
{
}


void cPQueueTest::RunTests(cPQueue& _PQ)
{
	std::cout << std::endl << std::endl << std::endl;

	// populate PQ
	std::cout << "POPULATE PRIORITY QUEUE" << std::endl;
	PopulatePQ(_PQ);

	std::cout << std::endl << std::endl << std::endl;

	std::cout << "POP FROM FRONT OF QUEUE" << std::endl;
	PopPQ(_PQ);

	std::cout << std::endl << std::endl << std::endl;

	std::cout << "TESTING COMPLEATE" << std::endl;
}





void cPQueueTest::PopulatePQ(cPQueue& _PQ)
{

	assert(Keys.size() == Priorities.size());

	int PQSize = _PQ.GetLength();
	std::cout << "PQ size: " << PQSize << std::endl;
	assert(PQSize == 0); // cannot populate a PQ that alredy has stuff in it

	for (int i = 0; i < Keys.size(); i++)
	{
		_PQ.Push(cItem(Keys[i], Priorities[i])); // pushes an item using the given keys and priorities

		std::cout << "Pushing item number [" << i << "] Onto PQ, Key: " << Keys[i] << "  Priority: " << Priorities[i] << std::endl;
		
		assert(_PQ.GetLength() == i + 1);
	}

	PQSize = _PQ.GetLength();
	std::cout << "PQ size: " << PQSize << std::endl;
	assert(PQSize == 10);
}

void cPQueueTest::PopPQ(cPQueue& _PQ)
{
	float Priority = _PQ.PriorityFront();

	std::vector<float>::iterator ItMax = std::max_element(Priorities.begin(), Priorities.end());
	float Max = *ItMax;

	assert(Priority == Max);

	for (int j = 0; j < Keys.size(); j++)
	{
		std::cout << "Pop item: [" << j << "] ";
		cItem Popped = _PQ.Pop();

		std::cout << "Key: " << Popped.GetIdentifier() << " Priority: " << Popped.GetPriority() << std::endl;
		assert(_PQ.GetLength() == Keys.size() - (j + 1));

	}


}

void cPQueueTest::MaxElement(cPQueue& _PQ)
{
	

}

