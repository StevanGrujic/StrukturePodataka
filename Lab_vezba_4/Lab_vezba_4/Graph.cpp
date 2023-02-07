#include "Graph.h"
#include<stack>
#include<queue>
Graph::Graph()
{
	this->numberOfNodes = 0;
	this->start = NULL;
}
Graph::~Graph()
{
	Node* ptr = start;
	Node* p = ptr->next;
	while (ptr != NULL)
	{
		delete ptr;
		ptr = p;
		if(p!=NULL)
		p = p->next;
	}
}
void Graph::addNode(int a)
{
	if (start == NULL)
	{
		start = new Node(a, NULL, NULL, 0);
		numberOfNodes++;
	}
	else
	{
		Node* ptr = start;
		start = new Node(a, ptr, NULL, 0);
		numberOfNodes++;
	}
}
Node* Graph::findNode(int a)
{
	Node* ptr = start;
	while (ptr != NULL && ptr->node != a)
	{
		ptr = ptr->next;
	}
	return ptr;
}
void Graph::addEdge(int a, int b)
{
	Node* pa = findNode(a);
	Node* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		throw "Nepostojeci cvorovi!";
	Edge* ptr = pa->adj;
	pa->adj = new Edge(ptr, pb);
}
Edge* Graph::findEdge(int a, int b)
{
	Node* pa = findNode(a);
	Node* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		throw "Nepostojeci cvorovi!";
	Edge* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
	{
		ptr = ptr->link;
	}
	return ptr;
}
void Graph::print()
{
	Node* ptr = start;
	if (start == NULL)
		throw "Graf ne postoji!";
	while (ptr != NULL)
	{
		cout << ptr->node << "-->";
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			cout << p->dest->node << "|";
			p = p->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}
void Graph::dfs(int a)
{
	Node* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = 1;//neobradjen
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL)
		throw "Nepostojeci cvor!";
	stack<Node*> stek;
	stek.push(ptr);
	ptr->status = 2;
	while (stek.empty() == false)
	{
		ptr = stek.top();
		stek.pop();
		ptr->status = 3;
		ptr->visitNode();
		Edge* e = ptr->adj;
		while (e != NULL)
		{
			if (e->dest->status == 1)
			{
				e->dest->status = 2;
				stek.push(e->dest);
			}
			e = e->link;
		}
	}

}
void Graph::bfs(int a)
{
	Node* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = 1;//neobradjen
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL)
		throw "Nepostojeci cvor!";
	queue<Node*> red;
	red.push(ptr);
	ptr->status = 2;
	while (red.empty() == false)
	{
		ptr = red.front();
		red.pop();
		ptr->status = 3;
		ptr->visitNode();
		Edge* e = ptr->adj;
		while (e != NULL)
		{
			if (e->dest->status == 1)
			{
				e->dest->status = 2;
				red.push(e->dest);
			}
			e = e->link;
		}
	}
}
int Graph::bidirectedEdges()
{
	Node* pn = start;
	Edge* pe;
	Edge* pt;
	int s = 0;
	while (pn != NULL)
	{
		pe = pn->adj;
		while (pe != NULL)
		{
			pt = pe->dest->adj;
			while (pt != NULL && pt->dest != pn)
			{
				pt = pt->link;
			}
			if (pt != NULL)
				s++;
			pe = pe->link;
		}
		pn = pn->next;
	}
	return s / 2;
}
void Graph::shortestPath(int a, int b)
{
	Node* ptr = start;
	Node* pb;
	while (ptr != NULL)
	{
		ptr->distance = 0;
		ptr->status = 1;
		ptr->parent = NULL;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	pb = findNode(b);
	Edge* e;
	if (ptr == NULL)
		throw "Nepostojeci cvor!";
	queue<Node*> red;
	red.push(ptr);
	ptr->status = 2;
	bool nadjen =false;
	while (red.empty() == false && !nadjen)
	{
		ptr = red.front();
		red.pop();
		if (ptr != NULL)
		{
			ptr->status = 3;
			e = ptr->adj;
			while (e != NULL && e->dest->node != pb->node)
			{
				if (e->dest->status == 1)
				{
					e->dest->status = 2;
					red.push(e->dest);
					e->dest->parent = ptr;
					e->dest->distance = ptr->distance + 1;
				}
				e = e->link;
			}
			if (e != NULL)
			{
				nadjen = true;
				e->dest->parent = ptr;
				Node* p = e->dest;
				while (p != NULL)
				{
					cout << p->node << "<--";
					p = p->parent;
				}
			}
		}
	}
}

