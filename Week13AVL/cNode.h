#pragma once

#include <string>

	class cNode
	{
	protected:
		std::string msKey;
		int miDatum;
		cNode* mpLeftChild;
		cNode* mpRightChild;

	public:
		cNode()
		{
			mpLeftChild = nullptr;
			mpRightChild = nullptr;
		}

		cNode(std::string sKey, int iDatum)
		{
			msKey = sKey;
			miDatum = iDatum;
			mpLeftChild = nullptr;
			mpRightChild = nullptr;
		}

		void SetKey(std::string sKey)
		{
			msKey = sKey;
		}

		std::string GetKey()
		{
			return msKey;
		}

		void SetDatum(int iDatum)
		{
			miDatum = iDatum;
		}

		int GetDatum()
		{
			return miDatum;
		}

		void SetLeftChild(cNode* pLeftChild)
		{
			mpLeftChild = pLeftChild;
		}

		cNode* GetLeftChild()
		{
			return mpLeftChild;
		}

		void SetRightChild(cNode* pRightChild)
		{
			mpRightChild = pRightChild;
		}

		cNode* GetRightChild()
		{
			return mpRightChild;
		}

		bool LessThan(std::string sKey)
		{
			return sKey < msKey;
		}

		bool GreaterThan(std::string sKey)
		{
			return sKey > msKey;
		}

		bool Equal(std::string sKey)
		{
			return sKey == msKey;
		}

	};