#include "BSTree.h"
BSTree::BSTree()
{
	brel = 0;
	this->root = NULL;
}
BSTree::~BSTree()
{
	deleteTree(root);
	brel = 0;
}
void BSTree::deleteTree(BSTNode* p)
{
	if (p != NULL)
	{
		deleteTree(p->levi);
		deleteTree(p->desni);
		delete p;
	}
}
void BSTree::insert(int a)
{
	BSTNode* p = root;
	BSTNode* prev = NULL;
	while (p != NULL)
	{
		prev = p;
		if (p->info < a)
			p = p->desni;
		else
			p = p->levi;
	}
	if (root == NULL)
		root = new BSTNode(a);
	else
		if (prev->info < a)
			prev->desni = new BSTNode(a);
		else
			prev->levi = new BSTNode(a);
	brel++;
}
void BSTree::preorder(BSTNode* a)
{
	if (a != NULL)
	{
		cout << a->info << " ";
		preorder(a->levi);
		preorder(a->desni);
	}

}
BSTNode* BSTree::search(BSTNode* p, int el)
{
	while (p != NULL && p->info != el)
	{
		if (el > p->info)
			p = p->desni;
		else
			p = p->levi;
	}
	if (p == NULL)
		return NULL;
	else
		return p;
}
void BSTree::poSirini()
{
	if (root == NULL)
		return;
	queue<BSTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BSTNode* p = q.front();
		cout << p->info << " ";
		if (p->levi != NULL)
			q.push(p->levi);
		if (p->desni != NULL)
			q.push(p->desni);
		q.pop();
	}
}
void BSTree::deleteExternalNodes(BSTNode* p)
{
	if (brel == 0)
		throw "Stablo je prazno!";
	if (p != NULL)
	{
		if (p->levi != NULL)
			if (p->levi->levi == NULL && p->levi->desni == NULL)
			{
				delete p->levi;
				p->levi = NULL;
				brel--;
			}
		if (p->desni != NULL)
			if (p->desni->levi == NULL && p->desni->desni == NULL)
			{
				delete p->desni;
				p->desni = NULL;
				brel--;
			}
		deleteExternalNodes(p->levi);
		deleteExternalNodes(p->desni);
	}
}

