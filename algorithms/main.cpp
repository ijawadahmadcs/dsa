#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph g;
	int choice;

	while(true)
	{
		cout << "\n--- Graph Menu ---\n";
		cout << "1. Add Vertex\n";
		cout << "2. Add Edge\n";
		cout << "3. Display Graph\n";
		cout << "4. Prim's MST\n";
		cout << "5. Kruskal MST\n";
		cout << "6. Exit\n";
		cout << "Enter choice: ";
		if(!(cin >> choice))
		{
			cin.clear();
			cout << "Invalid input. Try again.\n";
			continue;
		}

		if(choice == 1)
		{
			int v;
			cout << "Enter vertex id (int): ";
			cin >> v;
			g.addVertex(v);
			cout << "Vertex added.\n";
		}
		else if(choice == 2)
		{
			int u, v, w;
			cout << "Enter source vertex: "; cin >> u;
			cout << "Enter destination vertex: "; cin >> v;
			cout << "Enter weight: "; cin >> w;
			g.addEdge(u, v, w);
			cout << "Edge added.\n";
		}
		else if(choice == 3)
		{
			cout << "\nGraph:\n";
			g.display();
		}
		else if(choice == 4)
		{
			int sv;
			cout << "Enter start vertex for Prim's algorithm: ";
			cin >> sv;
			g.prims(sv);
		}
		else if(choice == 5)
		{
			g.kruskal();
		}
		else if(choice == 6)
		{
			cout << "Exiting.\n";
			break;
		}
		else
		{
			cout << "Invalid choice.\n";
		}
	}

	return 0;
}