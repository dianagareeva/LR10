#include "Header.h"

Stack::Stack(){}

Stack::Stack(int a)
{
	tail = new Node();
	tail->prev = nullptr;
	tail->next = nullptr;
	tail->a = a;
	count = 0;

}

Stack& Stack::operator=(Stack &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete tail;
	delete next;
	tail = other.tail;
	other.tail = nullptr;
}

int Stack::GetSize() const
{
	return count;
}

bool Stack::Push(const int a)
{
	Node* newnode = new Node();
	Node* checking = next;
	if (HasElements())
	{
		while (checking->next != nullptr)
		{
			checking = checking->next;
		}
		next = newnode;
		tail->prev = nullptr;
	}
	else
	{
		tail = newnode;
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = nullptr;
	count = count + 1;
	return true;
}

bool Stack::Pop(int &a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
	if (next!= tail)
	{
		next = next->prev;
		next->next = nullptr;
	}
	else
	{
		next = tail = nullptr;
	}
	count = count - 1;
	return true;
}

bool Stack::Peek(int& a)
{
	if (!HasElements()) { throw NoElementsException("Stack is Empty!"); };
	a = next->a;
	return true;
}


bool Stack::HasElements() const
{
	if (this->tail != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


