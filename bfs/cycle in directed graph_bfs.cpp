#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);

}

bool isCyclicConntected(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{

    vector<int> parent(V, -1);


    queue<int> q;


    visited[s] = true;
    q.push(s);

    while (!q.empty()) {


        int u = q.front();
        q.pop();


        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;

            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}

bool isCyclicDisconntected(vector<int> adj[], int V)
{

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i,
                                         V, visited))
            return true;
    return false;
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 4);
    vector<bool> visited(V, false);
    if (isCyclicConntected(adj, 0,V, visited))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

