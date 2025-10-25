///////////////////////////////////////////////
// 本程序实现的是静态时序分析的算法，位于课本224页
// 用的是十字链表，方便处理有向图
// 用递归方法，无需拓扑排序
////////////////////////////////////////////////

#include <iostream>

#include "graph.h"

int main() 
{
	// 9个节点，并输入延迟
	Graph graph(9, {0.f, 0.f, 0.f, 0.f, 1.f, 2.f, 2.f, 2.f, 0.f});

	// 11条边，并输入延迟
	graph.connect(0, 1, 0.f);
	graph.connect(0, 2, 0.f);
	graph.connect(0, 3, 0.6f);
	graph.connect(1, 5, 0.15f);
	graph.connect(2, 4, 0.1f);
	graph.connect(3, 6, 0.1f);
	graph.connect(4, 5, 0.1f);
	graph.connect(4, 6, 0.3f);
	graph.connect(5, 7, 0.2f);
	graph.connect(6, 7, 0.25f);
	graph.connect(7, 8, 0.2f);


	// 设置最后一个节点的rat
	graph.set_rat(8, 5.5f);

	// 更新所有节点的aat、rat和slack
	graph.update_aat();
	graph.update_rat();
	graph.update_slack();

	// 展示
	graph.print();

	return 0;
}