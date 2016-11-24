#pragma once

#include "Grafo.h"
#include <fstream>

class Pajek
{
public:
	Pajek();
	~Pajek();
	void readPajek(string file);
	void createPajek(Grafo *G);
	Grafo readPajek();
	string filtraPalavra(string p);
	vector<string> split(const string &s);
};

