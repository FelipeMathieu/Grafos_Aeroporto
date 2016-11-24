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

void Grafo::setPg(Grafo *G, string initials, string day) {
	pair<string, string> aux;
	aux.first = day;
	aux.second = initials;
	G->G[aux] = *new List();
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
		if (!this->find(initials, day)) {
			aux.first = day;
			aux.second = initials;
			this->G[aux] = *new List();
			if (!this->G[aux].findEdge(hour, duration, voo) && arrival != "" && arrival != "CANCELADO") {
				aux.first = day;
				aux.second = initials;
				this->G[aux].insertFirst(destination, arrival, hour, duration, voo);
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
				this->G[aux].insertFirst(destination, arrival, hour, duration, voo);
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

bool Grafo::isEul() {
	int cont = 0;
	for (auto &x : this->G) {
		if ((x.second.listSize() % 2) != 0){
			cont++;
		}
		if (cont > 2) {
			return 0;
		}
	}

	if (cont == 2 || cont == 0) {
		return 1;
	}
	else {
		return 0;
	}
}