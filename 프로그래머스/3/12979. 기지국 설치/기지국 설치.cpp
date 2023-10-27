#include <iostream>
#include <vector>
using namespace std;

int AddStations(int start, int end, int width)
{
    int distance = end - start;
    if(distance <= 0) return 0;
    
    return (distance / width) + (distance%width ? 1 : 0);
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int width = (2 * w) + 1;
    
    int start = 1;
    for(int station : stations)
    {
        int end = station - w;
        int count = AddStations(start, end, width);
        
        answer += count;
        
        start = station + w + 1;
        
    }
    //마지막 위치까지 계산
    answer += AddStations(start, n+1, width);
    

    return answer;
}