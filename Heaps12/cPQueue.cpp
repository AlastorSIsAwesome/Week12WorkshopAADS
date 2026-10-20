#include "cPQueue.h"

//void cPQueue::Swap(cItem* _child, cItem* _parent)
//{
//    // the child's pointers become the parent's pointers
//    // parent's pointers become child's pointers, exept the self pointer is towards the parent
//
//    // child's pointers
//    cItem* LeftTemp = _child->m_ptrLeftChild;
//    cItem* RightTemp = _child->m_ptrRightChild;
//
//    if (_parent->m_ptrLeftChild == _child) // if the child is the left branch of the parent
//    {
//        _child->m_ptrLeftChild = _parent; // parent becomes left child
//        _child->m_ptrRightChild = _parent->m_ptrRightChild; 
//    }
//    else if (_parent->m_ptrRightChild == _child) // if the child is the right branch of the parent
//    {
//        _child->m_ptrLeftChild = _parent->m_ptrLeftChild; 
//        _child->m_ptrRightChild = _parent; // parent becomes Right child
//    }
//
//    // set parent's pointers to the child's pointers
//    _parent->m_ptrLeftChild = LeftTemp;
//    _parent->m_ptrRightChild = RightTemp;
//}
//
//void cPQueue::HeapSort()
//{
//
//
//
//}
//
//bool cPQueue::Equals(cItem* _item1, cItem* _item2)
//{
//    if (_item1 == nullptr)
//    {
//        throw "can't compair a null pointer";
//    }
//    if (_item2 == nullptr)
//    {
//        throw "can't compair a null pointer";
//    }
//
//    return (_item1->GetPriority() == _item2->GetPriority());
//}
//
//bool cPQueue::IsGreater(cItem* _item1, cItem* _item2)
//{
//    if (_item1 == nullptr)
//    {
//        throw "can't compair a null pointer";
//    }
//    if (_item2 == nullptr)
//    {
//        throw "can't compair a null pointer";
//    }
//
//
//    return (_item1->GetPriority() > _item2->GetPriority());
//}

struct Compair
{
    bool operator() (cItem& _a, cItem& _b)
        const
    {
        return _a.GetPriority() < _b.GetPriority();
    }
};



cPQueue::cPQueue()
{
}

cPQueue::~cPQueue()
{
}

void cPQueue::Push(cItem _item)
{
    m_Heap.push_back(_item); // push the item to the back of the vector

    push_heap(m_Heap.begin(), m_Heap.end(), Compair()); // heapify


}




cItem cPQueue::Pop()
{
    cItem Head = m_Heap[0];

    pop_heap(m_Heap.begin(), m_Heap.end(), Compair()); // removes the top to the back of the container
    m_Heap.pop_back(); // fully remove the item

    return Head;
}

int cPQueue::GetLength()
{
    {
        return m_Heap.size();
    }
}


float cPQueue::PriorityFront()
{
    return m_Heap[0].GetPriority();
}
