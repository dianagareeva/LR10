#include <iostream>

using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};

struct Node 
{
	int a;
	Node* prev;
	Node* next;
};

class Stack
{
public:
	Stack();
	Stack(int);
	Stack& operator=(Stack&&);
	int GetSize() const;
	bool Push(const int);
	bool Pop(int&);
	bool HasElements() const;
	bool Peek(int&);
private:
	Node* tail;
	Node* next;
	int count;
};