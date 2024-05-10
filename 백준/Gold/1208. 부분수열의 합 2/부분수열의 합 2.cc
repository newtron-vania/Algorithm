#include <bits/stdc++.h>

using namespace std;
 
int arr[40];
int N, S;
long long cnt;
vector<int> a, b;
 
void makeA(int idx, int sum) 
{
    sum += arr[idx];
    if (idx >= N / 2) return;
    // 만약 S를 만들 수 있다면 cnt++을 해준다
    if (sum == S) cnt++;
 
    a.push_back(sum);
    makeA(idx + 1, sum - arr[idx]);
    makeA(idx + 1, sum);
}
 
void makeB(int idx, int sum) 
{
    sum += arr[idx];
    if (idx >= N) return;
    // 만약 S를 만들 수 있다면 cnt++을 해준다
    if (sum == S) cnt++;
    
    b.push_back(sum);
    makeB(idx + 1, sum - arr[idx]);
    makeB(idx + 1, sum);
}
 
int main() 
{
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
 
    // 각각 만들 수 있는 모든 부분집합의 합
    makeA(0, 0);
    makeB(N / 2, 0);
 
    // 이분탐색을 이용하기 위해서 미리 정렬
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    // 찾고자하는 값의 갯수 이분탐색
    for (int i = 0; i < a.size(); i++) 
    {
        int temp = S - a[i];
        int lower = lower_bound(b.begin(), b.end(), temp) - b.begin();
        int upper = upper_bound(b.begin(), b.end(), temp) - b.begin();
        cnt += upper - lower;
    }
 
    cout << cnt;
 
    return 0;
}
