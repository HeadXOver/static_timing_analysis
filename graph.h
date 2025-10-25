#pragma once

#include <vector>

struct Node;
struct Edge;

//////////////////////////////////////////////////////
//@brief Graph类，包含节点和边
//////////////////////////////////////////////////////

class Graph
{
public:
	Graph(int n, const std::vector<float>& weights);
	~Graph();

	// 计算节点的aat, rat, slack
	void update_aat();
	void update_rat(); 
	void update_slack();

	void set_rat(int index, float value);

	void print() const;

	// @brief 添加有向边
	void connect(int from, int to, float weight);

private:
	std::vector<Node*> nodes;
	std::vector<Edge*> edges;
};

