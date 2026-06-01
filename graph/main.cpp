#include "Graph.h"

int main() {
    Graph graph;
    int choice;

    while (true) {
        cout << "\n";
        cout << "1.  insert node\n";
        cout << "2.  insert edge\n";
        cout << "3.  delete node\n";
        cout << "4.  delete edge\n";
        cout << "5.  DFS\n";
        cout << "6.  BFS\n";
        cout << "7.  Dijkstra\n";
        cout << "8.  complete\n";
        cout << "9.  connected\n";
        cout << "10. path of given length from one node to another\n";
        cout << "11. display\n";
        cout << "0.  Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 0:
                cout << "Exiting...\n";
                return 0;

            case 1: {
                int nodeName;
                cout << "Enter node number to insert: ";
                cin >> nodeName;
                graph.insert_node(nodeName);
                break;
            }

            case 2: {
                int u, v, w;
                cout << "Enter source node: ";
                cin >> u;
                cout << "Enter destination node: ";
                cin >> v;
                cout << "Enter weight (enter 1 for unweighted): ";
                cin >> w;
                graph.insert_edge(u, v, w);
                break;
            }

            case 3: {
                int nodeName;
                cout << "Enter node number to delete: ";
                cin >> nodeName;
                graph.delete_node(nodeName);
                break;
            }

            case 4: {
                int u, v;
                cout << "Enter source node of edge to delete: ";
                cin >> u;
                cout << "Enter destination node of edge to delete: ";
                cin >> v;
                graph.delete_edge(u, v);
                break;
            }

            case 5: {
                int startNode;
                cout << "Enter starting node for DFS: ";
                cin >> startNode;
                // iterative stack-based DFS (mirrors PDF dfs function)
                graph.dfs(startNode);
                // also available: graph.dfs_recursive(startNode);
                break;
            }

            case 6: {
                int startNode;
                cout << "Enter starting node for BFS: ";
                cin >> startNode;
                graph.bfs(startNode);
                break;
            }

            case 7: {
                int src, dst;
                cout << "Enter source node (0 to quit): ";
                cin >> src;
                if (src == 0) break;
                cout << "Enter destination node (0 to quit): ";
                cin >> dst;
                if (dst == 0) break;
                graph.dijkstra(src, dst);
                break;
            }

            case 8: {
                if (graph.isComplete())
                    cout << "The graph IS a complete graph.\n";
                else
                    cout << "The graph is NOT a complete graph.\n";
                break;
            }

            case 9: {
                if (graph.isConnected())
                    cout << "The graph IS connected.\n";
                else
                    cout << "The graph is NOT connected.\n";
                break;
            }

            case 10: {
                int src, dst, length;
                cout << "Enter source node: ";
                cin >> src;
                cout << "Enter destination node: ";
                cin >> dst;
                cout << "Enter path length: ";
                cin >> length;
                graph.pathOfLength(src, dst, length);
                break;
            }

            case 11: {
                cout << "Adjacency List:\n";
                graph.display();
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
