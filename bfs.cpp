#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int graph[10][10] = {0};

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}