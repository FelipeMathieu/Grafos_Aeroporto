#pragma once

#include<iostream>

using namespace std;

class Edge
{
private:
	string hour;
	string duration;
	string voo;
	int numbersVoo = 0;
public:
	Edge();
	~Edge();
	Edge(string hour, string duration);
	string getHour() {
		return this->hour;
	};
	string getDuration() {
		return this->duration;
	};
	string getVoo() {
		return this->voo;
	}
	int getNumbersVoo() {
		return this->numbersVoo;
	}
};

