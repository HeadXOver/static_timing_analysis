///////////////////////////////////////////////
// ������ʵ�ֵ��Ǿ�̬ʱ��������㷨��λ�ڿα�224ҳ
// �õ���ʮ���������㴦������ͼ
// �õݹ鷽����������������
////////////////////////////////////////////////

#include <iostream>

#include "graph.h"

int main() 
{
	// 9���ڵ㣬�������ӳ�
	Graph graph(9, {0.f, 0.f, 0.f, 0.f, 1.f, 2.f, 2.f, 2.f, 0.f});

	// 11���ߣ��������ӳ�
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


	// �������һ���ڵ��rat
	graph.set_rat(8, 5.5f);

	// �������нڵ��aat��rat��slack
	graph.update_aat();
	graph.update_rat();
	graph.update_slack();

	// չʾ
	graph.print();

	return 0;
}