#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
int student[401][4];
int classroom[MAX_N][MAX_N];
int N;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool CompareTuple(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b)
{
    int matchA = get<2>(a), emptyA = get<3>(a), xA = get<0>(a), yA = get<1>(a);
    int matchB = get<2>(b), emptyB = get<3>(b), xB = get<0>(b), yB = get<1>(b);

    if (matchA == matchB)
    {
        if (emptyA == emptyB)
        {
            if (xA == xB) return yA < yB;
            return xA < xB;
        }
        return emptyA > emptyB;
    }
    return matchA > matchB;
}

tuple<int, int, int, int> getSeatInfo(int key, int x, int y)
{
    int empty = 0;
    int match = 0;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

        if (classroom[nx][ny] == 0)
        {
            empty++;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (student[key][i] == classroom[nx][ny])
                {
                    match++;
                }
            }
        }
    }

    return {x, y, match, empty};
}

void AssignSeat(int key)
{
    vector<tuple<int, int, int, int>> candidates;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (classroom[i][j] == 0)
            {
                candidates.push_back(getSeatInfo(key, i, j));
            }
        }
    }

    sort(candidates.begin(), candidates.end(), CompareTuple);

    int x = get<0>(candidates[0]);
    int y = get<1>(candidates[0]);
    classroom[x][y] = key;
}

int calculateScore()
{
    int total = 0;

    for (int k = 1; k <= N * N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            bool found = false;
            for (int j = 1; j <= N; j++)
            {
                if (classroom[i][j] == k)
                {
                    int match = get<2>(getSeatInfo(k, i, j));
                    if (match > 0)
                    {
                        total += pow(10, match - 1);
                    }
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    return total;
}

int main()
{
    cin >> N;
    vector<int> seatOrder;

    for (int i = 1; i <= N * N; i++)
    {
        int key;
        cin >> key;
        seatOrder.push_back(key);
        for (int j = 0; j < 4; j++)
        {
            cin >> student[key][j];
        }
    }

    for (int i = 0; i < seatOrder.size(); i++)
    {
        AssignSeat(seatOrder[i]);
    }

    cout << calculateScore() << endl;
    return 0;
}
