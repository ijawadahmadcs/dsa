#include "Graph.h"
#include <cstring>   // memset

// ═══════════════════════════════════════════════════════════════════
//  Constructor / Destructor
// ═══════════════════════════════════════════════════════════════════

Graph::Graph() {
    start    = NULL;
    n        = 0;
    qFront   = NULL;
    qRear    = NULL;
    stackTop = NULL;
    memset(visited, false, sizeof(visited));
}

Graph::~Graph() {
    // free all edge lists, then all graph nodes
    GraphNode *ptr = start;
    while (ptr != NULL) {
        EdgeNode *eq = ptr->adj;
        while (eq != NULL) {
            EdgeNode *tmp = eq;
            eq = eq->link;
            delete tmp;
        }
        GraphNode *tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    // free any leftover queue nodes
    while (!isQueueEmpty()) dequeue();
    // free any leftover stack nodes
    while (!isStackEmpty()) pop();
}

//  findNode – locate a GraphNode by its integer name
GraphNode *Graph::findNode(int name) {
    GraphNode *ptr = start;
    while (ptr != NULL) {
        if (ptr->name == name)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

//  Linked-list Queue  (used by BFS and topological sort)
void Graph::enqueue(int val) {
    QueueNode *tmp = new QueueNode;
    tmp->data = val;
    tmp->next = NULL;
    if (qRear == NULL) {
        qFront = qRear = tmp;
    } else {
        qRear->next = tmp;
        qRear = tmp;
    }
}

int Graph::dequeue() {
    if (isQueueEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }
    QueueNode *tmp = qFront;
    int val = tmp->data;
    qFront = qFront->next;
    if (qFront == NULL) qRear = NULL;
    delete tmp;
    return val;
}

bool Graph::isQueueEmpty() {
    return (qFront == NULL);
}

// ═══════════════════════════════════════════════════════════════════
//  Linked-list Stack  (used by iterative DFS)
// ═══════════════════════════════════════════════════════════════════

void Graph::push(int val) {
    StackNode *tmp = new StackNode;
    tmp->data = val;
    tmp->next = stackTop;
    stackTop  = tmp;
}

int Graph::pop() {
    if (isStackEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    StackNode *tmp = stackTop;
    int val = tmp->data;
    stackTop = stackTop->next;
    delete tmp;
    return val;
}

bool Graph::isStackEmpty() {
    return (stackTop == NULL);
}

int Graph::peek() {
    if (isStackEmpty()) return -1;
    return stackTop->data;
}

// ═══════════════════════════════════════════════════════════════════
//  insert_node  (mirror of PDF insert_node function)
//  – adds a new header node at the end of the node list
// ═══════════════════════════════════════════════════════════════════

void Graph::insert_node(int nodeName) {
    // check for duplicate
    if (findNode(nodeName) != NULL) {
        cout << "Node " << nodeName << " already exists.\n";
        return;
    }

    GraphNode *tmp = new GraphNode;
    tmp->name = nodeName;
    tmp->next = NULL;
    tmp->adj  = NULL;

    n++;  // increase number of nodes
    cout << "The inserted node is " << nodeName << "\n";

    if (start == NULL) {
        start = tmp;
        return;
    }
    // append at end (preserves insertion order as in the PDF)
    GraphNode *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = tmp;
}

// ═══════════════════════════════════════════════════════════════════
//  insert_edge  (mirror of PDF insert_edge function)
//  – directed by default; weight=1 for unweighted graphs
// ═══════════════════════════════════════════════════════════════════

void Graph::insert_edge(int u, int v, int weight) {
    GraphNode *locu = findNode(u);
    GraphNode *locv = findNode(v);

    if (locu == NULL) {
        cout << "Source node not present, first insert node " << u << "\n";
        return;
    }
    if (locv == NULL) {
        cout << "Destination node not present, first insert node " << v << "\n";
        return;
    }

    // build new edge node
    EdgeNode *tmp = new EdgeNode;
    tmp->dest   = v;
    tmp->weight = weight;
    tmp->link   = NULL;

    // append at the end of locu's adjacency list
    if (locu->adj == NULL) {
        locu->adj = tmp;
        return;
    }
    EdgeNode *ptr = locu->adj;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = tmp;
}

// ═══════════════════════════════════════════════════════════════════
//  delete_node  (mirrors PDF delete_node + delnode_edge in one step)
//  1. Remove the header node from the node list.
//  2. Remove every edge in other nodes' adj lists that points to u.
// ═══════════════════════════════════════════════════════════════════

void Graph::delete_node(int u) {
    if (n == 0) {
        cout << "Graph is empty\n";
        return;
    }
    if (findNode(u) == NULL) {
        cout << "This node is not present in the graph\n";
        return;
    }

    // ── step 1: remove u from header node list ──
    if (start->name == u) {
        GraphNode *tmp = start;
        start = start->next;
        // free its adjacency list
        EdgeNode *eq = tmp->adj;
        while (eq != NULL) {
            EdgeNode *te = eq;
            eq = eq->link;
            delete te;
        }
        delete tmp;
    } else {
        GraphNode *q = start;
        while (q->next != NULL && q->next->name != u)
            q = q->next;
        if (q->next != NULL) {
            GraphNode *tmp = q->next;
            q->next = tmp->next;
            // free its adjacency list
            EdgeNode *eq = tmp->adj;
            while (eq != NULL) {
                EdgeNode *te = eq;
                eq = eq->link;
                delete te;
            }
            delete tmp;
        }
    }
    n--;

    // ── step 2: remove all edges coming INTO u from every other node ──
    GraphNode *ptr = start;
    while (ptr != NULL) {
        // check first edge node
        while (ptr->adj != NULL && ptr->adj->dest == u) {
            EdgeNode *tmp = ptr->adj;
            ptr->adj = ptr->adj->link;
            delete tmp;
        }
        if (ptr->adj == NULL) {
            ptr = ptr->next;
            continue;
        }
        EdgeNode *q = ptr->adj;
        while (q->link != NULL) {
            if (q->link->dest == u) {
                EdgeNode *tmp = q->link;
                q->link = tmp->link;
                delete tmp;
                // continue scanning (don't advance q)
            } else {
                q = q->link;
            }
        }
        ptr = ptr->next;
    }
}

// ═══════════════════════════════════════════════════════════════════
//  delete_edge  (mirror of PDF del_edge function)
//  – removes the directed edge u→v
// ═══════════════════════════════════════════════════════════════════

void Graph::delete_edge(int u, int v) {
    GraphNode *locu = findNode(u);

    if (locu == NULL) {
        cout << "Source node not present\n";
        return;
    }

    // check first adj node
    if (locu->adj != NULL && locu->adj->dest == v) {
        EdgeNode *tmp = locu->adj;
        locu->adj = locu->adj->link;
        delete tmp;
        return;
    }

    EdgeNode *q = locu->adj;
    while (q != NULL && q->link != NULL) {
        if (q->link->dest == v) {
            EdgeNode *tmp = q->link;
            q->link = tmp->link;
            delete tmp;
            return;
        }
        q = q->link;
    }
    cout << "This edge does not exist\n";
}

// ═══════════════════════════════════════════════════════════════════
//  display  (mirror of PDF display function)
// ═══════════════════════════════════════════════════════════════════

void Graph::display() {
    GraphNode *ptr = start;
    while (ptr != NULL) {
        cout << ptr->name << " ->";
        EdgeNode *q = ptr->adj;
        while (q != NULL) {
            cout << " " << q->dest;
            if (q->weight > 1) cout << "(" << q->weight << ")";
            q = q->link;
        }
        cout << "\n";
        ptr = ptr->next;
    }
}

// ═══════════════════════════════════════════════════════════════════
//  dfs_rec  (mirror of PDF dfs_rec recursive function)
// ═══════════════════════════════════════════════════════════════════

void Graph::dfs_rec(int v) {
    visited[v] = true;
    cout << v << " ";
    GraphNode *loc = findNode(v);
    if (loc == NULL) return;
    EdgeNode *q = loc->adj;
    while (q != NULL) {
        if (!visited[q->dest])
            dfs_rec(q->dest);
        q = q->link;
    }
}

void Graph::dfs_recursive(int startNode) {
    // reset visited
    GraphNode *ptr = start;
    while (ptr != NULL) {
        visited[ptr->name] = false;
        ptr = ptr->next;
    }
    cout << "DFS (recursive) from " << startNode << ": ";
    dfs_rec(startNode);
    cout << "\n";
}

// ═══════════════════════════════════════════════════════════════════
//  dfs  – iterative stack-based (mirror of PDF dfs function)
// ═══════════════════════════════════════════════════════════════════

void Graph::dfs(int startNode) {
    // reset visited
    GraphNode *ptr = start;
    while (ptr != NULL) {
        visited[ptr->name] = false;
        ptr = ptr->next;
    }

    cout << "DFS (iterative) from " << startNode << ": ";

    push(startNode);

    while (!isStackEmpty()) {
        int pop_v = pop();

        if (!visited[pop_v]) {
            cout << pop_v << " ";
            visited[pop_v] = true;
        } else {
            continue;
        }

        // push all unvisited neighbours of pop_v (iterate in reverse
        // so that lower-numbered neighbours are processed first,
        // matching the PDF's for(i=n; i>=1; i--) loop order)
        GraphNode *loc = findNode(pop_v);
        if (loc == NULL) continue;

        // collect neighbours into a temporary array to push in reverse
        int neighbours[MAX];
        int cnt = 0;
        EdgeNode *q = loc->adj;
        while (q != NULL) {
            neighbours[cnt++] = q->dest;
            q = q->link;
        }
        // push in reverse order (last first) so first neighbour is on top
        for (int i = cnt - 1; i >= 0; i--) {
            if (!visited[neighbours[i]])
                push(neighbours[i]);
        }
    }
    cout << "\n";
}

//  bfs  (mirror of PDF bfs function)
void Graph::bfs(int startNode) {
    // reset visited
    GraphNode *ptr = start;
    while (ptr != NULL) {
        visited[ptr->name] = false;
        ptr = ptr->next;
    }
    // reset queue
    while (!isQueueEmpty()) dequeue();

    cout << "BFS from " << startNode << ": ";

    cout << startNode << " ";
    visited[startNode] = true;
    enqueue(startNode);

    while (!isQueueEmpty()) {
        int v = dequeue();

        GraphNode *loc = findNode(v);
        if (loc == NULL) continue;

        EdgeNode *q = loc->adj;
        while (q != NULL) {
            if (!visited[q->dest]) {
                cout << q->dest << " ";
                visited[q->dest] = true;
                enqueue(q->dest);
            }
            q = q->link;
        }
    }
    cout << "\n";
}

//  findMinTemp – helper for Dijkstra
//  Returns index of the PERM-eligible temporary node with min dist.
int Graph::findMinTemp(NodeState state[], int /*nodeCount*/) {
    int minDist = INFINITY_VAL + 1;
    int minIdx  = 0;
    // iterate over all actual nodes
    GraphNode *ptr = start;
    while (ptr != NULL) {
        int i = ptr->name;
        if (state[i].status == TEMP && state[i].dist < minDist) {
            minDist = state[i].dist;
            minIdx  = i;
        }
        ptr = ptr->next;
    }
    return minIdx;
}

//  dijkstra  (mirror of PDF findpath / Dijkstra logic)
void Graph::dijkstra(int source, int dest) {
    NodeState state[MAX + 1];

    // initialise all nodes as temporary with dist = infinity
    GraphNode *ptr = start;
    while (ptr != NULL) {
        int i = ptr->name;
        state[i].predecessor = 0;
        state[i].dist        = INFINITY_VAL;
        state[i].status      = TEMP;
        ptr = ptr->next;
    }

    // source node is permanent with dist = 0
    state[source].predecessor = 0;
    state[source].dist        = 0;
    state[source].status      = PERM;

    int current = source;

    // loop until destination becomes permanent
    while (current != dest) {
        // examine all temporary neighbours of current
        GraphNode *loc = findNode(current);
        if (loc != NULL) {
            EdgeNode *q = loc->adj;
            while (q != NULL) {
                int i = q->dest;
                if (state[i].status == TEMP) {
                    int newDist = state[current].dist + q->weight;
                    if (newDist < state[i].dist) {
                        state[i].predecessor = current;
                        state[i].dist        = newDist;
                    }
                }
                q = q->link;
            }
        }

        // find temporary node with minimum dist
        int minNode = findMinTemp(state, n);

        if (minNode == 0) {
            // no reachable temporary node – source/sink is isolated
            cout << "There is no path from source to destination node\n";
            return;
        }

        state[minNode].status = PERM;
        current = minNode;
    }

    // reconstruct path from destination back to source
    int path[MAX];
    int count = 0;
    int cur   = dest;
    while (cur != 0) {
        count++;
        path[count] = cur;
        cur = state[cur].predecessor;
    }

    // compute shortest distance
    int shortDist = 0;
    for (int i = count; i > 1; i--) {
        int u = path[i];
        int v = path[i - 1];
        GraphNode *locU = findNode(u);
        if (locU != NULL) {
            EdgeNode *eq = locU->adj;
            while (eq != NULL) {
                if (eq->dest == v) {
                    shortDist += eq->weight;
                    break;
                }
                eq = eq->link;
            }
        }
    }

    cout << "Shortest distance is: " << shortDist << "\n";
    cout << "Shortest Path is: ";
    for (int i = count; i > 1; i--)
        cout << path[i] << "->";
    cout << path[1] << "\n";
}

//  isComplete – every node is adjacent to every other node
bool Graph::isComplete() {
    // For a directed complete graph each node should have n-1 outgoing edges
    // to every other node (no self-loops expected).
    GraphNode *ptr = start;
    while (ptr != NULL) {
        // count out-degree
        int outDeg = 0;
        EdgeNode *q = ptr->adj;
        while (q != NULL) {
            outDeg++;
            q = q->link;
        }
        if (outDeg != n - 1) return false;
        ptr = ptr->next;
    }
    return true;
}

//  isConnected – undirected-style: every node reachable from node 1
//  (uses BFS internally without touching the public visited state)
bool Graph::isConnected() {
    if (start == NULL) return true;

    // local visited map
    bool vis[MAX + 1];
    memset(vis, false, sizeof(vis));

    // reset local queue
    while (!isQueueEmpty()) dequeue();

    int startName = start->name;
    vis[startName] = true;
    enqueue(startName);

    while (!isQueueEmpty()) {
        int v = dequeue();
        GraphNode *loc = findNode(v);
        if (loc == NULL) continue;
        EdgeNode *q = loc->adj;
        while (q != NULL) {
            if (!vis[q->dest]) {
                vis[q->dest] = true;
                enqueue(q->dest);
            }
            q = q->link;
        }
    }

    // check all nodes visited
    GraphNode *ptr = start;
    while (ptr != NULL) {
        if (!vis[ptr->name]) return false;
        ptr = ptr->next;
    }
    return true;
}

// helper: multiply two n×n matrices (1-indexed up to nodeCount)
static void multiplyMatrices(int a[][MAX], int b[][MAX], int c[][MAX], int nodeCount) {
    for (int i = 1; i <= nodeCount; i++)
        for (int j = 1; j <= nodeCount; j++) {
            c[i][j] = 0;
            for (int k = 1; k <= nodeCount; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void Graph::pathOfLength(int src, int dst, int length) {
    // build adjacency matrix from linked list (1-indexed)
    int adj[MAX][MAX];
    memset(adj, 0, sizeof(adj));

    GraphNode *ptr = start;
    while (ptr != NULL) {
        EdgeNode *q = ptr->adj;
        while (q != NULL) {
            adj[ptr->name][q->dest] = 1;
            q = q->link;
        }
        ptr = ptr->next;
    }

    // result starts as adj (power 1)
    int result[MAX][MAX];
    int temp[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            result[i][j] = adj[i][j];

    // multiply (length-1) more times to get adj^length
    for (int p = 1; p < length; p++) {
        multiplyMatrices(result, adj, temp, n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                result[i][j] = temp[i][j];
    }

    cout << "Number of paths of length " << length
         << " from node " << src << " to node " << dst
         << " is: " << result[src][dst] << "\n";
}


void Graph::prims(int startNode)
{
    int key[MAX + 1];
    int parent[MAX + 1];
    bool mstSet[MAX + 1];

    for(int i = 1; i <= MAX; i++)
    {
        key[i] = INFINITY_VAL;
        parent[i] = -1;
        mstSet[i] = false;
    }

    key[startNode] = 0;

    for(int count = 0; count < n; count++)
    {
        int u = -1;
        int minKey = INFINITY_VAL;

        for(int v = 1; v <= MAX; v++)
        {
            if(!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        if(u == -1)
            break;

        mstSet[u] = true;

        GraphNode *node = findNode(u);
        if(node == NULL)
            continue;

        EdgeNode *p = node->adj;

        while(p != NULL)
        {
            int v = p->dest;

            if(!mstSet[v] && p->weight < key[v])
            {
                key[v] = p->weight;
                parent[v] = u;
            }

            p = p->link;
        }
    }

    cout << "\nMinimum Spanning Tree (Prim's):\n";

    int totalCost = 0;

    for(int i = 1; i <= MAX; i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i] << " -> " << i
                 << "  Weight = " << key[i] << endl;

            totalCost += key[i];
        }
    }

    cout << "Total Cost = " << totalCost << endl;
}

int findSet(int parent[], int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int parent[], int x, int y)
{
    int px = findSet(parent, x);
    int py = findSet(parent, y);

    parent[px] = py;
}

void Graph::kruskal()
{
    KEdge edges[100];
    int edgeCount = 0;

    GraphNode *u = start;

    while(u != NULL)
    {
        EdgeNode *e = u->adj;

        while(e != NULL)
        {
            if(u->name < e->dest) // avoid duplicates
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

    // Bubble Sort edges by weight
    for(int i = 0; i < edgeCount - 1; i++)
    {
        for(int j = 0; j < edgeCount - i - 1; j++)
        {
            if(edges[j].weight > edges[j + 1].weight)
            {
                KEdge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX + 1];

    for(int i = 0; i <= MAX; i++)
        parent[i] = i;

    cout << "\nMinimum Spanning Tree (Kruskal):\n";

    int totalCost = 0;
    int selectedEdges = 0;

    for(int i = 0; i < edgeCount && selectedEdges < n - 1; i++)
    {
        int x = findSet(parent, edges[i].src);
        int y = findSet(parent, edges[i].dest);

        if(x != y)
        {
            cout << edges[i].src << " -> "
                 << edges[i].dest
                 << " Weight = "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, x, y);

            selectedEdges++;
        }
    }

    cout << "Total Cost = " << totalCost << endl;
}