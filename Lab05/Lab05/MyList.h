#pragma once
#include <iostream>
#include <string>

#include "UInterface.h"

using namespace std;

template <class T>
class myList
{
private:
	struct node
	{
		T data;
		node* next;
		node* prev;
	};

	node* head;

	void destroy()
	{
		node* p, *p1;
		p = head;
		p1 = p->next;
		while (p1 != NULL)
		{
			p = p1;
			p1 = p1->next;
			delete p;
		}
	}

public:

	myList() 
	{ 
		head = new node; 
		head->next = NULL; 
	}

	~myList() 
	{ 
		destroy(); 
		delete head;
	}

	void push_back(T element)
	{
		node* p, *p1;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}

		p1 = new node;
		p1->data = element;
		p1->next = NULL;

		p1->prev = p;
		p->next = p1;

	}

	void print(UInterface myInterface)
	{
		node* p;
		p = head->next;
		while (p != NULL)
		{
			myInterface.outputData(p->data);
			p = p->next;
		}
	}

	void push_front(T element)
	{
		node* p;
		p = new node;
		p->data = element;
		if (head->next == NULL)
		{
			p->next = head->next;
			head->next = p;
			p->prev = head;
		}
		else
		{
			p->next = head->next;
			head->next->prev = p;
			head->next = p;
			p->prev = head;
		}
	}

	void pop_back()
	{
		node* p, *p1;
		p = head;
		p1 = p->next;
		while (p1->next != NULL)
		{
			p = p1;
			p1 = p1->next;
		}
		p->next = NULL;
		delete p1;
	}

	void pop_front()
	{
		node* p;
		p = head->next;
		head->next = p->next;
		p->next->prev = head;
		delete p;
	}

	void divideByTwo(T data, myList& a, myList& b)
	{
		node* p;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
			if (p->data == data)
				break;
			a.push_back(p->data);
		}

		p = p->prev;
		while (p->next != NULL)
		{
			p = p->next;
			b.push_back(p->data);
		}
	}
};

