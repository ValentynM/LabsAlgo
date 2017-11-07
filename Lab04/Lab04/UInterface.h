#pragma once
#include <iostream>

using namespace std;

class UInterface
{
public:
	
	void getID(int id)
	{
		switch (id)
		{
		case 1:
			cout << "\nEnter '1' to input deque,\n'2' to output deque,";
			cout << "\n'3' to get size of deque,\n'4' to clear deque,";
			cout << "\n'5' to pop back,\n'6' to pop front,";
			cout << "\n'7' to push back,\n'8' to push front,";
			cout << "\n'9' to test whether deque is empty\n\n";
			break;
		case 2:
			cout << "\nInput deque elements:\n";
			break;
		case 3:
			cout << "\nDeque elements:\n";
			break;
		case 4:
			cout << "\nFront element:\n";
			break;
		case 5:
			cout << "\nBack element:\n";
			break;
		case 6:
			cout << "\nDeque is empty!\n";
			break;
		case 7:
			cout << "\nDeque isn't empty!\n";
			break;
		case 8:
			cout << "\nDeque deleted!\n";
			break;
		case 9:
			cout << "\nDeque's size = ";
			break;
		case 10:
			cout << "\nEnter new deque element:\n";
			break;
		case 11:
			cout << "\nInput the count of elements:\n";
			break;
		default:
			break;
		}
	}


	static void inputCharacter(char& ch)
	{
		cin >> ch;
		cin.ignore();
	}

	template <class type>
	void inputDeque(const type& myIterator)
	{
			cin >> *myIterator;
	}

	template <class type>
	void outputDeque(const type myIterator)
	{
		cout << *myIterator << " ";
	}

	void setSize(int &size)
	{
		cin >> size;
	}

	void getSize(int size)
	{
		cout << size << endl;
	}

	template <class type>
	type inputNewDequeElement(list <type> myList)
	{
		type newElement;
		cin >> newElement;
		return newElement;
	}
};