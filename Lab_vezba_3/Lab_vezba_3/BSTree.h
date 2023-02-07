#pragma once
#include"BSTNode.h"
#include<queue>
class BSTree
{
	BSTNode* root;
	unsigned int brel;
public:
	BSTree();
	~BSTree();
	void deleteTree(BSTNode* p);
	void insert(int a);
	void preorder(BSTNode* a);
	void preorder() { preorder(root); }
	BSTNode* search(BSTNode* p, int el);
	BSTNode* search(int el) { return search(root, el); };
	void poSirini();
	void deleteExternalNodes(BSTNode* p);
	void deleteExternalNodes() { deleteExternalNodes(root); };
	BSTNode* vratiRoot()
	{
		return root;
	}
	void maxChildrenSum(BSTNode* node, int* suma, BSTNode** taj)
	{
		if (node == nullptr)
		{
			return;
		}
			int tren,tren2;
			if (node->levi == NULL)
				tren = 0;
			else
			{
				tren = node->levi->info;
			}
			if (node->desni == NULL)
				tren2 = 0;
			else
			{
				tren2 = node->desni->info;
			}
			
			if (tren + tren2 > *suma)
			{
				*suma = tren + tren2;
				*taj = node;
			}
			maxChildrenSum(node->levi, suma, taj);
			maxChildrenSum(node->desni, suma, taj);

	}
};

