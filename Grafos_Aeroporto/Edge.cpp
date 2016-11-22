#include "Edge.h"

Edge::Edge()
{
}

Edge::~Edge()
{
}

Edge::Edge(string hour, string duration, string voo) {
	this->duration = duration;
	this->hour = hour;
	this->voo = voo;
}