#include "Pajek.h"

Pajek::Pajek()
{
}

Pajek::~Pajek()
{
}

void Pajek::createPajek(Grafo *G) {
	ofstream file("Pajek.txt");
	int i = 1;
	int aux = 0;

	if (file.is_open()) {
		file << "*Vertices " << G->getVertices() << endl;
		for (auto &x : G->getGrafo()) {
			file << i << " \"" << x.first.first << " " << x.first.second << "\"" << endl;
			i += 1;
		}
		file << "*Arcs" << endl;
		i = 1;
		for (auto &x : G->getGrafo()) {
			if (!x.second.isVoid()) {
				i = G->getIndex(x.first.first, x.first.second);
				for (Node *p = x.second.getFirst(); p != NULL; p = p->getProx()) {
					aux = G->getIndex(p->getDay(), p->getAirport());
					file << i << " " << aux << " " << p->getHour() << " " << p->getDuration() << " " << p->getVoo() << endl;
					aux = 0;

				}
			}
		}
	}
}

string Pajek::filtraPalavra(string p)
{
	char chars[] = ",;<>!?[]\"{}()\&*+";

	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		// you need include <algorithm> to use general algorithms like std::remove()
		p.erase(remove(p.begin(), p.end(), chars[i]), p.end());
	}

	return p;
}

vector<string> Pajek::split(const string &s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i) 
	while (i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
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

Grafo Pajek::readPajek() {
	ifstream file("Pajek.txt");
	string line;
	vector<string> vLine;
	vector<pair<string, string>> aux;
	Grafo G;
	bool controller = false;
	string initials;
	string day;
	string voo;
	string hour;
	string duration;
	string destination;
	string arrival;

	if (file.is_open()) {
		while (getline(file, line).good()) {
			line = this->filtraPalavra(line);
			vLine = this->split(line);
			if (controller) {
				initials = aux.at(stoi(vLine.at(0), nullptr, 10) - 1).first;
				day = aux.at(stoi(vLine.at(0), nullptr, 10) - 1).second;
				voo = vLine.at(4);
				hour = vLine.at(2);
				duration = vLine.at(3);
				destination = aux.at(stoi(vLine.at(1), nullptr, 10) - 1).first;
				arrival = aux.at(stoi(vLine.at(1), nullptr, 10) - 1).second;
				G.insertGrafo(initials, day, voo, hour, duration, destination, arrival);
			}
			if (vLine.at(0) == "Arcs") {
				controller = true;
			}
			if (vLine.at(0) != "Vertices" && !controller) {
				G.setPg(&G, vLine.at(2), vLine.at(1));
				aux.push_back(make_pair(vLine.at(2), vLine.at(1)));
			}
		}
	}

	G.getVertices();
	G.getArestas();

	return G;
}