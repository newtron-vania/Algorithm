#include <bits/stdc++.h>

using namespace std;

const int MAX_INT = 1'000'000;

int binary_search(const vector<int>& answer, int val) 
{
    int start = 0;
    int end = answer.size() - 1;

    while (start <= end) 
    {
        int mid = (start + end) / 2;
        if (answer[mid] >= val) 
        {
            end = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }
    }
    return start;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[MAX_INT];
    
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    vector<int> answer;
    answer.push_back(-1000000001);

    pair<int, int> arr_info[MAX_INT];

    for (int i = 0; i < n; i++) 
    {
        if (answer.back() < arr[i]) 
        {
            answer.push_back(arr[i]);
            arr_info[i] = {arr[i], static_cast<int>(answer.size()) - 1};
        } 
        else 
        {
            int result = binary_search(answer, arr[i]);
            answer[result] = arr[i];
            arr_info[i] = {arr[i], result};
        }
    }

    cout << answer.size() - 1 << '\n';

    int cnt = answer.size() - 1;
    vector<int> lis(cnt);

    for (int i = n - 1; i >= 0; i--) 
    {
        if (arr_info[i].second == cnt) 
        {
            lis[cnt - 1] = arr_info[i].first;
            cnt--;
            if (cnt == 0) break;
        }
    }

    for (int i = 0; i < lis.size(); i++) 
    {
        cout << lis[i] << (i != lis.size() - 1 ? ' ' : '\n');
    }

    return 0;
}
