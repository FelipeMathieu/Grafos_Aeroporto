#include "Node.h"

Node::Node()
{
	this->prox = NULL;
}

Node::~Node()
{
}

Node::Node(string initials, string day) {
	this->initials = initials;
	this->day = day;
	this->prox = NULL;
}

Node::Node(string initials, string day, string hour, string duration, string voo) {
	this->initials = initials;
	this->day = day;
	this->edge = *new Edge(hour, duration, voo);
	this->prox = NULL;
}

string Node::getDay() {
	return this->day;
}

Node *Node::getProx() {
	return this->prox;
}

string Node::getAirport() {
	return this->initials;
}

int Node::countAdj() {
	if (this->prox == NULL) {
		return 0;
	}
	else {
		int i = 0;
		Node *p = this;
		while (p->prox != NULL) {
			i += 1;
			p = p->prox;
		}
		return i;
	}
}

void Node::setProx(Node *p) {
	this->prox = p;
}

void Node::setAirport(string initials) {
	this->initials = initials;
}

void Node::setDay(string day) {
	this->day = day;
}
