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
	this->vertices += 1;

	return this->G;
}

Grafo::Grafo(string initials, string day) {
	pair<string, string> aux;
	aux.first = day;
	aux.second = initials;
	this->G[aux] = *new List();
	this->vertices += 1;
}

void Grafo::insertGrafo(string initials, string day, string voo, string hour, string duration, string destination) {
	pair<string, string> aux;

	if (this->G.size() == 0) {
		this->G = this->newGrafo(initials, day);
	}
	else {
		if (!this->find(initials, day)) {
			/*if (this->G[vertice].findElement(value) && value != vertice) {
				this->G[vertice].findAndAttribute(value);
			}
			else if (value == vertice) {
				//Nda
			}
			else {
				this->G[vertice].insertLast(value, 1);
			}*/
			aux.first = day;
			aux.second = initials;
			this->G[aux] = *new List();
		}
		else {
			//this->G[vertice] = *new List(vertice, 0);
		}
	}

	//this->nVertices = this->getVertices();
	//this->nArestas = this->getArestas();
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