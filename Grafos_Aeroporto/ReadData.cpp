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
				if (informations.at(8).substr(0, 10) == "REALIZADO") {
					G->insertGrafo(informations.at(4), informations.at(6).substr(0, 10), informations.at(0), informations.at(6).substr(11, 16), this->calcDuracao(informations.at(7), informations.at(6)), informations.at(5), informations.at(7).substr(0, 10));
				}
				else if(informations.at(8).substr(0, 10) != "CANCELADO"){
					G->insertGrafo(informations.at(4), informations.at(6).substr(0, 10), informations.at(0), informations.at(6).substr(11, 16), this->calcDuracao(informations.at(8), informations.at(6)), informations.at(5), informations.at(8).substr(0, 10));
				}
				else {
					G->insertGrafo(informations.at(4), informations.at(6).substr(0, 10), informations.at(0), informations.at(6).substr(11, 16), "", informations.at(5), "CANCELADO");
				}
			}
		}
	}
	G->getArestas();
	G->getVertices();
}

string ReadData::calcDuracao(string saida, string chegada) {
	string hS = saida.substr(11, 2);
	string mS = saida.substr(14, 2);
	string hC = chegada.substr(11, 2);
	string mC = chegada.substr(14, 2);
	if (std::stoi(hS) < std::stoi(hC)) {
		int horas = std::stoi(hC) - std::stoi(hS);
		if (std::stoi(mS) > std::stoi(mC)) {
			horas--;
			int minutos = std::stoi(mC) - std::stoi(mS) + 60;
			return std::to_string(horas) + ':' + std::to_string(minutos);
		}
		else {

			int minutos = std::stoi(mC) + std::stoi(mS);
			return std::to_string(horas) + ':' + std::to_string(minutos);
		}
	}
	else {
		int horas = 24 - std::stoi(hS) + std::stoi(hC);
		if (std::stoi(mS) > std::stoi(mC)) {
			horas--;
			int minutos = std::stoi(mC) - std::stoi(mS) + 60;
			return std::to_string(horas) + ':' + std::to_string(minutos);
		}
		else {

			int minutos = std::stoi(mC) - std::stoi(mS);
			return std::to_string(horas) + ':' + std::to_string(minutos);
		}
	}
}