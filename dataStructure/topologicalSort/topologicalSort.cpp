#include <iostream>
#include <stack>
using namespace std;
const int N = 10010;
using vnodeType = int;
typedef struct Node
{
	int adj;
	int w;
	Node *next;
}Node;

typedef struct Vnode
{
	int indegree;
	vnodeType v;
	Node *firstEdge;
}Vnode;


class Graph
{
public:
	void createGraph()
	{
		int n, m;
        cout << "请输入node节点数：" << endl;
		cin >> n;
        cout << "请输入弧个数：" << endl;
        cin >> m;
		vnodeNum = n;
		edgeNum = m;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i << "个顶点要存储的信息" << endl;
			cin >> adjlist[i].v;
			adjlist[i].firstEdge = nullptr;
		}

		for (int i = 0; i < m; i++)
		{
			int x, y;
            cout << "请输入node间连接关系：" << endl;
			cin >> x >> y;
			Node *p = new Node;
			p->adj = y;
			p->next = adjlist[x].firstEdge;
			adjlist[x].firstEdge = p;
		}
	}

	void findIndegree()
	{
		for (int i = 0; i < vnodeNum; i++)
		{
			adjlist[i].indegree = 0;
		}
		for (int i = 0; i < vnodeNum; i++)
		{
			for (Node *p = adjlist[i].firstEdge; p; p = p->next)
			{
				adjlist[p->adj].indegree++;
			}
		}
	}

	void Top_sort()
	{
		int cnt = vnodeNum;
		findIndegree();
		stack<int>s;
		for (int i = 0; i < vnodeNum; i++)
		{
			if (!adjlist[i].indegree) s.push(i);
		}

		while (!s.empty())
		{
			int  xx = s.top();
			cout << adjlist[xx].v << " ";
			cnt--;
			s.pop();
			for (Node *p = adjlist[xx].firstEdge; p; p = p->next)
			{
				int yy = p->adj;
				adjlist[yy].indegree--;
				if (!adjlist[yy].indegree) s.push(yy);
			}
		}
        cout << endl;

		if (cnt)
            cout << "The network has a cycle" << endl;
	}

private:
	int vnodeNum;
	int edgeNum;
	Vnode adjlist[N];

};



int  main()
{
	Graph g;
	g.createGraph();
	g.Top_sort();

	return 0;
}
