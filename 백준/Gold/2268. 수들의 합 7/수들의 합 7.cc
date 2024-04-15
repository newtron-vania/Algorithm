#include <iostream>
#include <vector>

using namespace std;

class SegmentTree 
{
private:
    vector<long long> segment_tree;
    vector<long long> num;
    int n;

    long long init(int start, int end, int node) 
    {
        if (start == end) 
        {
            return segment_tree[node] = num[start];
        }
        int mid = (start + end) / 2;
        return segment_tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }

    long long sum(int start, int end, int node, int left, int right) 
    {
        if (left > end || right < start) 
        {
            return 0;
        }
        if (left <= start && end <= right) 
        {
            return segment_tree[node];
        }
        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    }

    void update(int start, int end, int node, int index, long long diff) 
    {
        if (index < start || index > end) return;
        segment_tree[node] += diff;
        if (start != end) 
        {
            int mid = (start + end) / 2;
            update(start, mid, node * 2, index, diff);
            update(mid + 1, end, node * 2 + 1, index, diff);
        }
    }

public:
    SegmentTree(const vector<long long>& v) 
    {
        n = v.size();
        num = v;
        segment_tree.resize(n * 4);
        init(0, n - 1, 1);
    }

    long long sum(int left, int right) 
    {
        return sum(0, n - 1, 1, left, right);
    }

    void update(int index, long long newValue) 
    {
        long long diff = newValue - num[index];
        num[index] = newValue;
        update(0, n - 1, 1, index, diff);
    }
};

void Swap(int& a, int& b)
{
    if(a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<long long> num(N, 0);

    SegmentTree segTree(num);

    for (int i = 0; i < M; ++i) 
    {
        int k, a, b;
        cin >> k >> a >> b;
        
        if(k == 0)
        {
            Swap(a, b);
            cout << segTree.sum(a - 1, b - 1) << "\n";
        }
        else if(k == 1)
        {
            segTree.update(a - 1, b);
        }
    }
    return 0;
}