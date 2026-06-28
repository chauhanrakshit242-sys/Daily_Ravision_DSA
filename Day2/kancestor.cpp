#include <bits/stdc++.h>
using namespace std;

int LOG;
vector<vector<int>> adj;
vector<vector<int>> ancestor;

void dfs(int node, int parent)
{
    ancestor[node][0] = parent;

    for(int j = 1; j < LOG; j++)
    {
        if(ancestor[node][j - 1] == -1)
            break;

        ancestor[node][j] =
            ancestor[ancestor[node][j - 1]][j - 1];
    }

    for(int child : adj[node])
    {
        if(child != parent)   // FIX
            dfs(child, node);
    }
}

int kthAncestor(int node, int k)
{
    for(int j = 0; j < LOG; j++)
    {
        if(node == -1)
            return -1;

        if(k & (1 << j))
        {
            node = ancestor[node][j];
        }
    }
    return node;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    LOG = log2(vertex) + 1;

    adj.resize(vertex);
    ancestor.assign(vertex, vector<int>(LOG, -1));

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // FIX
    }

    int root = 0;
    dfs(root, -1);

    int node, k;
    cin >> node >> k;

    cout << kthAncestor(node, k) << endl;

    return 0;
}