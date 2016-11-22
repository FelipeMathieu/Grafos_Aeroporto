#pragma once
#include<iostream>
#include "Edge.h"

using namespace std;

class Node
{
private:
	string initials;
	string day;
	Edge edge;
	Node *prox;

public:
	Node();
	~Node();
	Node(string initials, string day);
	Node(string initials, string day, string hour, string duration);

	string getAirport();
	string getDay();
	Node *getProx();
	int countAdj();
	void setProx(Node *p);
	void setAirport(string newCost);
	void setDay(string day);
	string getHour() {
		return edge.getHour();
	};
	string getDuration() {
		return edge.getDuration();
	};
	string getVoo() {
		return edge.getVoo();
	};
};

