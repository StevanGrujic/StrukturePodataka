#pragma once
#include"Node.h"
class List
{
protected:
	Node* head;
	Node* tail;
public:
	List();
	~List();
	bool isEmpty();
	void addToHead(int a);
	void addToTail(int x);
	int deleteFromHead();
	int deleteFromTail();
	void deleteEl(int el);
	Node* findNode(int el);
	Node* getHead();
	Node* getNext(Node* ptr);
	int getHeadEl();
	int getNextEl(int a);
	bool isInList(int el);
	void print();
	void update(int oldinfo, int newinfo);
};

