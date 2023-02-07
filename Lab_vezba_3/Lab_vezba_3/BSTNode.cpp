#include "BSTNode.h"
BSTNode::BSTNode()
{
	this->desni = NULL;
	this->levi = NULL;
}
BSTNode::BSTNode(int a)
{
	this->info = a;
	this->desni = NULL;
	this->levi = NULL;
}
BSTNode::BSTNode(int a, BSTNode* b, BSTNode* c)
{
	this->info = a;
	this->levi = b;
	this->desni = c;
}

