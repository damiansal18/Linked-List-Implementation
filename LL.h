//#pragma once
#ifndef LL_H
#define LL_H

typedef int el_t;

struct Node
{
	el_t Elem;
	Node* Next;

};

class LL
{

protected:
	Node *Front;
	Node* Rear;
	int count;

	void moveTo(int, Node*&);

public:
	LL();
	~LL();

	class Underflow {};
	class Overflow {};

	bool isEmpty(); // checks for an empty list.

	void displayList();

	void addFront(el_t);

	void addRear(el_t);

	void deleteFront(el_t&);

	void deleteRear(el_t&);

	void deleteAt(int, el_t&); // removes node at desired position.

	void insertAt(int, el_t);

	LL(const LL&); // copy constructor

	LL& operator=(const LL&); // overloading the '=' operator






};


#endif 
