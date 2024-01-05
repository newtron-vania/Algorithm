#include <iostream>

using namespace std;

int lis[1001];

int binarysearch(int left, int right, int target) {
	int mid;

    // lis 배열에 들어갈 target=arr[i]의 위치를 이분탐색으로 찾기

	while (left < right) {
		mid = (left + right) / 2; // 중간값 설정

		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int count;

    int arr[1001];
    cin >> count;
    for(int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    lis[0] = arr[0];

    int j = 0;
    int i = 1;
    while(i < count)
    {
        if(lis[j] < arr[i])
        {
            lis[++j] = arr[i];
        }
        else
        {
            int idx = binarysearch(0, j, arr[i]);
            lis[idx] = arr[i];
        }
        i += 1;
    }

    cout << j + 1;

    return 0;
}