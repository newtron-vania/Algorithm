#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> boxCount;
    vector<bool> visited(cards.size(), false);
    
    for(int i = 0; i < cards.size(); i++)
    {
        int cnt = 0;
        int idx = i;
        
        while(true)
        {
            if(visited[idx])
            {
                if(cnt > 0)
                {
                    boxCount.push_back(cnt);
                }
                break;
            }
            
            cnt++;
            visited[idx] = true;
            idx = cards[idx] - 1;
        }
    }
    if(boxCount.size() <= 1)
    {
        return 0;
    }
    sort(boxCount.rbegin(), boxCount.rend());
    answer = boxCount[0] * boxCount[1];
    return answer;
}