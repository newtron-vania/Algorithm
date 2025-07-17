#include <bits/stdc++.h>
using namespace std;

int p[1000001];
int mmap[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int find(int x) 
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b) p[b] = a;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'U') mmap[i][j] = 0;
            else if (s[j] == 'D') mmap[i][j] = 1;
            else if (s[j] == 'L') mmap[i][j] = 2;
            else if (s[j] == 'R') mmap[i][j] = 3;
        }
    }

    for (int i = 0; i < n * m; i++) p[i] = i;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            int dir = mmap[i][j];
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) 
            {
                int cur = i * m + j;
                int next = ni * m + nj;
                merge(cur, next);
            }
        }
    }

    set<int> roots;
    for (int i = 0; i < n * m; i++) 
    {
        roots.insert(find(i));
    }

    cout << roots.size() << '\n';
    return 0;
}
