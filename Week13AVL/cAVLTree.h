#pragma once

#include "cNode.h"

class cAVLTree
{
protected:
	int miSize;

	cNode* mpRoot;

	void InsertNode(cNode* pInsert, cNode* pStartNode);

	cNode* GetNode(std::string sKey, cNode* pStartNode);

	int GetHeight(cNode* pStartNode);

	void DestroyTree(cNode* pNode);

	cNode* GetLeftmost(cNode* pStartNode);



	int GetBalanceFactor(cNode* _ptrRoot);

	//int CalculateHeight(cNode* _ptrStartingNode);

	cNode* RotateRight(cNode* _ptrRoot);

	cNode* RotateLeft(cNode* _ptrRoot);

	cNode* RotateRightLeft(cNode* _ptrRoot);

	cNode* RotateLeftRight(cNode* _ptrRoot);

public:
	cAVLTree()
	{
		mpRoot = nullptr;
		miSize = 0;
	}

	~cAVLTree();

	int GetSize()
	{
		return miSize;
	}




	void InsertNode(cNode* pInsert); // rewrite this




	//void InsertNode(cNode* pInsert);

	cNode* GetNode(std::string sKey);

	int GetHeight();

	bool KeyExists(std::string sKey);

	cNode* GetLeftmost();
};