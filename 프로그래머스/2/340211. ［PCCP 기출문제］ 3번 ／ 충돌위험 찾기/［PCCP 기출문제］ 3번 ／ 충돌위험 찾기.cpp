#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int answer = 0;
    
    vector<vector<pair<int, int>>> robotRoutes(101, vector<pair<int, int>>());
    
    pair<int, int> p;
    int num = 0, maxLength = 0;
    
    for (int i = 0; i < routes.size(); i++) 
    {
        for (int j = 1; j < routes[i].size(); j++) 
        {
            int start = routes[i][j - 1];
            int end = routes[i][j];
            p = make_pair(points[start - 1][0], points[start - 1][1]);

            while (points[end - 1][0] != p.first) 
            {
                robotRoutes[num].push_back(p);
                points[end - 1][0] > p.first ? p.first++ : p.first--;
            }
            while (points[end - 1][1] != p.second) 
            {
                robotRoutes[num].push_back(p);
                points[end - 1][1] > p.second ? p.second++ : p.second--;
            }
        }
        robotRoutes[num].push_back(p);
        
        if (maxLength < robotRoutes[num].size())
            maxLength = robotRoutes[num].size();
        
        num++;
    }
    
    int routeSize = routes.size();
    pair<int, int> currentPoint;
    
    for (int index = 0; index < maxLength; index++) 
    {
        for (int i = 0; i < routeSize; i++) 
        {
            if (robotRoutes[i].size() <= index)
                continue;
            
            if (robotRoutes[i][index].first == -1)
                continue;
            
            currentPoint = robotRoutes[i][index];
            for (int j = i + 1; j < routeSize; j++) 
            {
                if (robotRoutes[j].size() <= index)
                    continue;
            
                if (robotRoutes[j][index].first == -1)
                    continue;
                
                if (currentPoint == robotRoutes[j][index]) 
                {
                    if (robotRoutes[i][index].first != -1)
                        robotRoutes[i][index] = make_pair(-1, -1);
                    
                    robotRoutes[j][index] = make_pair(-1, -1);
                }
            }
            if (robotRoutes[i][index].first == -1)
            {
                answer++;
            }
        }
    }
    
    return answer;
}
