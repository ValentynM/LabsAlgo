#pragma once
# include <iostream>
#include <vector>
#include <queue>

#include "UInterface.h"

using namespace std;

class Graph
{
private:
	int n;
	vector <vector<int>> graph;
	vector <bool> visited;
	vector <int> way;
	
public:

	Graph(int n1)
	{
		n = n1;
		graph.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++)
		{
			graph[i].resize(n);
			visited[i] = false;
		}
	}

	bool inputGraph(UInterface myInterface)
	{
		myInterface.getID(1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!myInterface.graphMatrixElementInput(graph[i][j]))
					return false;
		return true;
	}

	void depthFirstSearch(int initialVertex, UInterface myInterface)
	{
		visited[initialVertex] = true;
		way.resize(way.size() + 1);
		way[way.size() - 1] = initialVertex;
		for (int i = 0; i < n; i++)
			if ((graph[initialVertex][i] != 0) && (!visited[i]))
				depthFirstSearch(i, myInterface);
	}

	void outputWay(UInterface myInterface)
	{
		for (int i = 0; i < way.size(); i++)
			myInterface.outputWay(way[i]);
	}
};