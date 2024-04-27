#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& parent, int node) 
{
    if (parent[node] != node) 
    {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void unionSet(vector<int>& parent, int a, int b) 
{
    a = find(parent, a);
    b = find(parent, b);

    if (a < b) 
    {
        parent[b] = a;
    } else 
    {
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            int connected;
            cin >> connected;
            if (connected == 1) 
            {
                unionSet(parent, i + 1, j + 1);
            }
        }
    }

    vector<int> plan(m);
    for (int i = 0; i < m; i++) 
    {
        cin >> plan[i];
    }

    bool sameSet = true;
    int root = find(parent, plan[0]);
    for (int i = 1; i < m; i++) 
    {
        if (find(parent, plan[i]) != root) 
        {
            sameSet = false;
            break;
        }
    }

    if (sameSet) 
    {
        cout << "YES" << endl;
    } else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
