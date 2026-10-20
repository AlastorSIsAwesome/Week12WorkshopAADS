#include "cPQueue.h"

void cPQueue::Swap(cItem* _child, cItem* _parent)
{
    // the child's pointers become the parent's pointers
    // parent's pointers become child's pointers, exept the self pointer is towards the parent

    // child's pointers
    cItem* LeftTemp = _child->m_ptrLeftChild;
    cItem* RightTemp = _child->m_ptrRightChild;

    if (_parent->m_ptrLeftChild == _child) // if the child is the left branch of the parent
    {
        _child->m_ptrLeftChild = _parent; // parent becomes left child
        _child->m_ptrRightChild = _parent->m_ptrRightChild; 
    }
    else if (_parent->m_ptrRightChild == _child) // if the child is the right branch of the parent
    {
        _child->m_ptrLeftChild = _parent->m_ptrLeftChild; 
        _child->m_ptrRightChild = _parent; // parent becomes Right child
    }

    // set parent's pointers to the child's pointers
    _parent->m_ptrLeftChild = LeftTemp;
    _parent->m_ptrRightChild = RightTemp;
}

void cPQueue::HeapSort()
{



}





cPQueue::cPQueue()
{
}

cPQueue::~cPQueue()
{
}

void cPQueue::Push(cItem _item)
{
    // send to the closest avalible spot
    // check if child is smaller than node
    // if not, swap and repeat

    if (m_ptrRoot == nullptr)
    {
        m_ptrRoot = &_item;
    }

}

cItem cPQueue::Pop()
{
    return *m_ptrRoot;
}


float cPQueue::PriorityFront()
{
    return 0.0f;
}
