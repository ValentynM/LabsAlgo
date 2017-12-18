#pragma once

#include <iostream>
#include <queue>

#include "UInterface.h"

using namespace std;

template <class T>
class myTree
{
private:
	struct myNode
	{
		T data;
		myNode *son;
		myNode *brother;

		myNode(T element, myNode* s = NULL, myNode* b = NULL)
		{
			data = element;
			son = s;
			brother = b;
		}
	};

	myNode* root;

	void add(myNode*& node, T element);
	void deleteSubtree(myNode *node);
	int getHeight(myNode *node);
	int getNodesOneLevel(myNode *node, int level);

public:
	
	myTree()
	{
		root = NULL;
	}

	~myTree()
	{
		deleteSubtree(root);
	}

	int getTreeHeight()
	{
		return getHeight(root);
	}

	int getTreeNodesOneLevel(int level)
	{
		return getNodesOneLevel(root, level);
	}

	void addNode(T element)
	{
		add(root, element);
	}

	void print(UInterface myInterface)
	{
		myNode* p;
		p = root;
		queue <myNode*> p1;

		myInterface.newLine();

		do
		{
			while (p != NULL)
			{
				myInterface.outputData(p->data);
				if (p->son != NULL)
					myInterface.outputSon(p->son->data);
				else
					myInterface.outputSon("-");
				if (p->brother != NULL)
					myInterface.outputBrother(p->brother->data);
				else
					myInterface.outputBrother("-");
				if (p->son != NULL)
					p1.push(p->son);
				p = p->brother;
			}

			
			if (!p1.empty())
			{
				p = p1.front();
				p1.pop();
			}
		} while (!p1.empty() || p != NULL);

		myInterface.newLine();
	}

	template <class T>
	void divideByTwo(T element, myTree& a, myTree& b)
	{
		myNode* p;
		bool flag = false;
		p = root;
		queue <myNode*> p1;

		do
		{
			while (p != NULL)
			{
				if(p->data != element)
					a.addNode(p->data);
				else goto secondpart;
				if (p->son != NULL)
					p1.push(p->son);
				p = p->brother;
			}


			if (!p1.empty())
			{
				p = p1.front();
				p1.pop();
			}
		} while (!p1.empty() || p != NULL);

	secondpart:

		do
		{
			while (p != NULL)
			{
				b.addNode(p->data);
				if (p->son != NULL)
					p1.push(p->son);
				p = p->brother;
			}


			if (!p1.empty())
			{
				p = p1.front();
				p1.pop();
			}
		} while (!p1.empty() || p != NULL);
	}
};

template <class T>
void myTree<T> :: deleteSubtree(myNode* node)
{
	if (node)
	{
		deleteSubtree(node->son);
		deleteSubtree(node->brother);
		delete node;
	}
}

template <class T>
int myTree<T> :: getHeight(myNode* node)
{
	if (node == NULL)
		return 0;
	int max = 0;

	for (myNode *current = node->son; current; current = current->brother)
	{
		int curHeight = getHeight(current);
		if (curHeight > max)
			max = curHeight;
	}
	return max + 1;
}

template <class T>
int myTree<T> :: getNodesOneLevel(myNode* node, int level)
{
	if (node == 0)
		return 0;
	if (level <= 0)
		return 0;

	return getNodesOneLevel(node->son, level - 1) + (level == 1) + getNodesOneLevel(node->brother, level);
}

template <class T>
void myTree<T> :: add(myNode*& node, T element)
{
	if (node == NULL)
		node = new myNode(element);
	else if (element < node->data)
		add(node->son, element);
	else
		add(node->brother, element);
}
