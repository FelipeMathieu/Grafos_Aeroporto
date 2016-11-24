#pragma once

#include<iostream>

using namespace std;

class Edge
{
private:
	string hour;
	string duration;
	string voo;
public:
	Edge();
	~Edge();
	Edge(string hour, string duration, string voo);
	string getHour() {
		return this->hour;
	};
	string getDuration() {
		return this->duration;
	};
	string getVoo() {
		return this->voo;
	}
	void setHour(string hour) {
		this->hour = hour;
	};
	void setDuration(string duration) {
		this->duration = duration;
	};
	void setVoo(string voo) {
		this->voo = voo;
	};
};

