#pragma once
#include "BaseList.h"
#include "LinkedListNode.h"

template <typename ItemType>
class LinkedList : public BaseList<ItemType>
{
private:
	LinkedListNode<ItemType>* m_pHead;
	LinkedListNode<ItemType>* m_pTail;

public:

	LinkedList();
	virtual BaseList<ItemType>& addInHead(const ItemType& Item);
	virtual BaseList<ItemType>& addInTail(const ItemType& Item);
	virtual BaseList<ItemType>& removeFromHead();
	virtual BaseList<ItemType>& removeFromTail();
	virtual ItemType& operator[] (const int index);
	virtual const ItemType& operator[] (const int index) const;
	virtual ~LinkedList();
};

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
	m_pHead = m_pTail = nullptr;
	this->m_size = 0;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::addInHead(const ItemType& Item)
{
	if (this->m_size)
		m_pHead = m_pHead->addBefore(Item);
	else
		m_pHead = m_pTail = new LinkedListNode<ItemType>(Item);

	this->m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::addInTail(const ItemType& Item)
{
	if (this->m_size)
		m_pTail = m_pTail->addAfter(Item);
	else
		m_pHead = m_pTail = new LinkedListNode<ItemType>(Item);

	this->m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::removeFromHead()
{
	switch (this->m_size)
	{
	case 0: return *this;
	case 1:
		m_pHead->remove();
		m_pHead = m_pTail = nullptr;
		break;
	default:
		LinkedListNode<ItemType>* temp = m_pHead;
		m_pHead = m_pHead->operator[](1);
		temp->remove();
	}
	
	this->m_size--;
	
	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::removeFromTail()
{
	switch (this->m_size)
	{
	case 0: return *this;
	case 1:
		m_pHead->remove();
		m_pHead = m_pTail = nullptr;
		break;
	default:
		LinkedListNode<ItemType>* temp = m_pTail;
		m_pTail = m_pTail->operator[](-1);
		temp->remove();
	}

	this->m_size--;

	return *this;
}

template <typename ItemType>
ItemType& LinkedList<ItemType>::operator[] (const int index)
{
	if (index<this->m_size/2)
		return m_pHead->operator[](index)->data;
	else
		return m_pTail->operator[](index-this->m_size+1)->data;
}

template <typename ItemType>
const ItemType& LinkedList<ItemType>::operator[] (const int index) const
{
	if (index<this->m_size / 2)
		return m_pHead->operator[](index)->data;
	else
		return m_pTail->operator[](index - this->m_size + 1)->data;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
	if (this->m_size)
		delete m_pHead;
}