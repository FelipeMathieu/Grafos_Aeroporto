#include "ReadData.h"

ReadData::ReadData()
{
}

ReadData::~ReadData()
{
}

vector<string> ReadData::split(const string &s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i) 
	while (i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && s[i] == ';')
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && s[j] != ';')
			j++;
		// if we found some nonwhitespace characters 
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

void ReadData::readFile(string nameFile, Grafo *G) {
	ifstream file(nameFile);
	vector<string> columns, informations;
	string line;
	int i = 0;

	if (file.is_open()) {
		while (getline(file, line).good()) {
			if (i == 0) {
				columns = this->split(line);
				i++;
			}
			else {
				informations = this->split(line);
				G->insertGrafo(informations.at(4), informations.at(6).substr(0, 10), informations.at(0), informations.at(6).substr(11, 16), informations.at(5), informations.at(5));
			}
		}
	}
}