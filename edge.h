#pragma once

struct Node;

//////////////////////////////////////////////////////
//@brief Edge�࣬ʮ�����������������ӳ�
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

