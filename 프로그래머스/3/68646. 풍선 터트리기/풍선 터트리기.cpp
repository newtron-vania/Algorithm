#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> a) 
{
    int check; 
    vector<int> del;    
    del.resize(a.size());
    fill(del.begin(), del.end(), 1); 
    
    int answer = 0;
    
    //왼쪽 확인
    for(int i=0; i<a.size(); i++)
    {
        if (i==0)
        {
            check = a[i];
            del[i] = 0;
        }
        else
        {
            
            //지금 풍선이 왼쪽 값들 중 최솟값보다 작음
            if(check > a[i])
            {
                check= a[i];   //최솟값 업데이트
                del[i] = 0;         //왼쪽에 자신보다 큰 값이 있으므로 삭제 가능
            }
        }
    }
    
    //오른쪽 확인
    for(int i=a.size()-1; i>=0; i--)
    {
        if (i== a.size()-1)
        {
            check = a[i];
            del[i] = 0;
        }
        else
        {
            if(check > a[i])
            {
                check = a[i];       //최솟값 업데이트
                del[i] = 0;
            }
        }
    }
    
    //삭제가능한 풍선수 count
    for(int i=0; i<del.size(); i++)
    {
        if(del[i] == 0)
        {
            answer++;
        }
    }
    
    return answer;
}