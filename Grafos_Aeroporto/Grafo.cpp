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
			return false;
		}
	}

	if (cont == 2 || cont == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Grafo::isConex() {
	vector<pair<pair<string, string>, int>> v;
	pair<string, string> aux;
	int i = 0, j = 0;
	for (auto &x : this->G) {
		aux.first = x.first.first;
		aux.second = x.first.second;
		v.push_back(make_pair(aux, -1));
	}

	for (auto &x : this->G) {
		j = this->indexVec(v, x.first.first, x.first.second);
		if (v.at(j).second == -1) {
			v.at(j).second = i;
		}
		else if (v.at(j).second != i) {
			i++;
			v.at(j).second = i;
			return false;
		}
		if (!x.second.isVoid() && v.at(j).second != -1){
			for (Node *p = x.second.getFirst(); p != NULL; p = p->getProx()) {
				j = this->indexVec(v, p->getDay(), p->getAirport());
				v.at(j).second = i;
			}
		}
		j = 0;
	}

	if (i > 0) {
		return false;
	}
	else {
		return true;
	}
}

int Grafo::indexVec(vector<pair<pair<string, string>, int>> v, string first, string second) {
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i).first.first == first && v.at(i).first.second == second) {
			return i;
		}
	}
}