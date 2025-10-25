#include "graph.h"

#include "node.h"
#include "edge.h"

#include <iostream>

Graph::Graph(int n, const std::vector<float>& weights)
{
	for (int i = 0; i < n; i++) {
		nodes.push_back(new Node(weights[i]));
	}
}

Graph::~Graph()
{
	for (auto node : nodes) delete node;
	for (auto edge : edges) delete edge;
}

void Graph::update_aat()
{
	for (auto node : nodes) {
		node->calcule_AAT();
	}
}

void Graph::update_rat()
{
	for (auto node : nodes) {
		node->calcule_RAT();
	}
}

void Graph::update_slack()
{
	for (auto node : nodes) {
		node->slack = node->RAT - node->AAT;
	}
}

void Graph::set_rat(int index, float value)
{
	nodes[index]->RAT = value;
	nodes[index]->rat_fixed = true;
}

void Graph::print() const
{
	for (int i = 0; i < nodes.size(); i++) {
		std::cout << "Node " << i << ": " << std::endl;
		nodes[i]->print();
	}
}

void Graph::connect(int from, int to, float weight)
{
	Edge* edge = new Edge(weight, nodes[from], nodes[to]);
	edges.push_back(edge);
	nodes[from]->connct_to(edge);
	nodes[to]->conncted_from(edge);
}
