#include "RouteFinder.h"


RouteFinder::RouteFinder(void)
{
	idCounter = 0;
}


RouteFinder::~RouteFinder(void)
{
}

bool RouteFinder::AddEntry(string source, string destination, int tramLen, int busLen)  //dodaje krawêdŸ (i ewentualnie wêz³y) do grafu
{
	map<string, Node>::iterator it = nodes.find(source);
	map<string, Node>::iterator it2 = nodes.find(destination);
	if (it == nodes.end()) //jesli nie bylo takiego przystanku dodajemy
	{
		it = (nodes.insert(pair<string,Node>(source, Node(idCounter++)))).first;
	}
	if (it2 == nodes.end()) //j.w.
	{
		it2 = (nodes.insert(pair<string,Node>(destination, Node(idCounter++)))).first;
	}
	Edge newEdge;
	if (tramLen!=0)
	{
		newEdge = Edge(it2->second.GetId(), TRAM, tramLen, &it2->second);
		it->second.AddEdge(newEdge);
	}
	if (busLen!=0)
	{
		newEdge = Edge(it2->second.GetId(), BUS, busLen, &it2->second);
		it->second.AddEdge(newEdge);
	}
	return true;
}

void RouteFinder::ParseEntry(string line)
{
	string source;
	string destination;
	int busLen;
	int tramLen;
	int i,j;  //indices of beginning and end of a station name
	i = line.find('"');
	if (i == string::npos)
	{
		cout << "corrupted data\n";
		return;
	}
	j = line.find('"', i+1);
	source = line.substr(i, j-i+1);
	i = line.find('"', j+1);
	j = line.find('"', i+1);
	destination = line.substr(i, j-i+1);
	line = line.erase(0, j+1);
	stringstream tmp;
	tmp.str(line);
	tmp >> tramLen >> busLen;
	AddEntry(source, destination, tramLen, busLen);
}