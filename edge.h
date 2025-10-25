#pragma once

struct Node;

//////////////////////////////////////////////////////
//@brief Edge类，十字链表，含浮点数的延迟
//////////////////////////////////////////////////////

struct Edge
{
	Edge(float delay, Node* from, Node* to);

	float delay;
	Node* from = nullptr;
	Node* to = nullptr;
	Edge* next_out = nullptr;
	Edge* next_in = nullptr;
};

