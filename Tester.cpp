using namespace std;
#include <iostream>
#include "LL.h"
#include <stdlib.h>

void caseOne()
{
	cout << "Case 1: Basic Functionality" << endl;
	
	LL listOne;
	int x;

	if (listOne.isEmpty())
	{
		cout << endl << "List is currently empty." << endl;
	}
	else
	{
		cout << "List is not empty." << endl;
	}

	listOne.displayList();

	listOne.addFront(1);
	listOne.addRear(2);
	listOne.addRear(4);
	listOne.insertAt(3, 3);

	listOne.displayList();

	listOne.deleteFront(x);
	listOne.deleteRear(x);
	listOne.deleteAt(2, x);

	listOne.displayList();

 }

void caseTwo()
{
	LL listTwo;
	int x;
	
	if (listTwo.isEmpty())
	{
		cout << endl << "List is currently empty." << endl;
	}
	else
	{
		cout << "List is not empty." << endl;
	}

	try
	{
		listTwo.deleteFront(x);
	}
	catch (LL::Underflow)
	{
		cerr << "Error: Underflow, List is empty. " << endl;
	}

	try
	{
		listTwo.deleteRear(x);
	}
	catch (LL::Underflow)
	{
		cerr << "Error: Underflow, List is empty. " << endl;
	}

	listTwo.displayList();

	listTwo.addFront(4);
	listTwo.addRear(3);
	listTwo.addRear(1);
	listTwo.insertAt(3, 2);

	listTwo.displayList();

	listTwo.insertAt(3, 1);
	listTwo.insertAt(1, 5);

	listTwo.displayList();

	listTwo.deleteAt(2, x);
	listTwo.deleteAt(3, x);
	listTwo.displayList();

	try
	{
		listTwo.deleteAt(7, x);
	}
	catch (LL::Overflow)
	{
		cerr << "Error: Out of Range. " << endl;
	}

	try
	{
		listTwo.insertAt(8, x);
	}
	catch (LL::Overflow)
	{
		cerr << "Error: Out of Range. " << endl;
	}
}
/*
void caseThree()
{
	LL listThree;
	int x;

	listThree.displayList();

	listThree.addFront(4);
	listThree.addRear(3);
	listThree.addRear(1);
	listThree.insertAt(6, 2);
	listThree.displayList();
	listThree.insertAt(3, 1);

	LL copy(listThree);
	copy.displayList();
	copy.addFront(1);
	copy.displayList();
	
	listThree = copy;
	listThree.displayList();
	


}
*/
int main()
{
	int choice;

	do
	{
		cout << endl << "List Tests" << endl;
		cout << "***MENU***" << endl << endl;
		cout << "Case 1 ( 1 ) " << endl;
		cout << "Case 2 ( 2 ) " << endl;
		//cout << "Case 3 ( 3 ) " << endl;
		cout << "Enter ( 0 ) to quit." << endl;
		
		cout << ">";
		cin >> choice;

		switch (choice)
		{
		case 1: caseOne();
			break;
		case 2: caseTwo();
			break;
		//case 3: caseThree();
			//break;
		}
	} while (choice != 0);
}