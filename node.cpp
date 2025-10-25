#include "node.h"

#include "edge.h"

#include <iostream>

Node::Node(float weight) :delay(weight)
{
}

void Node::connct_to(Edge* edge)
{
	if (!out_edges) {
		out_edges = edge;
		return;
	}
	Edge* next = out_edges;
	while(next->next_out) next = next->next_out;
	next->next_out = edge;
}

void Node::conncted_from(Edge* edge)
{
	if (!in_edges) {
		in_edges = edge;
		return;
	}
	Edge* next = in_edges;
	while (next->next_in) next = next->next_in;
	next->next_in = edge;
}

float Node::calcule_AAT()
{
	if(aat_fixed) return AAT;

	Edge* next = in_edges;
	float max = 0;
	float aat;
	while (next) {
		aat = next->delay + next->from->calcule_AAT() + delay;
		if (aat > max) {
			max = aat;
		}
		next = next->next_in;
	}
	AAT = max;
	aat_fixed = true;
	return AAT;
}

float Node::calcule_RAT()
{
	if(rat_fixed) return RAT;

	Edge* next = out_edges;
	float min = 1000000;
	float rat;
	while (next) {
		rat = next->to->calcule_RAT() - next->to->delay - next->delay;
		if (rat < min) {
			min = rat;
		}
		next = next->next_out;
	}
	RAT = min;
	rat_fixed = true;
	return RAT;
}

void Node::print()
{
	std::cout << "AAT: " << AAT << std::endl;
	std::cout << "RAT: " << RAT << std::endl;
	std::cout << "slack: " << slack << std::endl;
}
