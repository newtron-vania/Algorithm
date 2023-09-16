#include <iostream>
#include <vector>

using namespace std;

void binary_search(int val, vector<int> &answer) {
    int start = 0;
    int end = answer.size() - 1;
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (answer[mid] >= val) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    answer[start] = val;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n + 1, 0);
    vector<int> answer;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    answer.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        int val = arr[i];
        if (answer.back() > val) {
            binary_search(val, answer);
        } else if (answer.back() < val) {
            answer.push_back(val);
        }
    }

    cout << answer.size() << endl;

    return 0;
}