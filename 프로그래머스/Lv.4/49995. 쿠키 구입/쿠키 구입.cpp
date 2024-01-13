#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookies) {
    int answer = 0;

    for(int i = 0; i < cookies.size(); i++)
    {
        int left = i;
        int right = i+1;
        int ls = cookies[left];
        int rs = cookies[right];
        
        while(true)
        {
            if(ls == rs && answer < ls)
            {
                answer = ls;
            }
            else if(ls <= rs && left > 0)
            {
                ls += cookies[--left];
            }
            else if(ls >= rs && right < cookies.size() - 1)
            {
                rs += cookies[++right];
            }
            else{
                break;
            }
        }
    }

    
    return answer;
}