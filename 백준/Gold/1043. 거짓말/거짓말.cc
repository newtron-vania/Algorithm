#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    // 진실을 아는 사람들 집합
    int knowCount;
    cin >> knowCount;
    set<int> knowList;
    for (int i = 0; i < knowCount; ++i) 
    {
        int person;
        cin >> person;
        knowList.insert(person);
    }

    // 파티별 구성원 집합
    vector<set<int>> parties(m);
    for (int i = 0; i < m; ++i) 
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) 
        {
            int person;
            cin >> person;
            parties[i].insert(person);
        }
    }

    // 진실을 아는 사람들 집합 업데이트
    for (int i = 0; i < m; ++i) 
    {
        for (const auto& party : parties) 
        {
            set<int> intersection;
            set_intersection(knowList.begin(), knowList.end(), party.begin(), party.end(), inserter(intersection, intersection.begin()));

            if (!intersection.empty()) 
            {
                knowList.insert(party.begin(), party.end());
            }
        }
    }

    // 과장된 이야기 할 수 있는 파티 개수 계산
    int cnt = 0;
    for (const auto& party : parties) 
    {
        set<int> intersection;
        set_intersection(knowList.begin(), knowList.end(), party.begin(), party.end(), inserter(intersection, intersection.begin()));

        if (intersection.empty()) 
        {
            ++cnt;
        }
    }

    cout << cnt << endl;
    return 0;
}
