#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "cAVLTree.h"

int main()
{
	cAVLTree* pAVL = new cAVLTree();

	//use a vector of string and ints to store the test keys and test data.
	//means we can use for loops for populating the tree and testing inserts,
	//Exists and get methods
	std::vector<std::string> vsKeys = { "Duck", "Apple", "Beans", "Eggs", "Carrots", "Grapes", "Feta" };
	std::vector<int> viData = { 1, 2, 3, 4, 5, 6, 7 };
	assert(vsKeys.size() == viData.size());

	int iAVLSize = pAVL->GetSize();
	std::cout << "AVL size = " << iAVLSize << std::endl;
	assert(iAVLSize == 0);

	int iAVLHeight = pAVL->GetHeight();
	std::cout << "AVL height = " << iAVLHeight << std::endl;
	assert(iAVLHeight == 0);

	for (int i = 0; i < vsKeys.size(); i++)
	{
		std::string sKey = vsKeys[i];
		int iDatum = viData[i];
		cNode* pNewNode = new cNode(sKey, iDatum);
		std::cout << "Inserting node - key: " << sKey << " datum " << iDatum << std::endl;
		pAVL->InsertNode(pNewNode);
		iAVLSize = pAVL->GetSize();
		std::cout << "AVL size = " << iAVLSize << std::endl;
		assert(iAVLSize == i + 1);
		iAVLHeight = pAVL->GetHeight();
		std::cout << "AVL height = " << iAVLHeight << std::endl;
		assert(iAVLHeight > 0);
	}

	//end of the test
	//delete pAVL; // BUG HAPPENS WHEN TRY TO DELETE
	std::cout << "End of test program" << std::endl;
}