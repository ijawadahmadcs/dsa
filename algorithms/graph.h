#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

struct EdgeNode
{
    int dest;
    int weight;
    EdgeNode* link;
};

struct GraphNode
{
    int name;
    GraphNode* next;
    EdgeNode* adj;
};

struct KEdge
{
    int src;
    int dest;
    int weight;
};

class Graph
{
private:
    GraphNode* start;
    int n;

    GraphNode* findNode(int vertex);

public:
    Graph();

    void addVertex(int vertex);
    void addEdge(int src, int dest, int weight);

    void display();

    void prims(int startVertex);
    void kruskal();
};

#endif