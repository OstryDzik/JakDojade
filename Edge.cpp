#include "Edge.h"


Edge::Edge(void)
{
}

Edge::Edge(int id, int type, int len, Node* destination)
{
	this->id = id;
	this->type = type;
	this->len = len;
	this->destination = destination;
}

Edge::~Edge(void)
{
}
