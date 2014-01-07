#pragma once
#include "Edge.h"
#include <vector>
using namespace std;

class Node
{
private:
	int id;
	vector<Edge> edges; 
	
public:
	Node(void);
	Node (int id);
	~Node(void);
	bool AddEdge(Edge newEdge);
	int GetId() {return id;};
};

