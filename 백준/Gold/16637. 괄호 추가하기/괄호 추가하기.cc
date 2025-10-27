#include <bits/stdc++.h>

using namespace std;

int N;
char expr[20];  // 수식 문자열
vector<long long> nums;
vector<char> ops;
long long answer = LLONG_MIN;

long long applyOp(char op, long long a, long long b)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

void dfs(int idx, long long current)
{
    // idx는 ops 벡터의 인덱스 → 현재 계산된 값이 current
    if (idx >= (int)ops.size())
    {
        if (current > answer) answer = current;
        return;
    }

    // 괄호 없이 다음 연산 수행
    long long nextVal = applyOp(ops[idx], current, nums[idx + 1]);
    dfs(idx + 1, nextVal);

    // 괄호를 사용해서 ops[idx+1] 연산 먼저 실행할 수 있다면
    if (idx + 1 < (int)ops.size())
    {
        long long bracketVal = applyOp(ops[idx + 1], nums[idx + 1], nums[idx + 2]);
        long long newCurrent = applyOp(ops[idx], current, bracketVal);
        dfs(idx + 2, newCurrent);
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%s", expr);

    // expr 길이 N, 숫자와 연산자가 번갈아 나옴
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            nums.push_back(expr[i] - '0');
        }
        else
        {
            ops.push_back(expr[i]);
        }
    }

    // 초기값은 첫 숫자
    dfs(0, nums[0]);

    printf("%lld\n", answer);

    return 0;
}
