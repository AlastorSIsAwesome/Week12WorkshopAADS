#include "cAVLTree.h"
#include <algorithm>





#include "cAVLTree.h"


int cAVLTree::GetBalanceFactor(cNode* _ptrRoot)
{
	if (_ptrRoot == nullptr)
	{
		return 0;
	}
	else
	{
		int LeftHeight = GetHeight(_ptrRoot->GetLeftChild());
		int RightHeight = GetHeight(_ptrRoot->GetRightChild());
		return LeftHeight - RightHeight;
	}
}

//int cAVLTree::CalculateHeight(cNode* _ptrStartingNode)
//{
//	return 0;
//}

cNode* cAVLTree::RotateRight(cNode* _ptrRoot)
{
	if (_ptrRoot == nullptr)
	{
		return nullptr;
	}

	// get the root node's left child
	cNode* ptrLeftChild = _ptrRoot->GetLeftChild();

	// get root node's right child
	cNode* ptrTemp = _ptrRoot->GetRightChild();

	// set the root's left node to be it's right node (temp)
	_ptrRoot->SetLeftChild(ptrTemp);

	// set the leftChild's right child as the root
	ptrLeftChild->SetRightChild(_ptrRoot);

	// return the left child, new root node for this tree
	return ptrLeftChild;
}


cNode* cAVLTree::RotateLeft(cNode* _ptrRoot)
{
	if (_ptrRoot == nullptr)
	{
		return nullptr;
	}

	// get the right child of the root node
	cNode* ptrRightChild = _ptrRoot->GetRightChild();

	// get left child of root node
	cNode* ptrTemp = _ptrRoot->GetLeftChild();

	// set root node's right node as it's left node (temp)
	_ptrRoot->SetRightChild(ptrTemp);

	// set the right node's left pointer to the root node
	ptrRightChild->SetLeftChild(_ptrRoot);

	// right child is now root node, return new root
	return ptrRightChild;
}

cNode* cAVLTree::RotateRightLeft(cNode* _ptrRoot)
{
	if (_ptrRoot == nullptr)
	{
		return nullptr;
	}

	cNode* ptrRightChild = _ptrRoot->GetRightChild();

	ptrRightChild = RotateRight(ptrRightChild);
	_ptrRoot->SetRightChild(ptrRightChild);


	// return new root node
	return RotateLeft(_ptrRoot);
}

cNode* cAVLTree::RotateLeftRight(cNode* _ptrRoot)
{
	if (_ptrRoot == nullptr)
	{
		return nullptr;
	}

	cNode* ptrLeftChild = _ptrRoot->GetLeftChild();
	ptrLeftChild = RotateLeft(ptrLeftChild);
	_ptrRoot->SetLeftChild(ptrLeftChild);


	// return new root node
	return RotateRight(_ptrRoot);
}



void cAVLTree::InsertNode(cNode* pInsert, cNode* pStartNode)
{
	if (!mpRoot)
	{
		mpRoot = pInsert;
		miSize++;
		return;
	}
	else if (pStartNode->Equal(pInsert->GetKey()))
	{
		return;
	}
	else if (pStartNode->LessThan(pInsert->GetKey())) //left child pointer is null, so insert as left child
	{
		if (!pStartNode->GetLeftChild())
		{
			pStartNode->SetLeftChild(pInsert);
			miSize++;
		}
		else //left child point is not null, so recurse down left subtree
		{
			cNode* pLeftChild = pStartNode->GetLeftChild();
			InsertNode(pInsert, pLeftChild);

			// reset child of parent node
			pStartNode->SetLeftChild(pLeftChild);
		}
	}
	else //insert key must be greater
	{
		if (!pStartNode->GetRightChild()) //right child pointer is null, so insert as right child
		{
			pStartNode->SetRightChild(pInsert);
			miSize++;
		}
		else //right child pointer is not null, so recurse down right subtree
		{
			cNode* pRightChild = pStartNode->GetLeftChild();
			InsertNode(pInsert, pStartNode->GetRightChild());

			//reset child of parent node
			pStartNode->SetRightChild(pRightChild);
		}
	}


	int RootBalanceFactor = GetBalanceFactor(pStartNode);
	int RightBalanceFactor = GetBalanceFactor(pStartNode->GetRightChild());
	int LeftBalanceFactor = GetBalanceFactor(pStartNode->GetLeftChild());

	if (RootBalanceFactor > 1 && LeftBalanceFactor >= 0)
	{
		pStartNode = RotateRight(pStartNode);
	}
	
	if (RootBalanceFactor < -1 && RightBalanceFactor <= 0)
	{
		pStartNode = RotateLeft(pStartNode);
	}

	if (RootBalanceFactor > 1 && LeftBalanceFactor < 0)
	{
		pStartNode = RotateLeftRight(pStartNode);
	}

	if (RootBalanceFactor < -1 && RightBalanceFactor > 0)
	{
		pStartNode = RotateRightLeft(pStartNode);
	}
}


cNode* cAVLTree::GetNode(std::string sKey, cNode* pStartNode)
{
	if (!pStartNode)
	{
		return nullptr;
	}
	else if (pStartNode->Equal(sKey))
	{
		return pStartNode;
	}
	else if (pStartNode->LessThan(sKey))
	{
		return GetNode(sKey, pStartNode->GetLeftChild());
	}
	else if (pStartNode->GreaterThan(sKey))
	{
		return GetNode(sKey, pStartNode->GetRightChild());
	}
}


int cAVLTree::GetHeight(cNode* pStartNode)
{
	if (pStartNode == nullptr)
	{
		return 0;
	}
	else
	{
		int iLeftHeight = GetHeight(pStartNode->GetLeftChild());
		int iRightHeight = GetHeight(pStartNode->GetRightChild());

		return std::max(iLeftHeight, iRightHeight) + 1;
	}
}


void cAVLTree::DestroyTree(cNode* pNode)
{
	if (pNode)
	{
		DestroyTree(pNode->GetLeftChild());
		DestroyTree(pNode->GetRightChild());
		delete pNode;
		miSize--;
	}
}

cNode* cAVLTree::GetLeftmost(cNode* pStartNode)
{
	if (pStartNode == nullptr)
	{
		return nullptr;
	}
	else if (pStartNode->GetLeftChild() == nullptr)
	{
		return pStartNode;
	}
	else
	{
		return GetLeftmost(pStartNode->GetLeftChild());
	}
}

void cAVLTree::InsertNode(cNode* pInsert)
{

	InsertNode(pInsert, mpRoot);

}


cAVLTree::~cAVLTree()
{
	DestroyTree(mpRoot);
}

cNode* cAVLTree::GetNode(std::string sKey)
{
	return GetNode(sKey, mpRoot);
}

int cAVLTree::GetHeight()
{
	return GetHeight(mpRoot);
}

bool cAVLTree::KeyExists(std::string sKey)
{
	return GetNode(sKey) != nullptr;
}

cNode* cAVLTree::GetLeftmost()
{
	return GetLeftmost(mpRoot);
}
