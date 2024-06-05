#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string arr;
	getline(cin, arr);
	for(int i=0;i<arr.length(); i++)
    {
		if (arr[i] >= 'a' && arr[i] <= 'z')
        {
			//소문자라면,
			arr[i] += 13;
			if (arr[i] > 'z' || arr[i]<'a')
            {
				arr[i] -= 26;
			}
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z') 
        {
			arr[i] += 13;
			if (arr[i] > 'Z') {
				arr[i] -= 26;
			}
		}

		cout << arr[i];
	}
	
}