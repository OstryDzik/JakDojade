#pragma once
#include "Node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std; 

class RouteFinder
{
private:
	int idCounter;
	map<string, Node> nodes;
public:
	RouteFinder(void);
	bool LoadGraph(string filename);
	void ParseEntry(string line);
	bool AddEntry(string source, string destination, int tramLen, int busLen);
	~RouteFinder(void);
};

