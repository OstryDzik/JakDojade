#pragma once
#define BUS 1
#define TRAM 0
class Node;

class Edge
{
private:
	int id;
	int type;
	int len;
	Node* destination;
public:
	Edge(void);
	Edge(int id, int type, int len, Node* destination);
	~Edge(void);
	int GetId() {return id;};
	int GetType() {return type;};
	int GetLen() {return len;};
	Node* operator-> () {return destination;};
	Node* GetDest() {return destination;};
};
