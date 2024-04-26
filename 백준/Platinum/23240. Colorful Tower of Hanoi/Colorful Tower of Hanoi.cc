#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	char color[51] = "";
	int arr[51] = { 0, };
	for (int i = 0; i < count; i++) {
		getchar();
		cin >> color[i];
		cin >> arr[i];
	}
	long long int sum = 0;
	int bonus = 0; //해당 블록의 움직임이 홀수인지 짝수인지 구별 할 거
	long long int dx = 1; //2의 승수로 움직일 거임.
	bool is_parity = false;
	for (int i = count - 1; i >= 0; i--) {
		//B는 짝수 번 움직여야 순차적으로 쌓임
		if (is_parity) {
			dx += 1;
			is_parity = false;
		}
		if (arr[i] == 1) {
			sum += dx * arr[i];
		}
		else if (color[i] == 'B' && !(dx & 1)) {
			//블루가 짝수 번 움직이면, 그냥 쌓으면 됨.
			sum += dx * arr[i];
		}
		else if (color[i] == 'B' && dx & 1) { 
			//블루가 홀수번 움직이면 움직임의 횟수를 한 번 추가 해 줘야 함.
			//그리고 젤 위 탑이면, -1 해줘야 함.
			sum += (dx+1)* arr[i];
			is_parity = true;
			if (i == 0) sum--;
		}
		else if (color[i] == 'R' && dx & 1) {
			//레드가 홀 수번 움직 이면 역순으로 쌓이므로 그냥 쌓음.
			sum += dx * arr[i];
		}
		else if (color[i] == 'R' && !(dx & 1)) {
			//레드가 짝수번 움직이면, 한 번 더 움직여 줘야 함.
			//그리고 젤 위 탑이면, -1 해줌.
			is_parity = true;
			sum += (dx+1) * arr[i];
			if (i == 0) sum--;
		}
		else {
			//그린은 상관없이 그냥 계산 해 주면 됨.
			sum += dx * arr[i];
		}
		//그리고 기본적으로 탑의 이동 수는
		//2의 승수대로 움직인다.
		dx = dx << 1;
	}

	cout << sum << "\n";
}