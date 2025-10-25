#pragma once

struct Edge;

/////////////////////////////////////////////////////////////
//@brief Node�࣬ʮ���������и��������ӳ٣�aat��rat,�Լ�slack
//@details aat_fixed���ڵݹ��㷨����¼aat�Ƿ񱻼������rat_fixedͬ��
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

