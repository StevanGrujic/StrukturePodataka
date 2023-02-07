#include "List.h"
List::List()
{
	this->head = NULL;
	this->tail = NULL;
}
List::~List()
{
	while (!isEmpty())
	{
		int x = deleteFromHead();
	}
}
bool List::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
void List::addToHead(int a)
{
	head = new Node(a, head);
	if (tail==NULL)
		tail = head;
}
void List::addToTail(int x)
{
	if (isEmpty())
	{
		head = new Node(x, NULL);
		tail = head;
	}
	else
	{
		tail->next = new Node(x, NULL);
		tail = tail->next;
	}
}
int List::deleteFromHead()
{
	if (isEmpty())
		throw "Lista je prazna!";
	int p = head->info;
	Node* ptr = head;
		if (head->next == NULL)
		{
			head = tail = NULL;
		}
		else
			head = head->next;
		delete ptr;
		return p;
}
int List::deleteFromTail()
{
	if (isEmpty())
		throw "Lista je prazna!";
	Node* ptr = tail;
	int k = tail->info;
	if (head->next == NULL)
		head = tail = NULL;
	else
	{
		Node* spok = NULL;
		Node* npok = head;
		while (npok != tail)
		{
			spok = npok;
			npok = npok->next;
		}
		if (npok == tail)
		{
			tail = spok;
			spok->next = NULL;
		}
		delete ptr;
	}
	return k;
}
void List::deleteEl(int el)
{
	if (isEmpty())
		return;
	Node* ptr;
	if (head->next == NULL && head->info == el)
	{
		delete head;
		head = tail = NULL;
	}
	else if (head->info == el)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
			else
			{
				Node* spok = head;
				Node* npok = head->next;
				while (npok != NULL && npok->info != el)
				{
					spok = npok;
					npok = npok->next;
				}
				if (npok!=NULL)
				{
					spok->next = npok->next;
					if (npok == tail)
						tail = spok;
					delete npok;
				}
			}
}
void List::print()
{
	Node* ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
}
Node* List::findNode(int el)
{
	if (isEmpty())
		return NULL;
	Node* ptr = head;
	while (ptr != NULL && ptr->info != el)
	{
		ptr = ptr->next;
	}
	if (ptr != NULL)
		return ptr;
	else
		return NULL;

}
Node* List::getHead()
{
	return head;
}
Node* List::getNext(Node* ptr)
{
	return ptr->next;
}
int List::getHeadEl()
{
	if (!isEmpty())
		return head->info;
	else
		throw "Lista je prazna!";
}
int List::getNextEl(int a)
{
	if (isEmpty())
		throw "Lista je prazna!";
	Node* pok = findNode(a);
	if (pok->next != NULL)
		return pok->next->info;
	else
		throw "Ovaj element je poslednji!";
}
bool List::isInList(int el)
{
	if (!isEmpty())
	{
		Node* pok = head;
		while (pok != NULL && pok->info != el)
		{
			pok = pok->next;
		}
		if (pok != NULL)
			return true;
		else
			return false;
	}
	else
		return false;
}
void List::update(int oldinfo, int newinfo)
{
	if (head->info==oldinfo && head->next==NULL)
	{
		head->info = newinfo;
	}
	else if (head->info == oldinfo)
	{
		head->info = newinfo;
		if (newinfo > head->next->info)
		{
			Node* spok = NULL;
			Node* npok = head;
			while (npok != NULL && npok->info <= newinfo)
			{
				spok = npok;
				npok = npok->next;
			}
			Node* q = head;
			head = head->next;
			q->next = npok;
			spok->next = q;
		}
	}
	else
	if (isInList(oldinfo))
	{
		Node* npok = findNode(oldinfo);
		npok->info = newinfo;
		Node* spok = head;
		while (spok->next->info != newinfo)
		{
			spok = spok->next;
		}
		if (spok->info > npok->info)
		{
			Node* ptr = spok->next;
			spok->next = npok->next;
			Node* a = NULL;
			Node* b = head;

			if (head->info < newinfo)
			{
				while (b->info < newinfo)
				{
					a = b;
					b = b->next;
				}
				npok->next = b;
				a->next = npok;
			}
			else
			{
				npok->next = head;
				head = npok;
			}
		}
		else if (npok->info > spok->info && npok->info>npok->next->info)
		{
			spok->next = npok->next;
			Node* b = npok;
			while (b->next != NULL && b->next->info < newinfo)
			{
				b = b->next;
			}
			if (b->next != NULL)
			{
				npok->next = b->next;
				b->next = npok;
			}
			else
			{
				b->next = npok;
				npok->next = NULL;
				tail = npok;
			}

		}

	}
	else
		cout << "Zadati element nije u listi!" << endl;


}














