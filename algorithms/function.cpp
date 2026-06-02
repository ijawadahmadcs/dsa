#include "Graph.h"

Graph::Graph()
{
    start = NULL;
    n = 0;
}

GraphNode* Graph::findNode(int vertex)
{
    GraphNode* p = start;

    while(p != NULL)
    {
        if(p->name == vertex)
            return p;

        p = p->next;
    }

    return NULL;
}

void Graph::addVertex(int vertex)
{
    if(findNode(vertex) != NULL)
        return;

    GraphNode* temp = new GraphNode;

    temp->name = vertex;
    temp->adj = NULL;
    temp->next = NULL;

    if(start == NULL)
        start = temp;
    else
    {
        GraphNode* p = start;

        while(p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    n++;
}

void Graph::addEdge(int src, int dest, int weight)
{
    GraphNode* u = findNode(src);
    GraphNode* v = findNode(dest);

    if(u == NULL || v == NULL)
        return;

    EdgeNode* e1 = new EdgeNode;
    e1->dest = dest;
    e1->weight = weight;
    e1->link = u->adj;
    u->adj = e1;

    EdgeNode* e2 = new EdgeNode;
    e2->dest = src;
    e2->weight = weight;
    e2->link = v->adj;
    v->adj = e2;
}

void Graph::display()
{
    GraphNode* p = start;

    while(p != NULL)
    {
        cout << p->name << " -> ";

        EdgeNode* q = p->adj;

        while(q != NULL)
        {
            cout << "(" << q->dest
                 << "," << q->weight
                 << ") ";

            q = q->link;
        }

        cout << endl;

        p = p->next;
    }
}

void Graph::prims(int startVertex)
{
    int key[MAX + 1];
    int parent[MAX + 1];
    bool mstSet[MAX + 1];

    for(int i=0;i<=MAX;i++)
    {
        key[i] = INF;
        parent[i] = -1;
        mstSet[i] = false;
    }

    key[startVertex] = 0;

    for(int count=0; count<n; count++)
    {
        int u = -1;
        int min = INF;

        for(int i=1;i<=MAX;i++)
        {
            if(!mstSet[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        mstSet[u] = true;

        GraphNode* node = findNode(u);

        if(node == NULL)
            continue;

        EdgeNode* p = node->adj;

        while(p != NULL)
        {
            int v = p->dest;

            if(!mstSet[v] &&
               p->weight < key[v])
            {
                key[v] = p->weight;
                parent[v] = u;
            }

            p = p->link;
        }
    }

    cout << "\nPrim MST\n";

    int total = 0;

    for(int i=1;i<=MAX;i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i]
                 << " -> "
                 << i
                 << " Weight="
                 << key[i]
                 << endl;

            total += key[i];
        }
    }

    cout << "Total Cost = "
         << total
         << endl;
}

int findSet(int parent[], int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int parent[], int x, int y)
{
    int px = findSet(parent,x);
    int py = findSet(parent,y);

    parent[px] = py;
}

void Graph::kruskal()
{
    KEdge edges[100];
    int edgeCount = 0;

    GraphNode* u = start;

    while(u != NULL)
    {
        EdgeNode* e = u->adj;

        while(e != NULL)
        {
            if(u->name < e->dest)
            {
                edges[edgeCount].src = u->name;
                edges[edgeCount].dest = e->dest;
                edges[edgeCount].weight = e->weight;

                edgeCount++;
            }

            e = e->link;
        }

        u = u->next;
    }

    for(int i=0;i<edgeCount-1;i++)
    {
        for(int j=0;j<edgeCount-i-1;j++)
        {
            if(edges[j].weight >
               edges[j+1].weight)
            {
                KEdge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int parent[MAX+1];

    for(int i=0;i<=MAX;i++)
        parent[i] = i;

    cout << "\nKruskal MST\n";

    int total = 0;
    int selected = 0;

    for(int i=0;
        i<edgeCount && selected<n-1;
        i++)
    {
        int x =
        findSet(parent, edges[i].src);

        int y =
        findSet(parent, edges[i].dest);

        if(x != y)
        {
            cout << edges[i].src
                 << " -> "
                 << edges[i].dest
                 << " Weight="
                 << edges[i].weight
                 << endl;

            total += edges[i].weight;

            unionSet(parent,x,y);

            selected++;
        }
    }

    cout << "Total Cost = "
         << total
         << endl;
}



/*#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    for(int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for(int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i < n1)
        arr[k++] = left[i++];

    while(j < n2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}


void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main(){
    int arr[] = {64, 25, 12, 22, 11};
int n = 5;

quickSort(arr, 0, n - 1);
bubbleSort(arr, n);
 selectionSort(arr, n);
 mergeSort(arr, 0, n - 1);

display(arr, n);
}*/