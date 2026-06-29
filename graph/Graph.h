#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <climits>
using namespace std;
#define INFINITY_VAL 9999
#define MAX 20

struct EdgeNode {
    int dest;          // destination node number
    int weight;        // edge weight (0 if unweighted)
    EdgeNode *link;    // pointer to next adjacent node
};

struct KEdge
{
    int src;
    int dest;
    int weight;
};

// ─────────────────────────────────────────────
//  Header node in the node list
// ─────────────────────────────────────────────
struct GraphNode {
    int name;          // node number
    GraphNode *next;   // pointer to next node in node list
    EdgeNode  *adj;    // pointer to first adjacent edge node
};

// ─────────────────────────────────────────────
//  Dijkstra state per node
// ─────────────────────────────────────────────
#define TEMP 0
#define PERM 1

struct NodeState {
    int predecessor;
    int dist;
    int status;
};

struct QueueNode {
    int data;
    QueueNode *next;
};

struct StackNode {
    int data;
    StackNode *next;
};

class Graph {
private:
    GraphNode *start;   // head of the node list
    int        n;       // number of nodes
    GraphNode *findNode(int name);
    bool visited[MAX + 1];
    QueueNode *qFront;
    QueueNode *qRear;
    void   enqueue(int val);
    int    dequeue();
    bool   isQueueEmpty();

    StackNode *stackTop;
    void   push(int val);
    int    pop();
    bool   isStackEmpty();
    int    peek();
    void dfs_rec(int v);
    int  findMinTemp(NodeState state[], int n);

public:
    Graph();
    ~Graph();
    void insert_node(int nodeName);
    void insert_edge(int u, int v, int weight = 1);
    void delete_node(int u);
    void delete_edge(int u, int v);
    void display();
    void dfs(int startNode);              // iterative (stack)
    void dfs_recursive(int startNode);   // recursive
    void bfs(int startNode);
    void dijkstra(int source, int dest);
    bool isComplete();
    bool isConnected();
    void pathOfLength(int src, int dst, int length);
    void prims(int startNode);
void kruskal(); 
};

#endif // GRAPH_H
