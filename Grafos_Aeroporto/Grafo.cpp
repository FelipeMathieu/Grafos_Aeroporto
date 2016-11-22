#include "Grafo.h"

Grafo::Grafo()
{
}

Grafo::~Grafo()
{
}

map<pair<string, string>, List> Grafo::newGrafo(string initials, string day) {
	pair<string, string> aux;
	aux.first = day;
	aux.second = initials;
	this->G[aux] = *new List();

	return this->G;
}

Grafo::Grafo(string initials, string day) {
	pair<string, string> aux;
	aux.first = day;
	aux.second = initials;
	this->G[aux] = *new List();
}

void Grafo::insertGrafo(string initials, string day, string voo, string hour, string duration, string destination, string arrival) {
	pair<string, string> aux;

	if (this->G.size() == 0) {
		this->G = this->newGrafo(initials, day);
	}
	else {
		if (!this->find(initials, day) && initials == "KMIA") {
			aux.first = day;
			aux.second = initials;
			this->G[aux] = *new List();
			if (!this->G[aux].findEdge(hour, duration, voo) && arrival != "" && arrival != "CANCELADO") {
				aux.first = day;
				aux.second = initials;
				this->G[aux].insertFirst(destination, day, hour, duration, voo);
				if (!this->find(destination, arrival)) {
					aux.first = arrival;
					aux.second = destination;
					this->G[aux] = *new List();
				}
			}
		}
		else {
			aux.first = day;
			aux.second = initials;
			if (!this->G[aux].findEdge(hour, duration, voo) && arrival != "" && arrival != "CANCELADO") {
				this->G[aux].insertFirst(destination, day, hour, duration, voo);
				if (!this->find(destination, arrival)) {
					aux.first = arrival;
					aux.second = destination;
					this->G[aux] = *new List();
				}
			}
		}
	}
}

bool Grafo::find(string initials, string day) {
	for (auto &x : this->G) {
		if (x.first.first == day && x.first.second == initials) {
			return true;
			break;
		}
	}
	return false;
}