#pragma once

#include "Node.h"
#include <conio.h>

class List
{
private:
	Node *first;
	Node *last;
	int size = 0;

public:
	List();
	~List();
	List(string initials, string day);

	Node *getFirst();
	Node *getLast();
	bool isVoid();
	void insertFirst(string initials, string day, string hour, string duration);
	void insertLast(string initials, string day, string hour, string duration);
	void printList();
	//void insertInOrder(string initials, string day);
	Node *insertAfter(Node *thisNode, Node *aux);
	void removeFirst();
	void removeLast();
	void removeAdj(string initials, string day);
	int listSize();
	List *getList() {
		return this;
	};
	bool findElement(string initials, string day);
	void findAndAttribute(string initials, string day);
};

