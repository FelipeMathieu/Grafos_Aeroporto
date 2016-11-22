#include "List.h"

List::List()
{
	this->first = NULL;
	this->last = NULL;
}

List::List(string initials, string day) {
	Node *p = new Node(initials, day);
	this->first = p;
	this->last = p;
	this->size += 1;
}

List::~List()
{
}

Node *List::getLast() {
	return this->last;
}

Node *List::getFirst() {
	return this->first;
}

bool List::isVoid() {
	if (this->first == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void List::insertFirst(string initials, string day, string hour, string duration) {
	Node *p = new Node(initials, day, hour, duration);

	if (this->isVoid()) {
		this->first = p;
		this->last = p;
		this->size += 1;
	}
	else {
		p->setProx(this->first);
		this->first = p;
		this->size += 1;
	}
}

void List::insertLast(string initials, string day, string hour, string duration) {
	Node *p = new Node(initials, day, hour, duration);

	if (this->isVoid()) {
		this->first = p;
		this->last = p;
		this->size += 1;
	}
	else {
		this->last->setProx(p);
		this->last = p;
		this->size += 1;
	}
}

void List::printList() {
	if (this->isVoid()) {
		cout << "Lista vazia!" << endl;
	}
	else {
		for (Node *p = this->first; p != NULL; p = p->getProx()) {
			cout << p->getAirport().c_str() << " | " << p->getDay().c_str() << " -> ";
		}
		cout << endl;
	}
}

Node *List::insertAfter(Node *thisNode, Node *aux) {
	aux->setProx(thisNode->getProx());
	thisNode->setProx(aux);

	return thisNode;
}

/*void List::insertInOrder(string initials, string day) {
	Node *p = new Node(initials, day);

	if (this->isVoid()) {
		this->insertFirst(p->getValue(), p->getCost());
	}
	else {
		for (Node *s = this->first; s != NULL; s = s->getProx()) {
			if (s->getProx() == NULL && cost >= s->getCost()) {
				s->setProx(p);
				this->last = p;
				this->size += 1;
				break;
			}
			else {
				if (cost >= s->getCost() && cost < s->getProx()->getCost()) {
					s = insertAfter(s, p);
					this->size += 1;
					break;
				}
			}
		}
	}
}*/

void List::removeFirst() {
	if (this->isVoid()) {
		cout << "Lista vazia!" << endl;
	}
	else {
		this->first = this->first->getProx();
	}
}

void List::removeLast() {
	Node *p = new Node();

	if (this->isVoid()) {
		cout << "Lista vazia!" << endl;
	}
	else {
		for (p = this->first; p->getProx() != this->last; p = p->getProx()) {
			//Vai até o penultimo elemento
		}

		p->setProx(NULL);
		this->last = p;
	}
}

void List::removeAdj(string initials, string day) {
	if (this->isVoid()) {
		cout << "Lista vazia!" << endl;
	}
	else {
		Node *aux = NULL;
		Node *p = this->first;
		int i = 0;

		for (i; i < this->listSize(); i++) {
			if (p->getAirport() == initials && p->getDay() == day && i == 0) {
				this->removeFirst();
				break;
			}
			else if (p->getAirport() == initials && p->getDay() == day && i == (this->listSize() - 1)) {
				this->removeLast();
				break;
			}
			else if (p->getAirport() == initials && p->getDay() == day) {
				aux->setProx(p->getProx());
				break;
			}
			aux = p;
			p = p->getProx();
		}

		if (p == NULL) {
			cout << "Adjacencia inexistente!" << endl;
		}
	}
}

int List::listSize() {

	if (this->isVoid()) {
		return 0;
	}

	return this->size;
}

bool List::findElement(string initials, string day) {
	for (Node *p = this->first; p != NULL; p = p->getProx()) {
		if (initials == p->getAirport() && day == p->getDay()) {
			return true;
			break;
		}
	}
	return false;
}

void List::findAndAttribute(string initials, string day) {
	for (Node *p = this->first; p != NULL; p = p->getProx()) {
		if (initials == p->getAirport()) {
			p->setDay(day);
			break;
		}
	}
}