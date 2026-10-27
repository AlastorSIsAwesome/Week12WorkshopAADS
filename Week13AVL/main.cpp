#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "cAVLTree.h"

int main()
{
	cAVLTree* pBST = new cAVLTree();

	//use a vector of string and ints to store the test keys and test data.
	//means we can use for loops for populating the tree and testing inserts,
	//Exists and get methods
	std::vector<std::string> vsKeys = { "Duck", "Apple", "Beans", "Eggs", "Carrots", "Grapes", "Feta" };
	std::vector<int> viData = { 1, 2, 3, 4, 5, 6, 7 };
	assert(vsKeys.size() == viData.size());

	int iBSTSize = pBST->GetSize();
	std::cout << "BST size = " << iBSTSize << std::endl;
	assert(iBSTSize == 0);

	int iBSTHeight = pBST->GetHeight();
	std::cout << "BST height = " << iBSTHeight << std::endl;
	assert(iBSTHeight == 0);

	for (int i = 0; i < vsKeys.size(); i++)
	{
		std::string sKey = vsKeys[i];
		int iDatum = viData[i];
		cNode* pNewNode = new cNode(sKey, iDatum);
		std::cout << "Inserting node - key: " << sKey << " datum " << iDatum << std::endl;
		pBST->InsertNode(pNewNode);
		iBSTSize = pBST->GetSize();
		std::cout << "BST size = " << iBSTSize << std::endl;
		assert(iBSTSize == i + 1);
		iBSTHeight = pBST->GetHeight();
		std::cout << "BST height = " << iBSTHeight << std::endl;
		assert(iBSTHeight > 0);
	}

	//end of the test
	delete pBST;
	std::cout << "End of test program" << std::endl;
}