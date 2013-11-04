#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class StackType
{
private:
	nodeType<Type> *stackTop;
	string name;
public:
	StackType();
	~StackType();
	void pop();
	void push(Type& newItem);
	Type top();
	bool isEmptyStack();
	bool isFullStack();
	string getStackName();
	void setStackName(string n);
};

template <class Type>
StackType<Type> :: StackType()
{
	stackTop = NULL;
}

template <class Type>
StackType<Type> :: ~StackType()
{
	nodeType<Type> *temp; //pointer to delete a node

	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop -> link;
		
		delete temp;
	}
}

template <class Type>
void StackType<Type> :: push(Type& newItem)
{
	nodeType<Type> *newNode; //pointer to crete new Node
	newNode = new nodeType<Type>;
	newNode -> info = newItem;
	newNode -> link = stackTop;

	stackTop = newNode;
	
}

template <class Type>
Type StackType<Type> :: top()
{
	assert (stackTop != NULL);

	return stackTop -> info;
}
template <class Type>
void StackType<Type> :: pop()
{
	nodeType<Type> *temp; //pointer to delete a node
	if (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop -> link;
		
		delete temp;
	}
	else
	{
		cout << "Cannot pop off empty stack." << endl;
	}
}
template <class Type>
bool StackType<Type> :: isEmptyStack()
{
	return (stackTop==NULL);
}

template <class Type>
bool StackType<Type> :: isFullStack()
{
	return false;
}

template <class Type>
string StackType<Type>::getStackName()
{
	return name;
}

template <class Type>
void StackType<Type>::setStackName(string n)
{
	name = n;
}