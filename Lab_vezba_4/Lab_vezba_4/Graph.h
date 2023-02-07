#pragma once
#include"Node.h"
#include"Edge.h"
class Graph
{
	Node* start;
	unsigned int numberOfNodes;
public:
	Graph();
	~Graph();
	void addNode(int a);
	Node* findNode(int a);
	void addEdge(int a, int b);
	Edge* findEdge(int a, int b);
	void print();
	void dfs(int a);
	void bfs(int a);
	int bidirectedEdges();
	void shortestPath(int a, int b);

};

