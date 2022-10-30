
using namespace std;
#include <iostream>
#include "LL.h"


void LL::moveTo(int iter, Node*& temp)
{
	temp = Front;

	for (int i = 1; i < iter; i++)
	{
		temp = temp->Next;
	}
}

LL::LL()
{
	cout << endl <<"List initialized..." << endl;
	Front = NULL;
	Rear = NULL;
	count = 0;
}

LL::~LL()
{
	el_t x; // iterator 'x'.
	
	while (isEmpty() == false)
	{
		deleteFront(x);
	}
	cout << endl << "..Deconstructing list.." << endl;
}

bool LL::isEmpty()
{
	if ((Front == NULL) && (Rear == NULL) && (count == 0))
	{
		//cout << "List is Empty." << endl;
		return true;
	}
	else
	{
		//cout << "List is not empty." << endl;
		return false;
	}
}

void LL::displayList()
{
	if (isEmpty())
	{
		cout << endl << "List is empty , cannot display .." << endl;
	}
	else
	{
		cout << endl << "..[";

		Node* p = NULL; // Node pointer to travese the list.
		p = Front; // Set P to the address of the Node at the front of the list.

		while (p != NULL) // while p does not point at null.
		{
			cout << " " << p->Elem << " "; // display the element of the node where is pointing to.
			p = p->Next; // point p at the next node.
		}

		cout << "]" << endl;
	}
}

void LL::addFront(el_t newElem)
{
	
	
	if (isEmpty()) // if list is empty.
	{
		Front = new Node; // a node for the 'Front' pointer is allocated.
		Front->Elem = newElem; // the node takes the parameter as data;
		Rear = Front; // there is only one node in the list.
		Rear->Next = NULL; 
		count++;

		cout << endl << " " << newElem << " added to front of the empty list." << endl;
	}
	else // if the list is not empty rearrange pointers to set the new node as the 'Front'.
	{
		Node *p; // a node pointer is declared
		p = new Node; // a node memory is allocated to p.
		p->Next = NULL;
		p->Elem = newElem;
		p->Next = Front; // the new node's next ptr now points to the address of the previous 'Front' node.
		Front = p; // the new node p is now the 'Front' of the list.
		count++;

		cout << endl << " " << newElem << " added to front of list." << endl;
	}
	
}

void LL::addRear(el_t newElem)
{
	if (isEmpty()) // if list is empty.
	{
		Front = new Node; // a node for the 'Front' pointer is allocated.
		Front->Elem = newElem; // the node takes the parameter as data;
		Rear = Front; // there is only one node in the list.
		Rear->Next = NULL;
		count++;

		cout << endl << " " << newElem << " added to rear of the empty list." << endl;
	}
	else
	{
		Rear->Next = new Node; // a node is allocate at the end of the list.
		Rear = Rear->Next; // now the node is the the end of the list.
		Rear->Elem = newElem;
		Rear->Next = NULL ; // new 'Rear' node sets it's 'Next' pointer to NULL.
		count++;

		cout << endl << " " << newElem << " added to rear of list." << endl;
	}
}

void LL::deleteFront(el_t& frontElem)
{
	if (isEmpty())
		throw Underflow();
	else if (Front->Next == NULL)
	{
		frontElem = Front->Elem;
		delete Front;

		cout << endl << " Deleting the front & only element in the list : " << frontElem << endl;

		Front = NULL;
		Rear = NULL;
		count--;
	}
	else
	{
		frontElem = Front->Elem;
		Node* Second; 
		Second = Front->Next;
		delete Front;

		cout << endl << " Deleting the front element in the list : " << frontElem << endl; 

		Front = Second;
		count--;

	} 
}

void LL::deleteRear(el_t& rearElem)
{
	if (isEmpty())
		throw Underflow();
	else if (Front->Next == NULL) // only one element in list.
	{
		rearElem = Rear->Elem;
		delete Rear;
		Front = NULL;
		Rear = NULL;
		count--;

		cout << endl << " Deleting the rear & only element in the list : " << rearElem << endl;
	}
	else // list with elements.
	{
		Node* ptr;
		ptr = Front;

		while (ptr->Next != Rear) // traverse list to reach rear node.
		{
			ptr = ptr->Next;
		}
		rearElem = Rear->Elem;
		delete Rear;

		cout << endl << " Deleting the rear element in the list : " << rearElem << endl;

		Rear = ptr;
		Rear->Next = NULL;
		count--;

	}
}

void LL::deleteAt(int pos, el_t& nodeElem)
{
	if ((pos > count) || (pos < 1))
	{
		throw Overflow();
	}
	else if (pos == 1 )
	{
		deleteFront(nodeElem);
	}
	else if (pos == count-1)
	{
		deleteRear(nodeElem);
	}
	else
	{
		int before = pos - 1;
		int after = pos + 1;
		Node* prev ;
		Node* next;
		Node* target;

		target = new Node;

		moveTo(before, prev); //ptr to keep track of Node behind the the chosen Node.
		moveTo(after, next); //ptr to keep track of the Node infront of the chosen Node.
		moveTo(pos, target); //ptr to chosen node.
		
		nodeElem = target->Elem;
		delete target; // in between prev and next.

		cout << endl << " Deleting : " << nodeElem << " ... from position " << pos << " in the list." << endl;
		prev->Next = next; // add link missing after deleting 'target'.
		count--;
	}
}

void LL::insertAt(int pos, el_t newNode)
{ 
	if ((pos > count + 1) || pos < 1)
	{
			throw Overflow(); 
			
 	}
	else if (pos == 1 )
	{
		addFront(newNode);
	}
	else if (pos == count + 1)
	{
		addRear(newNode);
	}
	else 
	{
		Node* prev;
		Node* next;
		Node* target;

		moveTo(pos - 1, prev); //keeps track of Node behind the chosen Node.
		moveTo(pos, target); // keeps track of where the Node will be inserted
		moveTo(pos, next); // keeps track fo the Node which will be next to the newly inserted Node.

		target = new Node;
		target->Elem = newNode;

		cout << endl << " Inserting : " << newNode << " ... at position " << pos << " in the list." << endl;

		prev->Next = target; // sets new Node infront of 'prev' Node.
		target->Next = next; // insets new Node behind 'next' Node.  
		count++;
	}
}

LL::LL(const LL& copy)
{
	Front = NULL;
	Rear = NULL;
	count = 0;

	Node* ptr;
	ptr = copy.Front;

	while (ptr != NULL) // copying each element into the 'LL' Linked list.
	{
		this->addRear(ptr->Elem);
		ptr = ptr->Next;
	}
}

LL& LL::operator=(const LL& list) // LL1 = LL2
{
	// LeftHandSide(LHS) = RighHandSide(RHS)
	// RHS is copied into LHS 

	el_t element;

	if (&list != this) //if LHS is not equal to RHS delete it all.
	{
		while (!this->isEmpty())
			this->deleteRear(element);

		Node* ptr;
		ptr = list.Front;

		while (ptr != NULL) // add all elements of RHS to LHS
		{
			this->addRear(ptr->Elem);
			ptr = ptr->Next;
		}

	} // end of if.

	return *this; // return identical linked list
}
