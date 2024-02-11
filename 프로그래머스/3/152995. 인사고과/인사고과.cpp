#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> point;

int cura,pivot,N;
vector<point> arr;
vector<int> vec;

int cmp (point a, point b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first > b.first;
    }
}

int solution(vector<vector<int>> scores) {
    int tsum,ta,tb;
    int i = 0;
    N = scores.size();
    for(int i = 0 ; i < N;i++){
        arr.push_back(make_pair(scores[i][0],scores[i][1]));
    }
    ta = arr[0].first; tb = arr[0].second; 
    tsum = arr[0].first + arr[0].second;
    
    sort(arr.begin(),arr.end(),cmp);
    cura = arr[0].first;
    
    while(i < N){
        if(cura == arr[i].first){
            pivot = arr[i].second;
            vec.push_back(arr[i].first + arr[i].second);
            i++;
        }
        else{
            while(i < N){
                if(pivot > arr[i].second){
                    if(ta == arr[i].first && tb == arr[i].second)
                        return -1;
                    i++;
                }
                else break;
            }
            cura = arr[i].first;
            pivot = arr[i].second;
        }
    }
    sort(vec.begin(),vec.end(),greater<int>());
    for(int i = 0 ; i< vec.size() ;i++){
        if(vec[i] == tsum){
            return i + 1;
        }
    }
}