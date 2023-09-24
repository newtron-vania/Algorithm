using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 1LL * count*(count+1) / 2 * price - money;
    

    return answer > 0 ? answer : 0;
}