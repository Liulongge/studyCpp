#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

typedef struct myStruct_
{
    bool is_error;
    bool is_visited;
    bool is_root;
    list<int> myList;
} myStruct;

// 图的类定义
class Graph {

public:
    // 构造函数
    Graph()
    {
        error_node_ref_.clear();
    }

    // 添加边
    void addEdge(int v, int w)
    {
        adjList_[v].myList.push_back(w);
    }

    void addNode(int node_ref, bool is_root)
    {
        adjList_[node_ref].is_error = false;
        adjList_[node_ref].is_root = is_root;
        adjList_[node_ref].is_visited = false;
    }

    void addError(int node_ref)
    {
        adjList_[node_ref].is_error = true;
        if(adjList_[node_ref].is_root)
        {
            DFS(node_ref);
            cout << "Depth First Traversal: ";
            for (const auto& element : error_node_ref_)
            {
                printf("%x ", element);
            }
            printf("\n");
        }
    }

    void clearError(int node_ref)
    {
        adjList_[node_ref].is_error = false;
    }

    // 深度优先搜索递归函数
    void DFSUtil(int v)
    {
        // 对所有邻接顶点递归调用DFSUtil函数
        for (auto i = adjList_[v].myList.begin(); i != adjList_[v].myList.end(); ++i)
        {
            if(adjList_[*i].is_error == true)
            {
                DFSUtil(*i);
                if (adjList_[*i].myList.empty()) // node没有子node时，为根因
                {
                    error_node_ref_.push_back(*i);
                }
            }
        }
    }

    // 执行深度优先搜索
    void DFS(int node_ref)
    {
        // 如果报错节点没有子节点，则节点就是根因
        if (adjList_[node_ref].myList.empty())
        {
            error_node_ref_.push_back(node_ref);
        }

        // 对每个未被访问的顶点调用DFSUtil函数
        for (auto iter = adjList_[node_ref].myList.begin(); iter != adjList_[node_ref].myList.end(); ++iter) 
        {
            if(adjList_[*iter].is_error == true)
            {
                DFSUtil(*iter);
            }

        }
    }
private:
    map<int, myStruct> adjList_;    // 邻接表
    list<int> error_node_ref_;
};

int main() {
    Graph graph;
    graph.addNode(0x10, false);
    graph.addNode(0x11, false);
    graph.addNode(0x12, false);
    graph.addNode(0x13, false);
    graph.addNode(0x14, false);
    graph.addNode(0x15, false);
    graph.addNode(0x16, false);
    graph.addNode(0x17, true);
    graph.addNode(0x18, false);

    graph.addEdge(0x10, 0x11);
    graph.addEdge(0x10, 0x12);
    graph.addEdge(0x11, 0x13);
    graph.addEdge(0x11, 0x14);
    graph.addEdge(0x12, 0x15);
    graph.addEdge(0x12, 0x16);
    graph.addEdge(0x13, 0x17);
    graph.addEdge(0x14, 0x17);
    graph.addEdge(0x15, 0x18);

    graph.addError(0x17);
    graph.addError(0x14);
    graph.addError(0x13);
    graph.addError(0x11);
    graph.addError(0x10);




    return 0;
}