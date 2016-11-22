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
	int edges = 0;

public:
	Grafo();
	~Grafo();

	Grafo(string initials, string day);
	void insertGrafo(string initials, string day, string voo, string hour, string duration, string destination);
	map<pair<string, string>, List> Grafo::newGrafo(string initials, string day);
	bool find(string initials, string day);
};

