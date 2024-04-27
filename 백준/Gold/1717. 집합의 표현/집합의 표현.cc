#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int node) 
{
    if (parent[node] != node) {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void unionSet(vector<int>& parent, int a, int b) 
{
    a = find(parent, a);
    b = find(parent, b);

    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) 
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) 
        {
            unionSet(parent, a, b);
        } else 
        {
            a = find(parent, a);
            b = find(parent, b);
            if (a == b) 
            {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
