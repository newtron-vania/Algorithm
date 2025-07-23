#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;

vector<int> primes;
vector<bool> is_prime(MAX + 1, true);

// 에라토스테네스의 체
void generate_primes()
{
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    generate_primes();

    int T;
    scanf("%d", &T);

    for (int scenario = 1; scenario <= T; ++scenario)
    {
        int m;
        scanf("%d", &m);
        vector<int> nums(m);

        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &nums[i]);
        }

        vector<int> results(m, 0);
        vector<int> num_indexs(m, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int k = 0; k < nums[i]; k++)
            {
                results[i] += primes[k];
            }
            num_indexs[i] = nums[i];
        }

        int result = -1;
        while (true)
        {
            int max_val = *max_element(results.begin(), results.end());
            for (int i = 0; i < m; ++i)
            {
                while (results[i] < max_val || (!is_prime[results[i]] && num_indexs[i] < primes.size()))
                {
                    results[i] += primes[num_indexs[i]] - primes[num_indexs[i] - nums[i]];
                    num_indexs[i]++;
                }
                max_val = max(max_val, results[i]);
            }

            bool check = true;
            for (int k = 0; k < m - 1; k++)
            {
                if (results[k] != results[k + 1])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                result = max_val;
                break;
            }
        }
        printf("Scenario %d:\n%d\n\n", scenario, result);
    }

    return 0;
}
