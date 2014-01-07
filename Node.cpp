#include "Node.h"


Node::Node(void)
{
}

Node::Node(int id)
{
	this->id = id;
}

Node::~Node(void)
{
}


bool Node::AddEdge(Edge newEdge)
{
	int count = edges.size();
	if (count<=1)
	{
		edges.push_back(newEdge);
		return true;
	}
	int tmpcount =0;
	for (int i = 0; i < count; i++)
	{
		if (edges[i].GetId() == newEdge.GetId())
		{
			tmpcount++;
		}
		if (tmpcount>=2)
		{
			return false;
		}
	}
	edges.push_back(newEdge);
	return true;
}