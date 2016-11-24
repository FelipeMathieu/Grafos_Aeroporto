#include "List.h"
#include "Node.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#pragma once
class Grafo
{
private:
	map<pair<string, string>, List> G;
	int vertices = 0;
	int arestas = 0;
	int edges = 0;

public:
	Grafo();
	~Grafo();

	Grafo(string initials, string day);
	void insertGrafo(string initials, string day, string voo, string hour, string duration, string destination, string arrival);
	map<pair<string, string>, List> Grafo::newGrafo(string initials, string day);
	bool find(string initials, string day);
	int getArestas() {
		this->arestas = 0;
		for (auto &x : this->G) {
			this->arestas += x.second.listSize();
		}

		return this->arestas;
	};
	int getVertices() {
		this->vertices = this->G.size();
		return this->G.size();
	};
	map<pair<string, string>, List> getGrafo() {
		return this->G;
	};
	int getIndex(string first, string second) {
		int i = 1;
		for (auto &x : this->G) {
			if (x.first.first == first && x.first.second == second) {
				return i;
				break;
			}
			i += 1;
		}
		i = 0;
		if (i = 0) {
			pair<string, string> aux;
			aux.first = first;
			aux.second = second;
			G[aux] = *new List();
			return this->getIndex(first, second);
		}
	};
	void setPg(Grafo *G, string initials, string day);
	bool isEul();
};

