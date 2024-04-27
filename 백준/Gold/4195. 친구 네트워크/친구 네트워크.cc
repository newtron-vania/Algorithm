#include <bits/stdc++.h>

using namespace std;

string find(unordered_map<string, string>& parent, const string& node)
{
    if (parent[node] != node)
    {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void unionSet(unordered_map<string, string>& parent, unordered_map<string, int>& number, const string& a, const string& b) 
{
    string rootA = find(parent, a);
    string rootB = find(parent, b);

    if (rootA != rootB) 
    {
        if (number[rootA] < number[rootB])
        {
            parent[rootA] = rootB;
            number[rootB] += number[rootA];
        } else {
            parent[rootB] = rootA;
            number[rootA] += number[rootB];
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    while (T--)
    {
        int n;
        cin >> n;
        
        unordered_map<string, string> parent;
        unordered_map<string, int> number;
        
        while (n--) 
        {
            string a, b;
            cin >> a >> b;
            
            if (parent.find(a) == parent.end())
            {
                parent[a] = a;
                number[a] = 1;
            }
            if (parent.find(b) == parent.end()) 
            {
                parent[b] = b;
                number[b] = 1;
            }

            unionSet(parent, number, a, b);

            cout << number[find(parent, a)] << '\n';
        }
    }

    return 0;
}
