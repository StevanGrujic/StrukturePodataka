#pragma once
class Node;
class Edge
{
public:
	Edge* link;
	Node* dest;
public:
	Edge();
	Edge(Edge* e, Node* n);
};

