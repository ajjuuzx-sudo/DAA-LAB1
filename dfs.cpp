#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int graph[10][10] = {0};

    cout << "Enter the edges (u v):\n";

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
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (visited[current] == false)
        {
            cout << current << " ";
            visited[current] = true;

            for (int i = n - 1; i >= 0; i--)
            {
                if (graph[current][i] == 1 && visited[i] == false)
                {
                    s.push(i);
                }
            }
        }
    }

    return 0;
}