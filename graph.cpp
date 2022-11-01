#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Node;
class Edge;
class Graph
{
public:
    //保存所有的节点以及对应的编号
    unordered_map<int, Node> nodes;
    //保存所有的边
    unordered_set<Edge> edges;
};
class Node
{
public:
    //点的值
    int val = 0;
    //入度，即有多少个边指向这个点
    int in = 0;
    //出度，这个点指出去几条边
    int out = 0;

    //保存这个点指向的点
    vector<Node> nexts;
    //保存这个点所有指出去的边
    vector<Edge> edges;
    Node() = default;
    Node(int value) : val(value) {}

private:
};
class Edge
{
public:
    //这条边的权重
    int weight = 0;

    //这条边的起点
    Node from;
    //这条边的终点
    Node to;
    Edge() = default;
    Edge(int w) : weight(w) {}
};

int main()
{

    cout << sizeof(Graph) << "\n";
}