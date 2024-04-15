#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();
vector<pair<int, int>> segment_tree;
vector<int> arr;

// 세그먼트 트리 초기화 함수
pair<int, int> init(int start, int end, int node) 
{
    if (start == end) 
    {
        segment_tree[node] = {arr[start], arr[start]};
        return segment_tree[node];
    }
    
    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, node * 2);
    pair<int, int> right = init(mid + 1, end, node * 2 + 1);
    segment_tree[node] = {min(left.first, right.first), max(left.second, right.second)};
    return segment_tree[node];
}

// 주어진 범위 [left, right]에서 최소값과 최대값을 찾는 함수
pair<int, int> query(int start, int end, int node, int left, int right) 
{
    if (left > end || right < start) 
    {
        return {INF, 0};
    }
    if (start >= left && end <= right) 
    {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> left_result = query(start, mid, node * 2, left, right);
    pair<int, int> right_result = query(mid + 1, end, node * 2 + 1, left, right);
    return {min(left_result.first, right_result.first), max(left_result.second, right_result.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    arr.resize(N);
    segment_tree.resize(N * 4);

    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    init(0, N - 1, 1);

    for (int i = 0; i < M; i++) 
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = query(0, N - 1, 1, a - 1, b - 1);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}
