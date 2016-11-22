#include "Edge.h"

Edge::Edge()
{
}

Edge::~Edge()
{
}

Edge::Edge(string hour, string duration) {
	this->duration = duration;
	this->hour = hour;
}