#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

typedef struct myStruct_
{
    bool is_error;
    bool is_visited;
    list<int> myList;
} myStruct;

// 图的类定义
class Graph {

    // 深度优先搜索递归函数
    void DFSUtil(int v)
    {
        adjList_[v].is_visited = true;
        printf("-> %x ", v);

        // 对所有邻接顶点递归调用DFSUtil函数
        for (auto i = adjList_[v].myList.begin(); i != adjList_[v].myList.end(); ++i)
        {
            if(! adjList_[*i].is_visited)
            {
                DFSUtil(*i);
            }
        }           
    }

public:
    // 构造函数
    Graph(int V) {}

    // 添加边
    void addEdge(int v, int w)
    {
        adjList_[v].is_error = adjList_[v].is_error == false ? adjList_[v].is_error : false;
        adjList_[w].is_error = adjList_[w].is_error == false ? adjList_[w].is_error : false;
        adjList_[v].is_visited = adjList_[v].is_visited == false ? adjList_[v].is_visited : false;
        adjList_[w].is_visited = adjList_[w].is_visited == false ? adjList_[w].is_visited : false;
        adjList_[v].myList.push_back(w);
    }

    void addError(int node_ref)
    {
        adjList_[node_ref].is_error = true;
    }

    void clearError(int node_ref)
    {
        adjList_[node_ref].is_error = false;
    }

    // 执行深度优先搜索
    void DFS(int node_ref)
    {
        printf("-> %x ", node_ref);
        // 对每个未被访问的顶点调用DFSUtil函数
        for (auto iter = adjList_[node_ref].myList.begin(); iter != adjList_[node_ref].myList.end(); ++iter) 
        {
            if(! adjList_[*iter].is_visited)
            {
                DFSUtil(*iter);
            }
        }
        printf("\n");
    }
private:
    map<int, myStruct> adjList_;    // 邻接表
};

int main() {
    Graph graph(9);
    graph.addEdge(0x10, 0x11);
    graph.addEdge(0x10, 0x12);
    graph.addEdge(0x11, 0x13);
    graph.addEdge(0x11, 0x14);
    graph.addEdge(0x12, 0x15);
    graph.addEdge(0x12, 0x16);
    graph.addEdge(0x13, 0x17);
    graph.addEdge(0x14, 0x17);
    graph.addEdge(0x15, 0x18);



    cout << "Depth First Traversal: ";
    graph.DFS(0x10);

    return 0;
}