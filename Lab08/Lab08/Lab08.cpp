#include "stdafx.h"
#include <iostream>

#include "graph.h"
#include "UInterface.h"

using namespace std;


void main()
{
	UInterface myInterface;
	bool newCycle = true;
	int n = 0;
	int initialVertex = 1;

	while (newCycle)
	{
		myInterface.getID(2);
		myInterface.countOfNodesInput(n);
		
		if (n < 1)
		{
			myInterface.getID(5);
			continue;
		}

		Graph myGraph(n);
		if (!myGraph.inputGraph(myInterface))
		{
			myInterface.getID(3);
			continue;
		}

		myInterface.getID(7);
		myInterface.initialVertexInput(initialVertex);
		if (initialVertex >= n)
		{
			myInterface.getID(10);
			continue;
		}

		myGraph.depthFirstSearch(initialVertex, myInterface);
		myGraph.outputWay(myInterface);

		myInterface.getID(4);
		cin >> newCycle;
	}

	system("pause");
}
