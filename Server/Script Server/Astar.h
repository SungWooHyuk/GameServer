#pragma once
#include <iostream>
#include <list>

using namespace std;

struct Node
{
	Node* Parent;
	int p_x;
	int p_y;
	int g, h, f;

	Node(int x, int y, Node* parent)
	{
		p_x = x;
		p_y = y;
		Parent = parent;
	}
};

struct Pos
{
	int x;
	int y;
};

class Astar
{
public:
	int endX, endY;
	int startX, startY;
	list<Node*> openList;
	list<Node*> clostList;
	void setStart(int x, int y, int x2, int y2);
	void setH(Node* Node);
	void setF(Node* Node);
	
public :
	~Astar();

};

struct _NODE
{
	int ix;
	int iy;
	_NODE* pParent; // 전에 방문했던 노드

	double	F;	//G+H
	double	G;	//출발점
	int		H;	//목적지와 거리


	_NODE(int x, int y, _NODE* parent)
	{
		ix = x;
		iy = y;
		pParent = parent;
	}
};

class CAStar
{

public:
	int iendX;
	int iendY;
	int istartX;
	int istartY;
	_NODE* endNode;
public:
	std::list<_NODE*> openList; // 아직 방문하지 않은곳들 
	std::list<_NODE*> closeList; // 이미 방문했거나 갈수없는 노드들의 집합


public:
	CAStar();
	~CAStar();


	//직선
	void setG(_NODE* _node);
	//대각선
	void setG_dia(_NODE* _node);
	bool compareG(int** mapData, _NODE* _node, bool isDia, int dir);

	void setH(_NODE* _node);
	void setF(_NODE* _node);

	void setEndPos(int x, int y);
	void setStartPos(int x, int y);
	bool returnPos(int* x, int* y); //공격시작이면 true

	bool searchLoad(int** mapData, int _startX, int _startY, int _endX, int _endY);
	//void searchLoad(HWND hWnd);

	void pathDraw();
	//void pathDraw(HWND hWnd);

	void setEndNodeNULL();
	bool isEndNode();

};



