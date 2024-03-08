#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) 
{
    sort(dist.rbegin(), dist.rend());
    
    deque<vector<int>> queue;
    set<vector<int>> visited;
    
    queue.push_back(weak);
    visited.insert(weak);

    for (int i = 1; i <= dist.size(); i++) 
    {
        int d = dist[i - 1];
        int queueSize = queue.size();
        for (int j = 0; j < queueSize; j++) 
        {
            vector<int> current = queue.front();
            queue.pop_front();
            for (int q : current) 
            {
                int l = q;
                int r = (q + d) % n;
                vector<int> tmp;
                if (l < r)
                {
                    copy_if(current.begin(), current.end(), back_inserter(tmp), [&](int x) {
                        return x < l || x > r;
                    });
                } else 
                {
                    copy_if(current.begin(), current.end(), back_inserter(tmp), [&](int x) {
                        return x < l && x > r;
                    });
                }

                if (tmp.empty()) 
                {
                    return i;
                } 
                else if (visited.find(tmp) == visited.end()) 
                {
                    visited.insert(tmp);
                    queue.push_back(tmp);
                }
            }
        }
    }
    
    return -1;
}