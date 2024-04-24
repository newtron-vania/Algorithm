#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int C, k, ct[MAX + 1], answer[MAX];

struct Query
{ // 쿼리 구조체
    int A, B, idx;

    bool operator < (const Query &that) const
    {
        if (this->A / k == that.A / k)
            return this->B < that.B;
        return this->A / k < that.A / k;
    }
};

// 절반보다 많은 수의 모자 색이 있는지 확인
int check(int half)
{
    for (int i = 1; i <= C; i++)
        if (ct[i] > half) return i;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N >> C;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    int M; cin >> M;
    vector<Query> queries;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        queries.push_back({--A, --B, i});
    }

    // 제곱근 분할
    k = sqrt(N);
    sort(queries.begin(), queries.end());

    auto [L, R, idx] = queries[0];
    fill(ct + 1, ct + C + 1, 0);
    for (int i = L; i <= R; i++) ct[arr[i]]++;

    answer[idx] = check((R - L + 1) / 2);

    for (int i = 1; i < M; i++)
    {
        auto [A, B, idx] = queries[i];
        while (L < A) // 왼쪽 범위 좁히기
            ct[arr[L++]]--;
        while (A < L) // 왼쪽 범위 늘리기
            ct[arr[--L]]++;
        while (B < R) // 오른쪽 범위 좁히기
            ct[arr[R--]]--;
        while (R < B) // 오른쪽 범위 늘리기
            ct[arr[++R]]++;
        answer[idx] = check((R - L + 1) / 2);
    }

    for (int i = 0; i < M; i++)
    {
        if (answer[i]) cout << "yes " << answer[i] << '\n';
        else cout << "no" << '\n';
    }
}