#pragma once

struct Edge;

/////////////////////////////////////////////////////////////
//@brief Node类，十字链表，含有浮点数的延迟，aat和rat,以及slack
//@details aat_fixed用于递归算法，记录aat是否被计算过，rat_fixed同理
/////////////////////////////////////////////////////////////

struct Node
{
	Node(float weight);

	void connct_to(Edge* edge);
	void conncted_from(Edge* edge);

	float calcule_AAT();
	float calcule_RAT();

	void print();

	float delay;
	Edge* in_edges = nullptr;
	Edge* out_edges = nullptr;

	float AAT{};
	bool aat_fixed = false;
	float RAT{};
	bool rat_fixed = false;
	float slack{};
};

