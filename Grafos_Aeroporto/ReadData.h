#pragma once

#include "Grafo.h"
#include <tchar.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

class ReadData
{
private:
	vector<string> split(const string &s);

public:
	ReadData();
	~ReadData();
	
	void readFile(string nameFile, Grafo *G);
	void populateGrafo(Grafo *G);
};

